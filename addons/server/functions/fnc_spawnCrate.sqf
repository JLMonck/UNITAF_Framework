#include "script_component.hpp"
/*
 * Author: JLMonck
 * Spawn what Zeus asked for in "Request logistics", on the server: a crate from the website, a
 * preset from the mod (CfgSupplies), or a full ACE Arsenal. The contents go in the boxes
 * packSupplies chooses (the smallest automatic one, more when needed) unless a box was picked,
 * and every box is handed to every Zeus. The boxes are the website's allowed ones that are in this
 * game, else the mod's own (unitaf_logistics_fnc_getBoxes, 2.6.0): an empty box is the smallest
 * automatic box and a full ACE Arsenal the largest, where they were Metal Case Medium and Large.
 * A box that is not on the list is never spawned; the choice falls back to Automatic.
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

// The boxes this game may use, and the ones an empty box and a full arsenal come in
(call EFUNC(logistics,getBoxes)) params ["_usable", "_fromSite"];
private _automatic = _usable select { _x select 3 };
// With the mod's own boxes, the medium and large metal cases as before 2.6.0
private _smallest = QEGVAR(logistics,MetalCase_500);
private _largest = QEGVAR(logistics,MetalCase_1000);
if (_fromSite && {_automatic isNotEqualTo []}) then {
	_smallest = (_automatic select 0) select 1;
	_largest = (_automatic select (count _automatic - 1)) select 1;
};

// Only a box on the list: an empty box may be any of them, anything else not one offered only empty
if (_type isNotEqualTo "" && {_usable findIf { (_x select 1) == _type && {_choice isEqualTo "empty" || {!(_x select 4)}} } == -1}) then {
	diag_log format ["UNITAF logistics: %1 is not offered for this; using Automatic", _type];
	_type = "";
};

if (_choice isEqualTo "empty") exitWith {
	// An empty box: the one chosen, or the smallest automatic box when left on Automatic
	private _box = [_type, _smallest] select (_type isEqualTo "");
	{ [_x] call FUNC(addToCurators); } forEach ([_position, [[_box, []]]] call EFUNC(logistics,spawnSupplies));
};

if (_arsenal) then {
	// A full ACE Arsenal is one box: the one chosen, or the largest automatic box when left on Automatic
	private _box = [_type, _largest] select (_type isEqualTo "");
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
