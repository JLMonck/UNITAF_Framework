#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the Logistics Page on the tablet
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

private _display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_LOGISTICS] call FUNC(hideAll);
GET_LOGISTICS ctrlShow true;

lnbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Type);
lnbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
lnbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Container);

GVAR(selectedType) = nil;
GVAR(selectedPreset) = nil;
GVAR(selectedContainer) = nil;

/**
 * set Types
 *	- Database Presets
 *	- Mod Presets
 *	- Arsenal
 *	- Empty
 */
GVAR(_fnc_setTypes) = {
	_ctrlTypes = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Type);
	{
		_index = _ctrlTypes lbAdd (_x select 0);
		_ctrlTypes lbSetValue [_index, _foreachIndex];
		_ctrlTypes lbSetData [_index, (_x select 1)];
	} forEach [
		["Database Presets", "db"],
		["Mod Presets", "mod"],
		["Arsenal", "arsenal"],
		["Empty", "empty"]
	];

	GVAR(_fnc_typeChange) = {
		params ["_control", "_selectedIndex"];

		_selected = _control lbValue _selectedIndex;
		_selectedData = _control lbData _selectedIndex;

		GVAR(selectedType) = _selectedData;

		if (GVAR(selectedType) == "empty") then {
			private _ctrlPresets = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
			lnbClear _ctrlPresets; // empty list first!
			GVAR(selectedPreset) = nil;
			call GVAR(_fnc_setContainers);
		} else {
			call GVAR(_fnc_setPresets);
		};
		true;
	};
	_ctrlTypes ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_typeChange))];
};

/**
 * set Presets
 *	- Database Presets
 *	 	> list database results
 *	- Mod Presets
 *		> list mod results
 *	- Arsenal
 *		> Limited ACE Arsenal
 *		> Full ACE Arsenal
 *	- Empty
 */
GVAR(_fnc_setPresets) = {
	_selectedType = GVAR(selectedType);

	private _ctrlPresets = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
	lnbClear _ctrlPresets; // empty list first!
	
	switch (_selectedType) do {
		case "db": {
			// list presets from DB
		};
		case "mod": {
			{
				_index = _ctrlPresets lbAdd (getText (_x >> "displayName"));
				_ctrlPresets lbSetValue [_index, _foreachIndex];
				_ctrlPresets lbSetData [_index, (configName _x)];
				
			} forEach ("true" configClasses (configFile >> "CfgSupplies"));
		};
		case "arsenal": {
			{
				_index = _ctrlPresets lbAdd (_x select 0);
				_ctrlPresets lbSetValue [_index, _foreachIndex];
				_ctrlPresets lbSetData [_index, (_x select 1)];
			} forEach [
				["Limited ACE Arsenal", "limited"],
				["Full ACE Arsenal", "full"],
				["Custom ACE Arsenal", "custom"]
			];
		};
		case "empty": {};
	};

	GVAR(_fnc_presetChanged) = {
		params ["_control", "_selectedIndex"];

		_selected = _control lbValue _selectedIndex;
		_selectedData = _control lbData _selectedIndex;

		GVAR(selectedPreset) = _selectedData;

		call GVAR(_fnc_setContainers);
		true;
	};
	_ctrlPresets ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_presetChanged))];
};

/**
 * list classes from 'Logistics'
 */
