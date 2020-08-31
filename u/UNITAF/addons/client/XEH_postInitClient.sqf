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
[QEGVAR(ClientEvent,PlayerInventory), {
	_this call FUNC(setInventory);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ClientEvent,PlayerData), {
	_this call FUNC(setPlayerData);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ClientEvent,PlayerArsenal), {
	_this call FUNC(setArsenal);
}] call CBA_fnc_addEventHandler;