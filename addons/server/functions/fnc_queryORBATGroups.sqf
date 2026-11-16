#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve callsigns from ORBAT
 *
 * extDB3 answers [1, [[unit, "CALLSIGN", "SIDE"], [unit, "CALLSIGN", "SIDE"], ...]]: the rows,
 * one per element with a place on the ORBAT (game_groups). setORBATGroups takes the whole list
 * as its one argument, so it is passed as [rows]. Until 2.6.2 the rows were passed bare, so
 * setORBATGroups read only the first row, as if it were the list, and made no callsign group
 * at all (UNITAF tracker #202).
 *
 * Arguments:
 * 0: operationID <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryORBATGroups
 *
 * Public: No
 */

params ["_operationID"];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	// Called here on the server, no longer as a CBA server event any client could send (2.6.1)
	[
		(parseSimpleArray "[1, [[1,""MONTY"",""WEST""],[2,""REAPER 1-1"",""WEST""]]]") select 1
	] call FUNC(setORBATGroups);
};

// Must return: <ID>, <CALLSIGN>, <SIDE>
private _query = "extDB3" callExtension format["0:FETCHDATA:SELECT unit, callsign, side FROM game_groups WHERE deployment = '%1'", _operationID];

private _result = parseSimpleArray (_query);

switch (_result param [0, -1]) do {
	case 0: {
		 diag_log "extDB3: Error retrieving ORBAT Groups";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		// the list of rows is the one argument (2.6.2)
		[_result select 1] call FUNC(setORBATGroups);
	};
	default {
		diag_log "extDB3: Something went wrong with ORBAT Groups";
		diag_log format["Database Result: %1", _query];
	};
};
