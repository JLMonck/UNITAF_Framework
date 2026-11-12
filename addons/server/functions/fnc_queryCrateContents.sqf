#include "script_component.hpp"
/*
 * Author: JLMonck
 * One crate's contents as the website publishes them (D-470), as [[class name, count], ...].
 * The site stores a crate as ["class", ["class", count], ...]: a class name with no count (a
 * faction crate written as a plain list) counts once.
 *
 * Arguments:
 * 0: Crate id <NUMBER>
 *
 * Return Value:
 * Contents, [[class name, count], ...]; empty when it cannot be read <ARRAY>
 *
 * Example:
 * [7101] call unitaf_server_fnc_queryCrateContents;
 *
 * Public: No
 */

params [["_crate", 0, [0]]];

if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { [] };

private _result = parseSimpleArray ("extDB3" callExtension format ["0:FETCHDATA:SELECT contents FROM game_crate_contents WHERE crate = '%1' LIMIT 1", floor _crate]);

if ((_result select 0) isNotEqualTo 1 || {(_result select 1) isEqualTo []}) exitWith {
	diag_log format ["extDB3: Error retrieving crate %1", _crate];
	diag_log format ["Database Result: %1", _result];
	[]
};

private _contents = (_result select 1) select 0 select 0;

(_contents apply {
	if (_x isEqualType "") then { [_x, 1] } else { [_x select 0, floor (_x select 1)] }
}) select { (_x select 0) isNotEqualTo "" && {(_x select 1) > 0} }
