#include "script_component.hpp"

// not used
params ["_MODULE_logic", "_MODULE_units", "_MODULE_activated"];

//put classnames of objects you want to disable simulation on in here, and it will do it for all of that object found
_objects_to_mod = ["Fridge_01_open_F", "Land_Rack_F", "Land_ShelvesWooden_F"];

private ["_arrayGroups","_triggersArray","_allItems","_simItems","_logicItems","_arrayVehicles","_mission","_br","_object","_side","_array","_pos","_count",
          "_seed","_newString","_finalString","_checkedGroups","_isKindofUnit","_allobjetives","_class"];
 
_br = toString [0x0D, 0x0A]; //need this in order for the rest to work right

_checkedGroups		= []; 
_arrayGroups 		= [];
_arrayVehicles 		= [];
_allobjetives 		= [];
_seed				= str (random 100000); //random seed to generate
hint format ["Starting to save.. \n\n Seed: %1", _seed];

_allItems		= allMissionObjects "All";
_simItems		= allMissionObjects "WeaponHolderSimulated";
_triggersArray 	= allMissionObjects "EmptyDetector"; //grab triggers
_logicItems		= allMissionObjects "logic";

{
	if (typeOf _x in ["ModuleObjective_F","ModuleObjectiveGetIn_F","ModuleObjectiveMove_F","ModuleObjectiveNeutralize_F","ModuleObjectiveProtect_F"]) then {
		_allobjetives set [count _allobjetives, _x]; //get objective modules placed
		hint "Objectives are placed.";
	};
} foreach _logicItems;

_allItems 		= _allItems - _simItems;
_allItems 		= _allItems - _logicItems;

//Sort everything out
{
	if (((count units group _x) <=1)) then {
		_isKindofUnit = if ((_x isKindOf "CAManBase") || (_x isKindOf "car") || (_x isKindOf "tank") || (_x isKindOf "air") || (_x isKindOf "StaticWeapon") || (_x isKindOf "ship")) then {true} else {false};
		switch (true) do {
			case (_isKindofUnit):  {
				if ((((count units group _x) ==1) || (_x isKindOf "CAManBase")) && !(group _x in _checkedGroups)) then {
					_arrayGroups set [count _arrayGroups, [group _x,toupper (format ["%1",side _x])]]; //its a man
					hint format ["Sorting Units: %1",_x];
					_checkedGroups set [count _checkedGroups, group _x]; 
				} else {
					if !(_x isKindOf "CAManBase") then {_arrayVehicles set [count _arrayVehicles, [_x,"EMPTY"]]}; //its a vehicle
					hint format ["Sorting Vehicles: %1",_x];
				};
			};	
			// Animals
			case (_x isKindOf "animal") : {
				if !(typeOf _x in ["Snake_random_F","Rabbit_F"]) then {
					_arrayVehicles set [count _arrayVehicles, [_x,"AMBIENT LIFE"]];
					hint format ["Sorting Animals: %1",_x];
				};
			};
			// Others
			default {
				_arrayVehicles set [count _arrayVehicles, [_x,"EMPTY"]];
			};
		};
	} else {
		if (!(group _x in _checkedGroups) && (alive _x)) then {
			_arrayGroups set [count _arrayGroups, [group _x,toupper (format ["%1",side _x])]];
			_checkedGroups set [count _checkedGroups, group _x]; 
		};
	};
} foreach _allItems;

_mission = "version=53;" + _br
		+ "class Mission" + _br
		+ "{" + _br
		+ "    addOns[] = {}; " + _br
		+ "    addOnsAuto[] = {}; " + _br 
		+ "    randomSeed = " + _seed + ";" + _br;
		
		//set up params for weather time of day and resistance friendliness
		hint "setting up mission parameters.";
