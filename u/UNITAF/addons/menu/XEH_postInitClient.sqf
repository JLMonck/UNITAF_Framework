#include "script_component.hpp"
/**
 * Author: Grezvany13
 * XEH postInitClient
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

if !(hasInterface) exitWith {};
waitUntil { alive player && ! isNull player };

if (!isClass(configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	player addAction  [
		"Open UNITAF Menu",
		{
			createDialog QGVAR(GUI);
		}
	];
};