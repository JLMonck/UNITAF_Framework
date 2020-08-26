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

waitUntil {isPlayer player};

/**
 * TEMP !!!
 * Needs to be replaced by UNITAF Menu
 */
if (!isClass(configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	player addAction  [
		"Open UNITAF Manager",
		{
			createDialog QGVAR(GUI);
		}
	];
};