_mission = _mission 
+ 		  "    class Intel   " + _br 
+ 		  "    {             " + _br
+ format ["        resistanceWest=%1;", if (resistance getFriend west < 0.6) then {0} else {1}] + _br	
+ format ["        resistanceEast=%1;", if (resistance getFriend east < 0.6) then {0} else {1}] + _br
+ format ["        startWeather=%1;", overcast] + _br	
+ format ["        startFog=%1;", fog] + _br
+ format ["        startWind=%1;", windStr] + _br		
+ format ["        startWindDir=%1;", windDir] + _br	
+ format ["        startRain=%1;", rain] + _br	
+ format ["        startLightnings=%1;", lightnings] + _br
+ format ["        startWaves=%1;", waves] + _br	
+ format ["        startGust=%1;", gusts] + _br	
+ format ["        forecastWeather=%1;", overcast] + _br	
+ format ["        forecastWind=%1;", windStr] + _br
+ format ["        forecastWaves=%1;", waves] + _br	
+ 		  "        rainForced=1;" + _br
+ 		  "        lightningsForced=1;" + _br
+ 		  "        wavesForced=1;" + _br
+ 		  "        windForced=1;" + _br
+ format ["        year=%1;", Date select 0] + _br	
+ format ["        month=%1;", Date select 1] + _br
+ format ["        day=%1;", Date select 2] + _br	
+ format ["        hour=%1;", Date select 3] + _br	
+ format ["        minute=%1;", Date select 4] + _br
+ 		  "        startFogDecay=0.0049333;" + _br
+ 		  "        forecastFogDecay=0.0049333;" + _br	
+ 		  "    };           " + _br;



_mission = _mission		
		+ "    class Groups" + _br
		+ "    {" + _br
		+ format ["        items= %1;", (count _arrayGroups + count _allobjetives)] + _br;
 
//Groups
private ["_group","_groupCounter","_blackListVehicles","_refinedGroup","_attachedUnit","_attachedUnitInit","_newName","_init","_desc","_owners"]; 
_count = 0;
_countID = 0;

// set up objectives, which are basically useless since they can't be interacted with after creation, but might as well.
if (count _allobjetives > 0) then {
	{
		_object 	= _x;
		_class		= typeOf _x;
		_pos		= getpos _object;
		_mission = _mission 
				 + format ["        class Item%1", _count] + _br
				 +         "        {" + _br
				 +         "              side= ""LOGIC"";" + _br
				 +         "              class Vehicles" + _br
				 +         "              {" + _br
				 + 		   "                   items=1;" + _br
				 +         "                   class Item0" + _br
				 +         "                   {" + _br
				 + format ["                       position[]={%1,%3,%2};", _pos select 0, _pos select 1, _pos select 2] + _br
				 + format ["                       id=%1;", _countID] + _br
				 +         "                       side= ""LOGIC"";"  + _br
				 + format ["                       vehicle=""%1"";", typeof _object] + _br
				 +         "                       leader= 1;"  + _br
				 +         "                       lock= ""UNLOCKED"";"  + _br
				 +         "                       skill= 0.6;"  + _br;
				 
		if (!isnil {_object getvariable "text"}) then {
			_mission = _mission 
				+ format ["                       text=""%1"";", (_object getvariable "text")] + _br;
		};
		
		_attachedUnit = _object getvariable ["bis_fnc_curatorAttachObject_object",objnull];

		if (!isnull _attachedUnit) then {
			_attachedUnitInit = _attachedUnit getvariable ["vehicleinit",""]; 
			_newName = format ["UNITAF_objectUnits_%1", ["UNITAF_objectUnitsCounter",1] call bis_fnc_counter];
			_init = format [";%2;%1 = _this;", _newName, _attachedUnitInit];
			_attachedUnit setVariable ["vehicleinit", _init]; 
		} else {
			_newName = -1; 
		};
		
		_owners = format ["%1",_object getVariable ["RscAttributeOwners",[]]]; //what side owns it
		_owners = [_owners, "WEST", "west"] call UNITAF_zeus_fnc_replaceString;
		_owners = [_owners, "EAST", "east"] call UNITAF_zeus_fnc_replaceString;
		_owners = [_owners, "GUER", "resistance"] call UNITAF_zeus_fnc_replaceString; 
		_owners = [_owners, "CIV", "civilian"] call UNITAF_zeus_fnc_replaceString; 
		
		if (!isnull _attachedUnit) then {
			_init = _init + format ["0 = this spawn {waituntil {!isnil '%1'};",_newName]
						  +	format ["_this setVariable ['bis_fnc_curatorAttachObject_object',%1];",_newName]
						  + 	    "_this setVariable ['updated',true]};";
		} else {
			_init = _init 
					+ 	"this setVariable ['updated',true];";
		};
				
		_mission = _mission 
				+ format ["                       init=""%1"";", _init] + _br;

		_mission = _mission 
				+         "                  };" + _br
				+         "              };" + _br
				+         "			};" + _br;
			
		_countID = _countID + 1;
		_count = _count + 1;
	} forEach _allobjetives;
};

