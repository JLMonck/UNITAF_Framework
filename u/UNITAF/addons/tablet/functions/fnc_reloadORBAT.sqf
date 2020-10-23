#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Requests an update of the ORBAT
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

 // get Full ORBAT
_operationId = missionNamespace getVariable ['UNITAF_operationID', 0];

[QEGVAR(ServerEvent,getFullORBAT), [_operationId]] call CBA_fnc_serverEvent;