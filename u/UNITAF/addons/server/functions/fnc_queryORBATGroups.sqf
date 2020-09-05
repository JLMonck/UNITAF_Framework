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

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ServerEvent,ORBATGroups), [
		(parseSimpleArray "[1, [[1,""MONTY"",""WEST""]]]")  select 1
	]] call CBA_fnc_serverEvent;	
};

// Must return: <ID>, <CALLSIGN>, <SIDE>
_ORBATGroups = "extDB3" callExtension format["0:FETCHDATA:SELECT ol.unit, CONCAT(oc.callsign,' ',u.append) as callsign, 'WEST' as side FROM operation_layout ol LEFT JOIN operation_unit_callsigns olc ON olc.unit = ol.unit LEFT JOIN operation_callsigns oc ON oc.id = olc.callsign LEFT JOIN units u ON u.id = ol.unit LEFT JOIN users us ON us.id = ol.user
WHERE ol.operation = '%1' AND olc.operation = ol.operation GROUP BY ol.unit", _operationID];

if (!(parseSimpleArray (_ORBATGroups)  select 0 isEqualTo 1)) exitWith { diag_log "extDB3: Error retrieving ORBAT Groups"; };

[QEGVAR(ServerEvent,ORBATGroups), [parseSimpleArray (_ORBATGroups) select 1]] call CBA_fnc_serverEvent;

