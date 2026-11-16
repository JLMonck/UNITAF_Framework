#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Set player inventory based on ORBAT
 *
 * Arguments:
 * 0: inventory <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

// Sent by the server's queryPlayerInventory with remoteExecCall; taken from nobody else (UNITAF tracker #202)
if (isRemoteExecuted && {remoteExecutedOwner isNotEqualTo 2}) exitWith {
	diag_log format ["UNITAF: ignored a loadout from client %1: only the server sends it", remoteExecutedOwner];
};

params [["_inventoryData", [], [[]]]];

[_inventoryData] spawn {
	params [["_inventory", [], [[]]]];

	// set loadout
	player setUnitLoadout (configFile >> "EmptyLoadout"); // first, remove everything!
	player setUnitLoadout _inventory;

	if (isClass(configFile >> "CfgPatches" >> "ace_safemode")) then {
		sleep 0.1;	// need to wait a frame to ensure the player exists and has an actual weapon
		// Set (active) weapon to Safe
		[player, currentWeapon player, true] call ace_safemode_fnc_setWeaponSafety;
	};

	player setVariable [QGVAR(hasInventory), true, true];
	player setVariable [QGVAR(defaultInventory), _inventory];
};