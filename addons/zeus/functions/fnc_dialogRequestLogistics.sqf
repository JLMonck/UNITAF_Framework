#include "script_component.hpp"
/*
 * Author: Grezvany13, JLMonck
 * Zeus's "Request logistics" dialog: what to spawn (the deployment's crates from the website,
 * then the mod's own presets), which box (Automatic: the smallest that fits, more if needed),
 * or a full ACE Arsenal. Opened by the server's crateList reply; the spawn runs on the server.
 *
 * Arguments:
 * 0: Position <ARRAY>
 * 1: The deployment's crates, from unitaf_server_fnc_queryCrates <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_position", ["_crates", [], [[]]]];

// What to spawn: the website's crates first (a resupply says whom it serves), then the mod's presets
private _choices = [];
private _labels = [];
{
	_x params ["_id", "_name", "_callsign", "_factionCrate"];
	_choices pushBack format ["db:%1", _id];
	_labels pushBack [
		_name,
		[["Made for this deployment", "The faction's crate"] select (_factionCrate isEqualTo 1), format ["Resupply for %1", _callsign]] select (_callsign isNotEqualTo ""),
		"",
		[[0.85, 0.75, 0.45, 1], [1, 1, 1, 1]] select (_factionCrate isEqualTo 1)
	];
} forEach _crates;
{
	_choices pushBack format ["mod:%1", configName _x];
	_labels pushBack [getText (_x >> "displayName"), "From the mod", "", [0.7, 0.7, 0.7, 1]];
} forEach ("true" configClasses (configFile >> "CfgSupplies"));

if (_choices isEqualTo []) exitWith {
	["No crates for this deployment, and no presets in the mod"] call zen_common_fnc_showMessage;
};

// Which box: Automatic first, then every box smallest first
private _containers = QUOTE((getNumber (_x >> 'scope') >= 2) && (configName _x) isKindOf SQUOTE(EGVAR(logistics,Container_Base))) configClasses (configFile >> "CfgVehicles");
_containers = [_containers, [], {configName _x}, "DESCEND"] call BIS_fnc_sortBy;
_containers = [_containers, [], {getNumber (_x >> "maximumLoad")}, "ASCEND"] call BIS_fnc_sortBy;
private _containerClasses = [""] + (_containers apply { configName _x });
private _containerNames = [["Automatic", "Smallest box that fits; more boxes if needed", ""]] + (_containers apply { [(getText (_x >> "displayName")), format ["maxLoad: %1", (getNumber (_x >> "maximumLoad"))], (getText (_x >> "editorPreview"))] });

[
	"Logistics Request",
	[
		["COMBO", "Supplies", [_choices, _labels, 0], true],
		["COMBO", "Container Type", [_containerClasses, _containerNames, 0], false],
		["CHECKBOX", "Full ACE Arsenal", false]
	],
	{
		_this call FUNC(actionRequestLogistics);
	},
	{
		// nothing on Cancel
	},
	[_position]
] call zen_dialog_fnc_create;
