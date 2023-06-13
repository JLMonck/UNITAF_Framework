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

// lets reset everything just to be sure
_player setVariable [QGVAR(hasInventory), false, true];
_player setVariable [QGVAR(defaultInventory), [], true];
_player setVariable [QGVAR(hasUserData), false, true];
_player setVariable [QGVAR(userData), [], true];
_player setVariable [QGVAR(hasGroup), false, true];

[QEGVAR(ServerEvent,queryPlayerData), [_player]] call CBA_fnc_serverEvent;
[QEGVAR(ServerEvent,queryPlayerInventory), [_player]] call CBA_fnc_serverEvent;
[QEGVAR(ServerEvent,queryPlayerArsenal), [_player]] call CBA_fnc_serverEvent;
