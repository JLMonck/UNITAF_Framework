#include "script_component.hpp"
/*
 * Author: Katalam
 * Adds a fired event handler to the local player preventing throwing near the respawn
 * position of the local players side.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call UNITAF_common_fnc_spawnProtection;
 *
 * Public: Yes
 */

if !(QGVAR(spawnProtectionEnabled) call CBA_settings_fnc_get) exitWith {};

[typeOf player, "Fired", {
    params ["_unit", "_weapon", "", "", "", "_magazine", "_projectile"];

	private _weapons = [primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit];

	if (_unit isEqualTo player) then {
		if ([_unit] call EFUNC(tablet,canAccessORBAT)) then {
			deleteVehicle _projectile;
			if (_weapon isEqualTo "Throw") then {
				_unit addMagazine [_magazine, 1];
			};
			if (_weapon in _weapons) then {
				[player, currentWeapon player, currentMuzzle player] call ACEFUNC(safemode,lockSafety);
			};
		};
	};
}] call CBA_fnc_addClassEventHandler;
