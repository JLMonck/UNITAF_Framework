#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve callsigns from ORBAT
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

// _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
// _playerUID = getPlayerUID _player;

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ServerEvent,ORBATGroups), [
		(parseSimpleArray "[1, [[1,""MONTY"",""WEST""]]]")  select 1
	]] call CBA_fnc_serverEvent;	
};

// Must return: <ID>, <CALLSIGN>, <SIDE>
private _query = "extDB3" callExtension format["0:FETCHDATA:SELECT ol.unit, CONCAT(oc.callsign,' ',u.append) as callsign, 'WEST' as side FROM operation_layout ol LEFT JOIN operation_unit_callsigns olc ON olc.unit = ol.unit LEFT JOIN operation_callsigns oc ON oc.id = olc.callsign LEFT JOIN units u ON u.id = ol.unit LEFT JOIN users us ON us.id = ol.user WHERE ol.operation = '%1' AND olc.operation = ol.operation GROUP BY ol.unit", _operationID];
//private _query = "extDB3" callExtension format["0:FETCHDATA:SELECT unit, callsign, side FROM operation_layout operation = '%1' GROUP BY unit", _operationID];
private _result = parseSimpleArray (_query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving ORBAT Groups";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		[QEGVAR(ServerEvent,ORBATGroups), (_result select 1)] call CBA_fnc_serverEvent;
	};
	default {
		diag_log "extDB3: Something went wrong with Player Arsenal";
		diag_log format["Database Result: %1", _result];
	};
};