if (count _arrayGroups > 0) then {
	{
		_group 	= _x select 0;
		_side 	= _x select 1;
		_blackListVehicles = []; 
		_refinedGroup = [];
		hint format ["Refining Groups: %1",_group];
		{
			_object = _x; 
			if ((vehicle _object != _object) && (alive vehicle _object)) then {
				if !(vehicle _object in _blackListVehicles) then {
					_refinedGroup set [count _refinedGroup, vehicle _object];
					_blackListVehicles set [count _blackListVehicles, vehicle _object];
				};
			} else {
				if (alive _object) then {_refinedGroup set [count _refinedGroup, _object]};
			};
		} foreach units _group; 
			
		_mission = _mission 
				 + format ["        class Item%1", _count] + _br
				 +         "        {" + _br
				 + format ["              side= ""%1"";", _side] + _br
				 +         "              class Vehicles" + _br
				 +         "              {" + _br
				 + format ["                   items=%1;", count _refinedGroup] + _br;
		
		_groupCounter = 0;
		{
			_object = _x; 
			_pos 	= getPos _object;
			
			_mission = _mission
						 + format ["                   class Item%1", _groupCounter] + _br
						 +         "                   {" + _br;
						 
			//air units
			if (_object isKindOf "air" && ((getpos _object select 2)>10)) then {
				hint format ["%1 is an air unit",_object];
				_mission = _mission			 
						 + 			"                      special=""FLY"";" + _br;
			};
						 
			_mission = _mission			 
						 + format ["                       position[]={%1,%3,%2};", _pos select 0, _pos select 1, _pos select 2] + _br
						 + format ["                       azimut=%1;", getDir _object] + _br
						 + format ["                       id=%1;", _countID] + _br
						 + format ["                       side= ""%1"";", _side] + _br
						 + format ["                       vehicle=""%1"";", typeof _object] + _br;
						 
			if (count crew _object > 0) then {
				if (leader _group in crew _object) then {
					hint format ["%1 is leader in Crew",_object];
					_mission = _mission
							 +         "                       leader=1;" + _br;
				};
			} else {
				if (_object == leader _group) then {
					hint format ["%1 is Leader",_object];
					_mission = _mission
							 +         "                       leader=1;" + _br;
				};
			};
			
			if (locked _object == 2) then {
				hint format ["Locking %1",_object];
				_mission = _mission
							 +         "                      lock=""LOCKED"";" + _br;
			};
			
			_mission = _mission
						 + format ["                       rank=%1;",rank _object] + _br
						 + format ["                       skill=%1;",skill _object] + _br
						 + format ["                       health=%1;",1 - (damage _object)] + _br
						 + format ["                       fuel=%1;",fuel vehicle _object] + _br
						 + format ["                       offsetY=%1;", (getposATL _object) select 2] + _br;

			
			if (!isnil {_object getvariable "vehicleinit"}) then {
				//Set variable for sqm save
				_newString = [(_object getvariable "vehicleinit"), "_this", "this"] call UNITAF_zeus_fnc_replaceString;
				_finalString = [_newString, '"', "'"] call UNITAF_zeus_fnc_replaceString;
				
				_mission = _mission 
						+ format ["                       init=""%1"";", _finalString] + _br;
			};
			
			if (!isnil {_object getvariable "text"}) then {
				_mission = _mission 
						+ format ["                       text=""%1"";", (_object getvariable "text")] + _br;
			};
			
			_mission = _mission 
						+         "                  };" + _br;
						
			_groupCounter = _groupCounter + 1;
			_countID = _countID + 1;
		} foreach _refinedGroup; 
		hint "Completed Refinining Groups.";
				
		_mission = _mission                 
						+         "              };" + _br;
		
		private ["_wpCounter","_wp"];
		if ((count (waypoints _group) > 0) && (count (waypoints _group) > currentWaypoint _group)) then {
			_mission = _mission                 
						+         "     		 class Waypoints " + _br
						+         "     		     {            " + _br
						+  format ["     		         items=%1;",count (waypoints _group)] + _br;
			
			_wpCounter = 0;
			
			{
				_wp = _x;
				
				_mission = _mission
						+ format ["                   	class Item%1", _wpCounter] + _br
						+         "                   	{           " + _br
						+ format ["                       	position[]={%1,%3,%2};",(waypointPosition _wp) select 0, (waypointPosition _wp) select 1, (waypointPosition _wp) select 2] + _br
						+ format ["                       	type=""%1"";",waypointType _wp] + _br
						+ format ["                       	combatMode=""%1"";",waypointCombatMode _wp] + _br
						+ format ["                       	formation=""%1"";",waypointFormation  _wp] + _br
						+ format ["                       	speed=""%1"";",waypointSpeed _wp] + _br
						+ format ["                       	combat=""%1"";",waypointBehaviour _wp] + _br
						+         "                       	class Effects" + _br
						+         "                       	{" + _br
						+         "                       	};" + _br
						+ format ["                       	showWP=""%1"";",waypointShow _wp] + _br
						+         "                   	};           " + _br;
				_wpCounter = _wpCounter + 1; 
				hint format ["Setting up waypoints for Group: \n\n %1",_group];
			} foreach (waypoints _group);
			
			_mission = _mission 
						+         "     		     };            " + _br;
		};
		
		_mission = _mission  
				 +         "         };" + _br;
				 
		_count = _count + 1;
	  
	} forEach _arrayGroups;
};
_mission = _mission 
					+ "    };" + _br;
			
