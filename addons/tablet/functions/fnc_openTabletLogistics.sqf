#include "script_component.hpp"
/**
 * Author: Grezvany13, JLMonck
 * The tablet's Logistics page (D-470): pick what to spawn, see what is in it, pick the box
 * (Automatic: the smallest that fits, more boxes if needed), then Spawn, at base.
 *
 * What to spawn:
 *	- Website crates: the ones this operation's logistics people made (a resupply says whom it
 *	  serves), then the faction's own crates. Listed and read from the server.
 *	- Mod presets: the mod's own CfgSupplies.
 *	- Full ACE Arsenal.
 *	- Empty box.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

private _display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_LOGISTICS] call FUNC(hideAll);
GET_LOGISTICS ctrlShow true;

lbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Type);
lbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
lbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Container);
lnbClear GET_IN_LOGISTICS(IDC_Tablet_Logistics_Preview);

// What is picked: the type, the choice spawnCrate reads ("db:<id>", "mod:<class>", "arsenal",
// "empty"), its contents for the preview, and the box ("" is Automatic)
GVAR(logisticsType) = "";
GVAR(logisticsChoice) = "";
GVAR(logisticsContents) = [];
GVAR(logisticsContainer) = "";

// 1. Type
GVAR(_fnc_setTypes) = {
	private _ctrlTypes = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Type);
	lbClear _ctrlTypes;
	{
		private _index = _ctrlTypes lbAdd (_x select 0);
		_ctrlTypes lbSetData [_index, _x select 1];
	} forEach [
		["Website crates", "db"],
		["Mod presets", "mod"],
		["Full ACE Arsenal", "arsenal"],
		["Empty box", "empty"]
	];
	_ctrlTypes ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_typeChanged))];
};

GVAR(_fnc_typeChanged) = {
	params ["_control", "_selectedIndex"];
	GVAR(logisticsType) = _control lbData _selectedIndex;
	GVAR(logisticsChoice) = "";
	GVAR(logisticsContents) = [];
	call GVAR(_fnc_setPresets);
	call GVAR(_fnc_setPreview);
	call GVAR(_fnc_setContainers);
	true
};

// 2. Preset: what of that type
GVAR(_fnc_setPresets) = {
	private _ctrlPresets = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
	lbClear _ctrlPresets;

	switch (GVAR(logisticsType)) do {
		case "db": {
			// Asked of the server; crateList fills it in (XEH_postInitClient)
			_ctrlPresets lbAdd "Loading the operation's crates…";
			[QEGVAR(ServerEvent,listCrates), [getPosATL player, player, QGVAR(crateList)]] call CBA_fnc_serverEvent;
		};
		case "mod": {
			{
				private _index = _ctrlPresets lbAdd (getText (_x >> "displayName"));
				_ctrlPresets lbSetData [_index, format ["mod:%1", configName _x]];
			} forEach ("true" configClasses (configFile >> "CfgSupplies"));
		};
		case "arsenal": {
			_ctrlPresets lbSetData [_ctrlPresets lbAdd "Full ACE Arsenal", "arsenal"];
		};
		case "empty": {
			_ctrlPresets lbSetData [_ctrlPresets lbAdd "Empty box", "empty"];
		};
	};

	_ctrlPresets ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_presetChanged))];
	if (GVAR(logisticsType) in ["arsenal", "empty"]) then { _ctrlPresets lbSetCurSel 0; };
};

GVAR(_fnc_presetChanged) = {
	params ["_control", "_selectedIndex"];
	private _choice = _control lbData _selectedIndex;
	if (_choice isEqualTo "") exitWith { true };

	GVAR(logisticsChoice) = _choice;
	GVAR(logisticsContents) = [];

	(_choice splitString ":") params ["_source", ["_key", ""]];
	switch (_source) do {
		case "db": {
			// Asked of the server; crateContents fills the preview in (XEH_postInitClient)
			[QEGVAR(ServerEvent,crateContents), [parseNumber _key, player, QGVAR(crateContents)]] call CBA_fnc_serverEvent;
		};
		case "mod": {
			GVAR(logisticsContents) = getArray (configFile >> "CfgSupplies" >> _key >> "items");
		};
	};

	call GVAR(_fnc_setPreview);
	call GVAR(_fnc_setContainers);
	true
};

// 3. Preview: what is in it, and what it weighs
GVAR(_fnc_setPreview) = {
	private _ctrlPreview = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Preview);
	lnbClear _ctrlPreview;

	private _weight = 0;
	{
		_x params ["_item", "_amount"];
		private _config = switch (true) do {
			case (isClass (configFile >> "CfgMagazines" >> _item)): { configFile >> "CfgMagazines" >> _item };
			case (isClass (configFile >> "CfgVehicles" >> _item)): { configFile >> "CfgVehicles" >> _item };
			case (isClass (configFile >> "CfgGlasses" >> _item)): { configFile >> "CfgGlasses" >> _item };
			default { configFile >> "CfgWeapons" >> _item };
		};
		private _name = getText (_config >> "displayName");
		private _index = _ctrlPreview lnbAddRow ["", [_name, _item] select (_name isEqualTo ""), str _amount];
		_ctrlPreview lnbSetPicture [[_index, 0], getText (_config >> "picture")];
		_weight = _weight + (([_item] call EFUNC(logistics,itemMass)) * _amount);
	} forEach GVAR(logisticsContents);

	if (_weight > 0) then {
		// The game's mass is a tenth of a pound
		_ctrlPreview lnbAddRow ["", "Total weight", format ["%1 kg", round (_weight * 0.04536)]];
	};
};

// 4. Box: Automatic first, then every box it fits in, smallest first
GVAR(_fnc_setContainers) = {
	private _ctrlContainers = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Container);
	lbClear _ctrlContainers;

	private _weight = 0;
	{ _weight = _weight + (([_x select 0] call EFUNC(logistics,itemMass)) * (_x select 1)); } forEach GVAR(logisticsContents);

	private _containers = QUOTE((getNumber (_x >> 'scope') >= 2) && (configName _x) isKindOf SQUOTE(EGVAR(logistics,Container_Base))) configClasses (configFile >> "CfgVehicles");
	_containers = _containers select { getNumber (_x >> "maximumLoad") >= _weight };
	_containers = [_containers, [], {configName _x}, "DESCEND"] call BIS_fnc_sortBy;
	_containers = [_containers, [], {getNumber (_x >> "maximumLoad")}, "ASCEND"] call BIS_fnc_sortBy;

	private _index = _ctrlContainers lbAdd "Automatic";
	_ctrlContainers lbSetData [_index, ""];
	_ctrlContainers lbSetTooltip [_index, "The smallest box it fits in; more boxes if needed"];
	{
		_index = _ctrlContainers lbAdd (getText (_x >> "displayName"));
		_ctrlContainers lbSetData [_index, configName _x];
		_ctrlContainers lbSetTooltip [_index, format ["maxLoad: %1", getNumber (_x >> "maximumLoad")]];
		_ctrlContainers lbSetPicture [_index, getText (_x >> "editorPreview")];
	} forEach _containers;

	_ctrlContainers ctrlSetEventHandler ["LBSelChanged", QUOTE(call GVAR(_fnc_containerChanged))];
	_ctrlContainers lbSetCurSel 0;
	GVAR(logisticsContainer) = "";
};

GVAR(_fnc_containerChanged) = {
	params ["_control", "_selectedIndex"];
	GVAR(logisticsContainer) = _control lbData _selectedIndex;
	true
};

call GVAR(_fnc_setTypes);
