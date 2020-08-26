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

/**
 * Set Event Handlers
 */
["UNITAF_ClientEvent_PlayerInventory", {
	_this call FUNC(setInventory);
}] call CBA_fnc_addEventHandler;

["UNITAF_ClientEvent_PlayerData", {
	_this call FUNC(setPlayerData);
}] call CBA_fnc_addEventHandler;

["UNITAF_ClientEvent_PlayerArsenal", {
	_this call FUNC(setArsenal);
}] call CBA_fnc_addEventHandler;