if ((count _arrayVehicles) > 0) then {
	_mission = _mission 
				+ "    class Vehicles" + _br
				+ "    {" + _br
				+ format ["        items= %1;", count _arrayVehicles] + _br;
				
	_count = 0;

	{
		_object = _x select 0;
		_side 	= _x select 1;
		_pos = getPos _object;

		_mission = _mission 
				 + format ["        class Item%1", _count] + _br
				 +         "        {" + _br
				 + format ["             position[]={%1,%3,%2};", _pos select 0, _pos select 1, _pos select 2] + _br
				 + format ["             azimut=%1;", getDir _object] + _br
				 + format ["             id=%1;", _countID] + _br
				 + format ["             side= ""%1"";", _side] + _br
				 + format ["             vehicle=""%1"";", typeof _object] + _br
				 +         "             skill=0.6;" + _br
				 + format ["             offsetY=%1;", (getposATL _object) select 2] + _br;
				
		if((typeof _object) in _objects_to_mod) then {
			_newString = format [(_object getvariable ["vehicleinit",""]) + "_this enableSimulation false;"];
			_object setvariable ["vehicleinit",_newString];
			_newString = [(_object getvariable "vehicleinit"), "_this", "this"] call UNITAF_zeus_fnc_replaceString;
			_finalString = [_newString, '"', "'"] call UNITAF_zeus_fnc_replaceString;
		};
				
		//ammoboxes
		if(getText(configFile >> "cfgVehicles" >> (typeof _object) >> "vehicleClass") == "Ammo") then {
			_weaponcargo = weaponcargo _object;
			_magazinecargo = magazinecargo _object;
			_backpackcargo = backpackcargo _object;
			_itemcargo = itemCargo _object;
			hint format ["Setting up ammoboxes: \n\n %1 \n\n %2 \n\n %3 \n\n %4",_weaponcargo,_magazinecargo,_backpackcargo,_itemcargo];
			_newString = format [(_object getvariable ["vehicleinit",""]) + "clearweaponcargo _this; clearmagazinecargo _this; clearbackpackcargo _this; clearitemcargo _this; {_this addMagazineCargo _x} foreach %1; {_this addWeaponCargo _x} foreach %2; {_this addItemCargo _x} foreach %3; {_this addBackpackCargo _x} foreach %4;",_magazinecargo,_weaponcargo,_itemcargo,_backpackcargo] ;
			_object setvariable ["vehicleinit",_newString];
			_newString = [(_object getvariable "vehicleinit"), "_this", "this"] call UNITAF_zeus_fnc_replaceString;
			_finalString = [_newString, '"', "'"] call UNITAF_zeus_fnc_replaceString;
		};
				 
		if (!isnil {_object getvariable "vehicleinit"}) then {
			_newString = [(_object getvariable "vehicleinit"), "_this", "this"] call UNITAF_zeus_fnc_replaceString;
			_finalString = [_newString, '"', "'"] call UNITAF_zeus_fnc_replaceString;
			
			_mission = _mission 
				 + format ["             init=""%1"";",_finalString] + _br;
		};
		
		if (!isnil {_object getvariable "text"}) then {
			_mission = _mission 
				+ format ["              text=""%1"";", (_object getvariable "text")] + _br;
		};
			
		_mission = _mission 
				+         "        };" + _br;
		
		_count = _count + 1;
		_countID = _countID +1;
	  
	} forEach _arrayVehicles;

	_mission = _mission 
				+ "    };" + _br;

};

