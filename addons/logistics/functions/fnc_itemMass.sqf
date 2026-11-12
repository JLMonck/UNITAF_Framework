#include "script_component.hpp"
/*
 * Author: JLMonck
 * How much an item weighs in a box, in the game's load units (the same units as a
 * container's maximumLoad). Works on any machine: it reads the config, not the tablet's
 * client-side item lists.
 *
 * Arguments:
 * 0: Class name <STRING>
 *
 * Return Value:
 * Mass <NUMBER>
 *
 * Example:
 * ["ACE_fieldDressing"] call unitaf_logistics_fnc_itemMass;
 *
 * Public: No
 */

params [["_class", "", [""]]];

private _config = configFile >> "CfgMagazines" >> _class;
if (isClass _config) exitWith { getNumber (_config >> "mass") };

_config = configFile >> "CfgWeapons" >> _class;
if (isClass _config) exitWith {
	// Weapons and binoculars carry their mass in WeaponSlotsInfo; everything else in ItemInfo
	if ((getNumber (_config >> "type")) in [1, 2, 4, 4096]) then {
		getNumber (_config >> "WeaponSlotsInfo" >> "mass")
	} else {
		getNumber (_config >> "ItemInfo" >> "mass")
	};
};

_config = configFile >> "CfgVehicles" >> _class;
if (isClass _config) exitWith { getNumber (_config >> "mass") };

_config = configFile >> "CfgGlasses" >> _class;
if (isClass _config) exitWith { getNumber (_config >> "mass") };

0