GVAR(_fnc_setContainers) = {
	_selectedType = GVAR(selectedType);
	_selectedPreset = GVAR(selectedPreset);

	private _ctrlContainers = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Container);
	lnbClear _ctrlContainers; // empty list first!

	private _weight = 0;
	switch (_selectedType) do {
		case "db": {
			//call GVAR(_fnc_setContentPreview);
		};
		case "mod": {
			call GVAR(_fnc_setContentPreview);
			{
				_mass = [_x select 0] call FUNC(logisticsGetItemMass);
				_weight = _weight + (_mass * (_x select 1));
			} forEach getArray (configFile >> "CfgSupplies" >> _selectedPreset >> "items");
		};
	};
	private _containers = [];
	if (_weight > 0) then {
		_containers = QUOTE((getNumber (_x >> 'scope') >= 2) && (getNumber (_x >> 'maximumLoad') >= _weight) && (configName _x) isKindOf SQUOTE(EGVAR(logistics,Container_Base))) configClasses (configFile >> "CfgVehicles");
	} else {
		_containers = QUOTE((getNumber (_x >> 'scope') >= 2) && (configName _x) isKindOf SQUOTE(EGVAR(logistics,Container_Base))) configClasses (configFile >> "CfgVehicles");
	};

	_containers = [_containers, [], {configName _x}, "DESCEND"] call BIS_fnc_sortBy;
	_containers = [_containers, [], {getNumber (_x >> "maximumLoad")}, "ASCEND"] call BIS_fnc_sortBy;
	private _containerArray = _containers apply { [configName _x, (getText (_x >> "displayName")), format ["maxLoad: %1", (getNumber (_x >> "maximumLoad"))], (getText (_x >> "editorPreview"))]};
	
	{
		_index = _ctrlContainers lbAdd (_x select 1);
		_ctrlContainers lbSetValue [_index, _foreachIndex];
		_ctrlContainers lbSetData [_index, (_x select 0)];
		_ctrlContainers lbSetTooltip [_index, (_x select 2)];
		_ctrlContainers lbSetPicture  [_index, (_x select 3)];
	} forEach _containerArray;

	GVAR(_fnc_containerChanged) = {
		params ["_control", "_selectedIndex"];

		_selected = _control lbValue _selectedIndex;
		_selectedData = _control lbData _selectedIndex;

		GVAR(selectedContainer) = _selectedData;

		call GVAR(_fnc_setInventory);
		true;
	};
	_ctrlContainers ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_containerChanged))];
};

GVAR(_fnc_setInventory) = {
	_selectedType = GVAR(selectedType);
	_selectedPreset = GVAR(selectedPreset);
	_selectedContainer = GVAR(selectedContainer);

	diag_log format ["Type: %1 - Preset: %2 - Container: %3", _selectedType, _selectedPreset, _selectedContainer];
	systemChat format ["Type: %1 - Preset: %2 - Container: %3", _selectedType, _selectedPreset, _selectedContainer];
};

GVAR(_fnc_setContentPreview) = {
	_selectedType = GVAR(selectedType);
	_selectedPreset = GVAR(selectedPreset);

	private _ctrlPreview = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Preview);
	lnbClear _ctrlPreview; // empty list first!

	private _objects = [];

	switch (_selectedType) do {
		case "db": {};
		case "mod": {
			_objects = getArray (configFile >> "CfgSupplies" >> _selectedPreset >> "items");
		};
	};

	private _itemsList = uiNamespace getVariable QGVAR(itemsList);
	private _cfgGlasses   = configFile >> "CfgGlasses";
    private _cfgMagazines = configFile >> "CfgMagazines";
    private _cfgVehicles  = configFile >> "CfgVehicles";
    private _cfgWeapons   = configFile >> "CfgWeapons";

	{
		_x params ["_item", "_amount"];

		// Get appropriate config for each item, items can be from any category
		private _config = switch (true) do {
			case (_item in (_itemsList select 7));
			case (_item in (_itemsList select 20));
			case (_item in (_itemsList select 21)): {
				_cfgMagazines >> _item;
			};
			case (_item in (_itemsList select 11)): {
				_cfgVehicles >> _item;
			};
			case (_item in (_itemsList select 12)): {
				_cfgGlasses >> _item;
			};
			default {
				_cfgWeapons >> _item;
			};
		};
		private _displayName = getText (_config >> "displayName");
		// Check if the item is matches the current filter
		private _picture = getText (_config >> "picture");
		private _tooltip = format ["%1\n%2", _displayName, _item];

		private _index = _ctrlPreview lnbAddRow ["", _displayName, str (_amount)];
		//_ctrlPreview lnbSetData    [[_index, 0], _item];
		_ctrlPreview lnbSetPicture [[_index, 0], _picture];
		//_ctrlPreview lbSetTooltip  [_index * count lnbGetColumnsPosition _ctrlPreview, _tooltip];
	} forEach _objects;
};

// Initialize scripts
call GVAR(_fnc_setTypes);