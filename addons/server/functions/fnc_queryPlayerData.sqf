#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve Player Data from ORBAT
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Clients ask with remoteExecCall to the server, for their own unit only (UNITAF tracker #202);
 * the reply goes to that unit's machine by remoteExecCall of unitaf_client_fnc_setPlayerData.
 *
 * Example:
 * [player] remoteExecCall ["unitaf_server_fnc_queryPlayerData", 2];
 *
 * Public: No
 */
params [["_player", objNull, [objNull]]];

if (!isServer || {isNull _player}) exitWith {};
if !([_player, "playerData"] call FUNC(checkOwnUnit)) exitWith {};

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
private _playerUID = getPlayerUID _player;

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	_query = "[1, [[12345678,"""",0,""rp1"",0,0,2,1,1,""REAPER"",251,""RED"",50,""PRIVATE"",""Fireteam Leader"",""Capt James"",0,0,1,1]]]";
	_result = (parseSimpleArray _query);
	(_result select 1) remoteExecCall [QEFUNC(client,setPlayerData), _player];
};

if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith {
	[QEGVAR(ClientEvent,PlayerDataFailed), ["database"], [_player]] call CBA_fnc_targetEvent;
};

if (missionNamespace getVariable ['UNITAF_deploymentMissing', false]) exitWith {
	[QEGVAR(ClientEvent,PlayerDataFailed), ["wrong_id"], [_player]] call CBA_fnc_targetEvent;
};

private _query = "extDB3" callExtension format["0:FETCHDATA:SELECT armauid, playerRank, playerAdmin, playerPos, playerDir, operation, is_medic_level, is_engineer_level, unit, callsign, freq, buddy, lr_freq, armarank, role, leader, is_zeus, is_eod, is_logistics, is_reporter, traits FROM game_players WHERE armauid = '%1' AND deployment = '%2' ORDER BY is_home DESC LIMIT 1", _playerUID, _operationID];

private _result = (parseSimpleArray _query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving Player Data";
		 diag_log format["Database Error: %1", (_result select 1)];
		[QEGVAR(ClientEvent,PlayerDataFailed), ["database"], [_player]] call CBA_fnc_targetEvent;
	};
	case 1: {
		if ((_result select 1) isEqualTo []) exitWith {
			// Nothing for this player: say whether the site knows them at all
			private _known = parseSimpleArray ("extDB3" callExtension format["0:FETCHDATA:SELECT armauid FROM game_known_players WHERE armauid = '%1' LIMIT 1", _playerUID]);
			private _reason = ["not_linked", "not_slotted"] select ((_known select 0) isEqualTo 1 && {!((_known select 1) isEqualTo [])});
			[QEGVAR(ClientEvent,PlayerDataFailed), [_reason], [_player]] call CBA_fnc_targetEvent;
		};
		// ignore "first" result
		(_result select 1) remoteExecCall [QEFUNC(client,setPlayerData), _player];
	};
	default {
		diag_log "extDB3: Something went wrong with Player Data";
		diag_log format["Database Result: %1", _result];
		[QEGVAR(ClientEvent,PlayerDataFailed), ["database"], [_player]] call CBA_fnc_targetEvent;
	};
};
