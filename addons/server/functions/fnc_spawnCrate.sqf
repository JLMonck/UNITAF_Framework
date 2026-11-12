#include "script_component.hpp"
/*
 * Author: JLMonck
 * Spawn what Zeus asked for in "Request logistics", on the server: a crate from the website, a
 * preset from the mod (CfgSupplies), or a full ACE Arsenal. The contents go in the boxes
 * packSupplies chooses (the smallest carryable one, more when needed) unless a box was picked,
 * and every box is handed to every Zeus.
 *
 * Arguments:
 * 0: What to spawn: "db:<crate id>", "mod:<CfgSupplies class>", or "empty" for an empty box <STRING>
 * 1: Box class name, or "" for automatic <STRING>
 * 2: Full ACE Arsenal instead <BOOL>
 * 3: Position ASL (ZEN gives Zeus's click as ASL; the tablet sends the spot in front of the player) <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["db:7101", "", false, getPos player] call unitaf_server_fnc_spawnCrate;
 *
 * Public: No
 */

params [["_choice", "", [""]], ["_type", "", [""]], ["_arsenal", false, [false]], ["_position", [0, 0, 0], [[]]]];

private _boxes = [];

if (_choice isEqualTo "empty") exitWith {
	// An empty box: the one chosen, or a medium case when left on Automatic
	private _box = [_type, QEGVAR(logistics,MetalCase_500)] select (_type isEqualTo "");
	{ [_x] call FUNC(addToCurators); } forEach ([_position, [[_box, []]]] call EFUNC(logistics,spawnSupplies));
};

if (_arsenal) then {
	// A full ACE Arsenal is one box: the one chosen, or a large case when left on Automatic
	private _box = [_type, QEGVAR(logistics,MetalCase_1000)] select (_type isEqualTo "");
	_boxes = [_position, [[_box, []]]] call EFUNC(logistics,spawnSupplies);
	[_boxes select 0, true] call ace_arsenal_fnc_initBox;
} else {
	(_choice splitString ":") params [["_source", ""], ["_key", ""]];
	private _contents = switch (_source) do {
		case "db": { [parseNumber _key] call FUNC(queryCrateContents) };
		case "mod": { [_key] call EFUNC(logistics,getSupplyContents) };
		default { [] };
	};

	if (_contents isEqualTo []) exitWith {
		diag_log format ["UNITAF logistics: nothing to spawn for %1", _choice];
	};

	_boxes = [_position, [_contents, _type] call EFUNC(logistics,packSupplies)] call EFUNC(logistics,spawnSupplies);
};

{
	[_x] call FUNC(addToCurators);
} forEach _boxes;
