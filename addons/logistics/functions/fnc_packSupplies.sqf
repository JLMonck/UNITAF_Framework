#include "script_component.hpp"
/*
 * Author: JLMonck
 * Decide which of the mod's boxes a crate's contents go in. By default the smallest carryable
 * box it fits in (up to AUTO_MAX_LOAD; the shipping containers only when picked); a crate of
 * nothing but medical items goes in a medical box when one is big enough.
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

// The mod's own boxes, smallest first, read once and kept: [load, class name, medical]
if (isNil QGVAR(boxes)) then {
	private _base = QGVAR(Container_Base);
	private _boxes = [];
	{
		private _class = configName _x;
		private _load = getNumber (_x >> "maximumLoad");
		if (_load > 0 && {getNumber (_x >> "scope") >= 2} && {_class isKindOf [_base, configFile >> "CfgVehicles"]}) then {
			// Our medical variants are the classes named *_Medical
			_boxes pushBack [_load, _class, (_class select [count _class - 8]) == "_Medical"];
		};
	} forEach ("true" configClasses (configFile >> "CfgVehicles"));
	_boxes sort true;
	GVAR(boxes) = _boxes;
};

private _units = _contents apply { _x params ["_class", "_count"]; [_class, floor _count, [_class] call FUNC(itemMass)] };
private _total = 0;
{ _total = _total + ((_x select 1) * (_x select 2)); } forEach _units;

// Which boxes may be used: the one named, else medical boxes for an all-medical crate, else plain ones
private _medical = _units findIf { getNumber (configFile >> "CfgWeapons" >> (_x select 0) >> "ACE_isMedicalItem") != 1 } == -1;
private _carryable = GVAR(boxes) select { (_x select 0) <= AUTO_MAX_LOAD };
private _pool = if (_chosen isNotEqualTo "") then {
	GVAR(boxes) select { (_x select 1) == _chosen }
} else {
	private _medicalBoxes = _carryable select { _x select 2 };
	if (_medical && {_medicalBoxes isNotEqualTo []} && {(_medicalBoxes select (count _medicalBoxes - 1) select 0) >= _total}) then {
		_medicalBoxes
	} else {
		_carryable select { !(_x select 2) }
	};
};
if (_pool isEqualTo []) then { _pool = _carryable };
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
