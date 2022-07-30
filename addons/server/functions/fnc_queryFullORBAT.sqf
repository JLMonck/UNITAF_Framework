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
private _query = "[0, [""not implemented""]]"; //"extDB3" callExtension format["0:FETCHDATA:SELECT * FROM test", _operationID];
private _result = parseSimpleArray (_query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving ORBAT";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		//[QEGVAR(ServerEvent,setFullORBAT), (_result select 1 select 0)] call CBA_fnc_serverEvent;
	};
	default {
		diag_log "extDB3: Something went wrong with ORBAT";
		diag_log format["Database Result: %1", _result];
	};
};

