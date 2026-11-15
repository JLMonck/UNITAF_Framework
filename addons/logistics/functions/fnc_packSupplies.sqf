#include "script_component.hpp"
/*
 * Author: JLMonck
 * Decide which boxes a crate's contents go in: the website's allowed boxes that are in this game,
 * else the mod's own (unitaf_logistics_fnc_getBoxes, 2.6.0). By default the smallest automatic
 * box it fits in (boxes a soldier can carry; pallets and containers only when picked); a crate of
 * nothing but medical items goes in a medical box when one is big enough. A box offered only as
 * an empty box is never packed: picked for a crate, the crate goes in automatic boxes instead.
 * When it fits in no single box, it is shared over as many of the largest boxes as it takes,
 * so nothing is left behind, and each box is then shrunk to the smallest one its share fits.
 * A box can be named instead, and the same rule fills as many of that box as it takes.
 *
 * Runs once per request, so the config lookups and loops cost nothing during play.
 *
 * Arguments:
 * 0: Contents, [[class name, count], ...] <ARRAY>
 * 1: Box to use, or "" to choose automatically <STRING>
 *
 * Return Value:
 * Boxes, [[box class name, [[class name, count], ...]], ...] <ARRAY>
 *
 * Example:
 * [[["ACE_fieldDressing", 40], ["30Rnd_556x45_Stanag", 60]]] call unitaf_logistics_fnc_packSupplies;
 *
 * Public: No
 */

params [["_contents", [], [[]]], ["_chosen", "", [""]]];

if (_contents isEqualTo []) exitWith { [] };

// The boxes, smallest first: [space, class name, medical, automatic, empty box only, name]
(call FUNC(getBoxes)) params ["_boxes"];

private _units = _contents apply { _x params ["_class", "_count"]; [_class, floor _count, [_class] call FUNC(itemMass)] };
private _total = 0;
{ _total = _total + ((_x select 1) * (_x select 2)); } forEach _units;

// Which boxes may be used: the one named, else medical boxes for an all-medical crate, else plain ones
private _medical = _units findIf { getNumber (configFile >> "CfgWeapons" >> (_x select 0) >> "ACE_isMedicalItem") != 1 } == -1;
private _carryable = _boxes select { _x select 3 };
private _pool = if (_chosen isNotEqualTo "") then {
	_boxes select { (_x select 1) == _chosen && {!(_x select 4)} }
} else {
	private _medicalBoxes = _carryable select { _x select 2 };
	if (_medical && {_medicalBoxes isNotEqualTo []} && {(_medicalBoxes select (count _medicalBoxes - 1) select 0) >= _total}) then {
		_medicalBoxes
	} else {
		_carryable select { !(_x select 2) }
	};
};
if (_pool isEqualTo []) then {
	if (_chosen isNotEqualTo "") then { diag_log format ["UNITAF logistics: %1 is not a box a crate may be packed in; packed automatically", _chosen]; };
	_pool = _carryable;
};
if (_pool isEqualTo []) exitWith { diag_log "UNITAF logistics: no boxes to pack into"; [] };

private _smallestFor = {
	params ["_load"];
	private _index = _pool findIf { (_x select 0) >= _load };
	(_pool select ([_index, count _pool - 1] select (_index == -1))) select 1
};
private _largest = (_pool select (count _pool - 1)) select 0;

// One box when it fits
if (_total <= _largest) exitWith {
	[[[_total] call _smallestFor, _units apply { [_x select 0, _x select 1] }]]
};

// Otherwise share it over the largest boxes, one item at a time, then shrink each box to fit
private _packed = [];
private _box = createHashMap;
private _load = 0;
{
	_x params ["_class", "_count", "_mass"];
	for "_i" from 1 to _count do {
		if (_load > 0 && {_load + _mass > _largest}) then {
			_packed pushBack [_load, _box];
			_box = createHashMap;
			_load = 0;
		};
		_box set [_class, (_box getOrDefault [_class, 0]) + 1];
		_load = _load + _mass;
	};
} forEach _units;
if (_load > 0) then { _packed pushBack [_load, _box]; };

_packed apply {
	_x params ["_boxLoad", "_boxContents"];
	[[_boxLoad] call _smallestFor, _boxContents toArray false]
}
