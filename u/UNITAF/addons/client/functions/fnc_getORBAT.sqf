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

["UNITAF_ServerEvent_queryPlayerData", [_player]] call CBA_fnc_serverEvent;
["UNITAF_ServerEvent_queryPlayerInventory", [_player]] call CBA_fnc_serverEvent;
["UNITAF_ServerEvent_queryPlayerArsenal", [_player]] call CBA_fnc_serverEvent;
