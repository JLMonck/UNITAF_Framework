#include "script_component.hpp"
/*
 * Author: Grezvany13, JLMonck
 * Zeus's "Request logistics" dialog: what to spawn (the deployment's crates from the website,
 * then the mod's own presets, or an empty box), which box (Automatic: the smallest that fits, more
 * if needed), or a full ACE Arsenal. The boxes are the website's allowed ones that are in this
 * game, else the mod's own (unitaf_logistics_fnc_getBoxes, 2.6.0); one offered only as an empty
 * box says so, and the server packs nothing into it. Opened by the server's crateList reply; the
 * spawn runs on the server.
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
_choices pushBack "empty";
_labels pushBack ["Empty box", "Nothing in it; the box picked below, or the smallest a soldier can carry", "", [0.7, 0.7, 0.7, 1]];

// Which box: Automatic first, then every box smallest first
(call EFUNC(logistics,getBoxes)) params ["_containers"];
private _containerClasses = [""] + (_containers apply { _x select 1 });
private _containerNames = [["Automatic", "Smallest box that fits; more boxes if needed", ""]] + (_containers apply {
	_x params ["_space", "_class", "", "", "_emptyOnly", "_name"];
	[[_name, format ["%1 (empty box only)", _name]] select _emptyOnly, format ["Space: %1", _space], getText (configFile >> "CfgVehicles" >> _class >> "editorPreview")]
});

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
