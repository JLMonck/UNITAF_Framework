#include "script_component.hpp"
/*
 * Author: JLMonck
 * What the website lets a player do on this deployment, from the same game_players row the
 * tablet reads (queryPlayerData): a Logistics role, a website admin, a Zeus. Read each time a
 * client asks for something only some may do (clientRequest, UNITAF tracker #199), so a change
 * on the website counts at once.
 *
 * Arguments:
 * 0: Player UID (Steam64) <STRING>
 *
 * Return Value:
 * [Logistics, admin, Zeus] <ARRAY of BOOL>; all false without the database or a row
 *
 * Example:
 * ["76561198000000000"] call unitaf_server_fnc_queryPlayerRights;
 *
 * Public: No
 */

params [["_playerUID", "", [""]]];

// A mission without the database: the test player queryPlayerData hands out, Logistics only
if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { [true, false, false] };

if (_playerUID isEqualTo "" || {!(missionNamespace getVariable ['UNITAF_databaseAvailable', false])}) exitWith { [false, false, false] };

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
private _result = parseSimpleArray ("extDB3" callExtension format ["0:FETCHDATA:SELECT is_logistics, playerAdmin, is_zeus FROM game_players WHERE armauid = '%1' AND deployment = '%2' ORDER BY is_home DESC LIMIT 1", _playerUID, _operationID]);

if ((_result param [0, 0]) isNotEqualTo 1) exitWith {
	diag_log format ["extDB3: Error retrieving the rights of %1", _playerUID];
	diag_log format ["Database Result: %1", _result];
	[false, false, false]
};

// Compared as the tablet compares them (fnc_openTabletMain, fnc_setPlayerData)
((_result select 1) param [0, []]) params [["_isLogistics", 0], ["_isAdmin", 0], ["_isZeus", 0]];
[_isLogistics isEqualTo 1, _isAdmin isEqualTo 1, _isZeus isEqualTo 1]
