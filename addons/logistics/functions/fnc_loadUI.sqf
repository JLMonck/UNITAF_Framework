#include "script_component.hpp"
disableSerialization;

params ["_dialog","_state"];

//spawnable crates config, move to cba settings ? 


switch (_state) do {
	case "items": {
	_spawnable_crates = [
						"Box_NATO_Ammo_F",
						"Box_NATO_Equip_F",
						"Box_NATO_AmmoVeh_F"
						];
						ctrlShow [IDC_spawned_crate,true];
						ctrlShow [IDC_AMOUNT,true];
						lbClear (_dialog displayCtrl IDC_spawned_crate);

					{
					_displayName = [(configFile >> "CfgVehicles" >> _x),"displayName"] call BIS_fnc_returnConfigEntry;

					_row = (_dialog displayCtrl IDC_spawned_crate) lbAdd _displayName;
					(_dialog displayCtrl IDC_spawned_crate) lbSetData [_row,_x];
					} forEach _spawnable_crates;
					//Get selected smallbox class
					_ctrl = _dialog displayCtrl IDC_spawned_crate;
        			_current_selection = lbCurSel IDC_spawned_crate;
        			_crate_data = _ctrl lbData _current_selection;
					ctrlShow [IDC_spawned_crate,true];
					ctrlShow [IDC_SMALLBOX,true];	

						
					

					//big box items
					lnbClear (_dialog displayCtrl IDC_BIGBOX);
					{
						private _itemClass = _x select 0;
						private _amount = _x select 1;
						private _configClass = _x select 2;
						private _displayName = [(configFile >> _configClass >> _itemClass),"displayName"] call BIS_fnc_returnConfigEntry;
						private _icon =  [(configFile >> _configClass >> _itemClass),"picture"] call BIS_fnc_returnConfigEntry;
						private _row = (_dialog displayCtrl IDC_BIGBOX) lnbAddRow [str _amount, "", _displayName];
						(_dialog displayCtrl IDC_BIGBOX) lnbSetPicture [[_row, 1], _icon];
						(_dialog displayCtrl IDC_BIGBOX) lnbSetData [[_row, 0], _itemClass];
					} forEach unitaf_logisticsMenu_bigBoxCargo;


					private _smallBoxLoad = 0;

					//small box items
					lnbClear (_dialog displayCtrl IDC_SMALLBOX);
					{
						//add row
						private _itemClass = _x select 0;
						private _amount = _x select 1;
						private _configClass = _x select 2;
						private _displayName = [(configFile >> _configClass >> _itemClass),"displayName"] call BIS_fnc_returnConfigEntry;
						private _icon =  [(configFile >> _configClass >> _itemClass),"picture"] call BIS_fnc_returnConfigEntry;
						private _row = (_dialog displayCtrl IDC_SMALLBOX) lnbAddRow [str _amount, "", _displayName];
						(_dialog displayCtrl IDC_SMALLBOX) lnbSetPicture [[_row, 1], _icon];
						(_dialog displayCtrl IDC_SMALLBOX) lnbSetData [[_row, 0], _itemClass];

						//add mass
						_smallBoxLoad = _smallBoxLoad + _amount * ([_itemClass,_configClass] call FUNC(itemMass));
					} forEach unitaf_logisticsMenu_smallBoxCargo;

					unitaf_logisticsMenu_smallBoxFreeSpace = ([(configFile >> "CfgVehicles" >> _crate_data),"maximumLoad"] call BIS_fnc_returnConfigEntry) - _smallBoxLoad;

					//update load
					(_dialog displayCtrl IDC_LOAD) progressSetPosition (_smallBoxLoad / ([(configFile >> "CfgVehicles" >> _crate_data),"maximumLoad"] call BIS_fnc_returnConfigEntry));

	 };
	case "crates": { 
		
		ctrlShow [IDC_spawned_crate,false];
		ctrlShow [IDC_SMALLBOX,false];

		{
			_x params ["_tableID","_displayName","_classnameBox","_contentsArray"];
			_row = (_dialog displayCtrl IDC_BIGBOX) lnbAddRow [_displayName];
			_data = [_classnameBox,_contentsArray];
			(_dialog displayCtrl IDC_BIGBOX) lnbSetData [[_row,0],(str _data)];

		} forEach unitaf_logistics_crates;
	};
	case "vehicles": {
		//uni_log_logistics_vic
		
		ctrlShow [IDC_spawned_crate,false];
		ctrlShow [IDC_AMOUNT,false];

		{
		private _itemClass = _x select 0;
		private _amount = _x select 1;
		
		private _displayName = [(configFile >> "CfgVehicles"  >> _itemClass),"displayName"] call BIS_fnc_returnConfigEntry;
		private _icon =  [(configFile >> "CfgVehicles"  >> _itemClass),"picture"] call BIS_fnc_returnConfigEntry;
		private _row = (_dialog displayCtrl IDC_BIGBOX) lnbAddRow [str _amount, "", _displayName];
		(_dialog displayCtrl IDC_BIGBOX) lnbSetPicture [[_row, 1], _icon];
		(_dialog displayCtrl IDC_BIGBOX) lnbSetData [[_row, 0], _itemClass];
		} forEach unitaf_logistics_vehicles;


	 };
	default { };
};



