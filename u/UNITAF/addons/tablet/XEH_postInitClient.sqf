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
waitUntil {!isNull player};
//waitUntil {alive player};

if (!isClass(configFile >> "CfgPatches" >> "ace_interact_menu")) then {
	player addAction  [
		"Open UNITAF Tablet",
		{
			_this call FUNC(openTablet);
		}
	];
};