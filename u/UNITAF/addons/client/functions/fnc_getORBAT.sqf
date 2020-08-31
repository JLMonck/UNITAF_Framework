#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Request ORBAT Data from database
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call unitaf_client_fnc_getORBAT;
 *
 * Public: Yes
 */
params ["_player"];

[QEGVAR(ServerEvent,queryPlayerData), [_player]] call CBA_fnc_serverEvent;
[QEGVAR(ServerEvent,queryPlayerInventory), [_player]] call CBA_fnc_serverEvent;
[QEGVAR(ServerEvent,queryPlayerArsenal), [_player]] call CBA_fnc_serverEvent;
