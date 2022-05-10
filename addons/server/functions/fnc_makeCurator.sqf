#include "script_component.hpp"
/**
 * Author: Katalam
 * Source: https://github.com/Katalam/KAT_Template/blob/master/kat_ttt_template.malden/functions/admintools/fn_createZeus.sqf
 * Give player Zeus access
 *
 * Arguments:
 * 0: player <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params ["_player"];

// Spawn it, to support SLEEP
[_player] spawn {
	params ["_player"];

	 if (isNull (getAssignedCuratorLogic _player)) exitWith {
        private _grp = createGroup sideLogic;
        private _curator = _grp createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "NONE"];

		// set Curator settings
		_curator setVariable ["showNotification", false];
		_curator setVariable ["birdType", "", true];
		_curator setCuratorWaypointCost 0;
		_curator setcuratorcoef ["place", 0];
		_curator setcuratorcoef ["edit", 0];
		_curator setcuratorcoef ["delete", 0];
		_curator setcuratorcoef ["destroy", 0];
		_curator setcuratorcoef ["group", 0];
		_curator setcuratorcoef ["synchronize", 0];

		//--- All (including unofficial ones)
        _curator setVariable ["Addons", 3, true];

        _curator addCuratorEditableObjects [vehicles, true];
        _curator addCuratorEditableObjects [(allMissionObjects "Man"), false];
        _curator addCuratorEditableObjects [(allMissionObjects "Air"), true];
        _curator addCuratorEditableObjects [(allMissionObjects "Ammo"), false];

        [_curator, [-1, -2, 2]] call BIS_fnc_setCuratorVisionModes;

        _curator addEventHandler ["CuratorPinged", {
			params ["_curator", "_unit"];
            private _zeus = getAssignedCuratorUnit _curator;
            if (isNull _zeus) then {
				// if GM doesn't exist anymore, remove the module
                unassignCurator _curator;
                deleteVehicle _curator;
            };
        }];

		_player assignCurator _curator;

		// remove Curator rights when unit gets killed
		/*
		// temp disabled, for now
		private _eh_id = _player addEventHandler ["killed", {
			params ["_player"];
			
			private _curObject = getAssignedCuratorLogic _player;

			if (!isNull _curObject) then {
				(group _curObject) deleteGroupWhenEmpty true;
				unassignCurator _player;
				deleteVehicle _curObject;
			};
			_player removeEventHandler ["killed", _player getVariable QGVAR(curatorKEH)];
		}];
		_player setVariable [QGVAR(curatorKEH), _eh_id];
		*/
    };

	/**
	 * Author: Dedmen
 	 * Source: https://gist.github.com/dedmen/3fa5f648631dd14a4173edea7580045e
	 *
	private _curVarName = (str _player)+"Cur";

	// delete any curator modules for this unit if already existing
	if (!isNil _curVarName) then {
		deleteVehicle (missionNamespace getVariable [_curVarName, objNull]);
		missionNamespace setVariable [_curVarName, nil, true];
	};

	if (isNil _curVarName) then {
		// create single Curator Group (to prevent hitting the 144 group limit)
		if (isNil "CuratorGroup") then {
			CuratorGroup = creategroup sideLogic;
		};
		// create a new Curator Module in the group
		private _curObject = CuratorGroup createunit["ModuleCurator_F", [0, 0, 0], [], 0.5, "NONE"];

		// set Curator settings
		_curObject setVariable ["showNotification", false];
		_curObject setVariable ["birdType", "", true];
		_curObject setCuratorWaypointCost 0;
		_curObject setcuratorcoef ["place", 0];
		_curObject setcuratorcoef ["edit", 0];
		_curObject setcuratorcoef ["delete", 0];
		_curObject setcuratorcoef ["destroy", 0];
		_curObject setcuratorcoef ["group", 0];
		_curObject setcuratorcoef ["synchronize", 0];

		// add Curator Object to Mission Variable (for future use)
		missionNamespace setVariable [_curVarName, _curObject, true];

		publicVariable "CuratorGroup";
		unassignCurator _curObject;

		// add all active mods/addons to the curator
		_cfg = "true" configClasses (configFile >> "CfgPatches"); 
		_newAddons = []; 
		{ 
			_name = configName _x; 
			_newAddons pushBack _name;
		} forEach _cfg;
		if (count _newAddons > 0) then {
			_curObject addCuratorAddons _newAddons;
		};

		private _addZeusObjects = QGVAR(Zeus_addObjects) call CBA_settings_fnc_get;
		if (_addZeusObjects) then {
			// add all current objects to Curator
			[_curObject] spawn {
				params ["_curObject"];
				_curObject addCuratorEditableObjects[(allMissionObjects "All"), true];
			};
		};

		private _curObject = missionNamespace getVariable [_curVarName, objNull];
		unassignCurator _curObject;
		sleep 0.4;
		_player assignCurator _curObject;

		// remove Curator rights when unit gets killed
		private _eh_id = _player addEventHandler ["killed", {
			params ["_player"];
			private _curVarName = (str _player)+"Cur";

			private _curObject = missionNamespace getVariable [_curVarName, objNull];
			if (!isNull _curObject) then {
				(group _curObject) deleteGroupWhenEmpty true;
				deleteVehicle _curObject;
			};
			_player removeEventHandler ["killed", _player getVariable QGVAR(curatorKEH)];
		}];
		_player setVariable [QGVAR(curatorKEH), _eh_id];
	};
	*/
};