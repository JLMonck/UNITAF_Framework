#include "script_component.hpp"
/*
 * Author: JLMonck
 * The crates the website holds for this deployment (D-470): the ones its logistics people made,
 * a resupply naming the callsigns it serves, then the faction's own crates. Contents are read
 * one crate at a time when someone spawns it (queryCrateContents), so this reply stays small.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Crates, [[id, name, callsigns, faction crate], ...]; empty without the database <ARRAY>
 *
 * Example:
 * call unitaf_server_fnc_queryCrates;
 *
 * Public: No
 */

if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { [] };

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
private _result = parseSimpleArray ("extDB3" callExtension format ["0:FETCHDATA:SELECT crate, name, callsign, faction_crate FROM game_crates WHERE deployment = '%1' ORDER BY faction_crate, callsign, name", _operationID]);

if ((_result select 0) isNotEqualTo 1) exitWith {
	diag_log "extDB3: Error retrieving the deployment's crates";
	diag_log format ["Database Result: %1", _result];
	[]
};

_result select 1
