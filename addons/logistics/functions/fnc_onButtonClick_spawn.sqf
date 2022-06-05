#include "script_component.hpp"
params ["_ctrl"];
private _dialog = ctrlParent _ctrl;
_state = uiNamespace getVariable "unilog_log_dialog_state";



switch (_state) do {
    case "items": {

        //Grab data from IDC_Spawnable_crate 
        _ctrl = _dialog displayCtrl IDC_spawned_crate;
        _current_selection = lbCurSel IDC_spawned_crate;
        _crate_data = _ctrl lbData _current_selection;
        
        //End grab
        private _smallBox = createVehicle [_crate_data, getPos unitaf_logisticsMenu_bigBox, [], 2, "NONE"];

        clearWeaponCargoGlobal _smallBox;
        clearBackpackCargoGlobal _smallBox;
        clearItemCargoGlobal _smallBox;
        clearMagazineCargoGlobal _smallBox;

        private _allItems = [];

        {
            for "_i" from 1 to (_x select 1) do {
            _allItems pushBack [_x select 0,_x select 2];
            
            };
        } forEach unitaf_logisticsMenu_smallBoxCargo;
        //Send data to EH
        

        {
            private _class = _x select 0;
            private _parentClass = _x select 1;
            switch (_parentClass) do {
                case ("CfgVehicles"): {
                    if (_class in (backpackCargo unitaf_logisticsMenu_bigBox)) then {
                        _smallBox addBackpackCargoGlobal [_class, 1];
                        [unitaf_logisticsMenu_bigBox,_class] call CBA_fnc_removeBackpackCargo;
                    } else {
                        systemChat format ["%1 could not be added because it has been removed already.", [(configFile >> _parentClass >> _class),"displayName"] call BIS_fnc_returnConfigEntry];
                    };
                };
                case ("CfgWeapons"): {
                    if (_class in (itemCargo unitaf_logisticsMenu_bigBox) || _class in (weaponCargo unitaf_logisticsMenu_bigBox)) then {
                        _smallBox addItemCargoGlobal [_class, 1];
                        private _r = [unitaf_logisticsMenu_bigBox,_class] call CBA_fnc_removeItemCargo;
                        if (!_r) then {[unitaf_logisticsMenu_bigBox,_class] call CBA_fnc_removeWeaponCargo;};
                    } else {
                        systemChat format ["%1 could not be added because it has been removed already.", [(configFile >> _parentClass >> _class),"displayName"] call BIS_fnc_returnConfigEntry];
                    };
                };
                case ("CfgMagazines"): {

                    if (_class in (magazineCargo unitaf_logisticsMenu_bigBox)) then {
                        _smallBox addMagazineCargoGlobal [_class, 1];
                        [unitaf_logisticsMenu_bigBox,_class] call CBA_fnc_removeMagazineCargo;
                    } else {
                        systemChat format ["%1 could not be added because it has been removed already.", [(configFile >> _parentClass >> _class),"displayName"] call BIS_fnc_returnConfigEntry];
                    };
                };
            };
        } forEach _allItems;
        //Add crate to players hands
        [player, _smallBox] call ace_dragging_fnc_startCarry;
        closeDialog 1;
     };
	case "crates": { 
		_ctrl_crate = _dialog displayCtrl IDC_BIGBOX;
        _curSel = lnbCurSelRow _ctrl_crate;
        _selData = _ctrl_crate lnbData [_curSel,0];
        _data = (parseSimpleArray _selData);
        
        //Debug
        _text = format ["Trying to create:%1 with content:%2",_data select 0,_data select 1];
        systemChat _text;

        _className = _data select 0;
        _contentArray = _data select 1;

        _smallBox = createVehicle [_className, getPos unilog_master_supply_depot, [], 2, "NONE"]; 
        clearWeaponCargoGlobal _smallBox; 
        clearBackpackCargoGlobal _smallBox; 
        clearItemCargoGlobal _smallBox; 
        clearMagazineCargoGlobal _smallBox;
        { 
              
                if (_x select 0 isKindOf ["CA_Magazine", configFile >> "CfgMagazines"]) then { 
                  _smallBox addMagazineCargoGlobal [_x select 0, _x select 1]; 
             }; 

        } forEach _contentArray;

        //Add crate to players hands
        [player, _smallBox] call ace_dragging_fnc_startCarry;


        closeDialog 1;
        
	};
	case "vehicles": {
		
        //Get currentlt selected item
        _ctrl_vic = _dialog displayCtrl IDC_BIGBOX;
        _curSel = lnbCurSelRow _ctrl_vic;
        _selData = _ctrl_vic lnbData [_curSel,0];

        _vehicle = createVehicle [_selData, getPos unitaf_logisticsMenu_bigBox, [], 2, "NONE"];
        [_vehicle] call FUNC(vehicle_Init);
        //Remove from "inventory"
      
        private _bigIndex = [unitaf_logistics_vehicles,_selData] call FUNC(findInTriplets);
        (unitaf_logistics_vehicles select _bigIndex) set [3, ((unitaf_logistics_vehicles select _bigIndex) select 3) - 1];

        closeDialog 1;
	 };
};
