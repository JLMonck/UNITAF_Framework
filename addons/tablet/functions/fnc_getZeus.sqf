#include "script_component.hpp"
/**
 * Author: Grezvany13
 * local function to trigger 'addToCurator' serverside
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */
params ["_player"];

[QEGVAR(ServerEvent,addToCurator), [_player]] call CBA_fnc_serverEvent;