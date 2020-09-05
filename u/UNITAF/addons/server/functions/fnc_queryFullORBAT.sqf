#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve full ORBAT
 *
 * Arguments:
 * 0: operationID <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryFullORBAT
 *
 * Public: No
 */

params ["_operationID"];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ServerEvent,setFullORBAT), [
		(parseSimpleArray "[1, [[1,""MONTY"",""WEST""]]]")  select 1
	]] call CBA_fnc_serverEvent;	
};

// Must return: <ID>, <CALLSIGN>, <SIDE>
_ORBAT = "extDB3" callExtension format["0:FETCHDATA:SELECT * FROM table WHERE 1 = %1", _operationID];

if (!(parseSimpleArray (_ORBAT)  select 0 isEqualTo 1)) exitWith { diag_log "extDB3: Error retrieving ORBAT"; };

[QEGVAR(ServerEvent,setFullORBAT), [parseSimpleArray (_ORBAT) select 1]] call CBA_fnc_serverEvent;