if (count allMapMarkers > 0) then {		
	hint "setting up map markers";
	private ["_marker","_markerCounter"]; 
	
	_markerCounter = 0;
	_mission = _mission                 
					+         "     		 class Markers" + _br
					+         "     		     {            " + _br
					+  format ["     		         items=%1;",count allMapMarkers] + _br;
					
	{
		_marker = _x;

		_mission = _mission
					+ format ["                   	  class Item%1", _markerCounter] + _br
					+         "                   	  {           " + _br
					+ format ["                       	  position[]={%1,%3,%2};",(markerPos _marker) select 0, (markerPos _marker) select 1, (markerPos _marker) select 2] + _br
					+ format ["                       	  name=""%1"";",_marker] + _br
					+ format ["                       	  text=""%1"";",markerText _marker] + _br
					+ format ["                       	  markerType=""%1"";",markerShape _marker] + _br
					+ format ["                       	  type=""%1"";",markerType  _marker] + _br
					+ format ["                       	  colorName=""%1"";",markerColor   _marker] + _br
					+ format ["                       	  a=%1;",(markerSize _marker) select 0] + _br
					+ format ["                       	  b=%1;",(markerSize _marker) select 1] + _br
					+ format ["                       	  angle=%1;",markerDir  _marker] + _br
					+         "                   	  };" + _br;
				
		_markerCounter = _markerCounter + 1; 
	} foreach allMapMarkers;
	
	_mission = _mission 
					+         "					};" + _br;
};

_mission = _mission 
		+ "};" + _br
		+ "class Intro {" + _br
		+ "    addOns[] = {}; " + _br
		+ "    addOnsAuto[] = {}; " + _br 
		+ "    randomSeed = " + _seed + ";" + _br
		+ "    class Intel {}; " + _br
		+ "};" + _br
		+ "class OutroWin {" + _br
		+ "    addOns[] = {}; " + _br
		+ "    addOnsAuto[] = {}; " + _br 
		+ "    randomSeed = " + _seed + ";" + _br
		+ "    class Intel {}; " + _br 
		+ "};" + _br
		+ "class OutroLoose {" + _br
		+ "    addOns[] = {}; " + _br
		+ "    addOnsAuto[] = {}; " + _br 
		+ "    randomSeed = " + _seed + ";" + _br
		+ "    class Intel {}; " + _br
		+ "};" + _br;
copyToClipboard _mission;
sleep 3;
hint "Mission saved to clipboard.";