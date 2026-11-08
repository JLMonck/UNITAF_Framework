#include "script_component.hpp"
/*
 * Look up which deployment this mission's ID belongs to. Clients name it and warn if its
 * date does not fit, because an old mission file can carry an ID that now means something else.
 *
 * Arguments:
 * 0: operationID <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryMission
 *
 * Public: No
 */
params ["_operationID"];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {};

private _result = parseSimpleArray ("extDB3" callExtension format["0:FETCHDATA:SELECT name, days_away FROM game_missions WHERE deployment = '%1' LIMIT 1", _operationID]);

if !((_result select 0) isEqualTo 1) exitWith {
	diag_log "extDB3: Error retrieving the deployment";
	diag_log format["Database Result: %1", _result];
};

if ((_result select 1) isEqualTo []) exitWith {
	diag_log format["UNITAF: no deployment has the ID %1. Check UNITAF_operationId in this mission.", _operationID];
	missionNamespace setVariable ['UNITAF_deploymentMissing', true, true];
};

((_result select 1) select 0) params ["_name", "_daysAway"];

if (_daysAway isEqualType "") then {
	_daysAway = parseNumber _daysAway;
};

missionNamespace setVariable ['UNITAF_deploymentName', _name, true];
missionNamespace setVariable ['UNITAF_deploymentDaysAway', _daysAway, true];
