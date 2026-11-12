#include "script_component.hpp"
/*
 * Author: JLMonck
 * Spawn a crate's boxes side by side and fill them, as packSupplies decided. Each item goes in
 * with the command for what it is (magazine, weapon, backpack or item), so nothing is dropped.
 * Run where the boxes should be created: the server, or Zeus's own machine (global commands).
 *
 * Arguments:
 * 0: Position ASL, so a box ordered on a deck or an upper floor stays there <ARRAY>
 * 1: Boxes, from packSupplies <ARRAY>
 *
 * Return Value:
 * The boxes created <ARRAY>
 *
 * Example:
 * [getPos player, [["unitaf_logistics_MetalCase_500", [["ACE_fieldDressing", 40]]]]] call unitaf_logistics_fnc_spawnSupplies;
 *
 * Public: No
 */

params [["_position", [0, 0, 0], [[]]], ["_boxes", [], [[]]]];

private _created = [];
{
	_x params ["_type", "_contents"];

	// Side by side, two metres apart, so boxes of one request never land inside each other; at the
	// asked-for height (ASL), so a deck or an upper floor keeps them rather than the ground beneath
	private _at = _position vectorAdd [2 * _forEachIndex, 0, 0];
	private _container = createVehicle [_type, ASLToATL _at, [], 0, "CAN_COLLIDE"];
	_container setPosASL _at;

	clearItemCargoGlobal _container;
	clearWeaponCargoGlobal _container;
	clearMagazineCargoGlobal _container;
	clearBackpackCargoGlobal _container;

	{
		_x params ["_class", "_count"];
		switch (true) do {
			case (isClass (configFile >> "CfgMagazines" >> _class)): {
				_container addMagazineCargoGlobal [_class, _count];
			};
			case (isClass (configFile >> "CfgVehicles" >> _class)): {
				_container addBackpackCargoGlobal [_class, _count];
			};
			case ((getNumber (configFile >> "CfgWeapons" >> _class >> "type")) in [1, 2, 4, 4096]): {
				_container addWeaponCargoGlobal [_class, _count];
			};
			case (isClass (configFile >> "CfgWeapons" >> _class) || {isClass (configFile >> "CfgGlasses" >> _class)}): {
				_container addItemCargoGlobal [_class, _count];
			};
			default {
				// Not in this game: a crate from the website can name a mod this server does not load
				diag_log format ["UNITAF logistics: %1 is not in this game; left out of the box", _class];
			};
		};
	} forEach _contents;

	_created pushBack _container;
} forEach _boxes;

_created
