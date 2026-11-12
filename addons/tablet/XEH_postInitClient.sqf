#include "script_component.hpp"
/**
 * Author: Grezvany13
 * XEH postInitClient
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

if !(hasInterface) exitWith {};

// The server's answers for the Logistics page (D-470): the operation's crates, then one's contents
[QGVAR(crateList), {
	params ["_position", ["_crates", [], [[]]]];
	if ((missionNamespace getVariable [QGVAR(logisticsType), ""]) isNotEqualTo "db") exitWith {};
	private _ctrlPresets = GET_IN_LOGISTICS(IDC_Tablet_Logistics_Combo_Preset);
	if (isNull _ctrlPresets) exitWith {};
	lbClear _ctrlPresets;
	if (_crates isEqualTo []) exitWith {
		_ctrlPresets lbAdd "No crates on the website for this operation";
	};
	{
		_x params ["_id", "_name", "_callsign"];
		private _index = _ctrlPresets lbAdd ([_name, format ["%1 (%2)", _name, _callsign]] select (_callsign isNotEqualTo ""));
		_ctrlPresets lbSetData [_index, format ["db:%1", _id]];
	} forEach _crates;
}] call CBA_fnc_addEventHandler;

[QGVAR(crateContents), {
	params ["_crate", ["_contents", [], [[]]]];
	// Only if it is still the crate picked
	if ((missionNamespace getVariable [QGVAR(logisticsChoice), ""]) isNotEqualTo format ["db:%1", _crate]) exitWith {};
	GVAR(logisticsContents) = _contents;
	call GVAR(_fnc_setPreview);
	call GVAR(_fnc_setContainers);
}] call CBA_fnc_addEventHandler;

waitUntil {!isNull player};
//waitUntil {alive player};

if (!isClass(configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	player addAction  [
		"Open UNITAF Tablet",
		{
			_this call FUNC(openTablet);
		}
	];
};