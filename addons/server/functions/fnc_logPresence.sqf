#include "script_component.hpp"
/*
 * Author: JLMonck
 * Write who is on the server right now to the website, so the ORBAT can show who is connected
 * and ENDEX can suggest no-shows, late joiners and time away. The same minute also records how
 * the session ran: each player's FPS, ping and desync, and the server's and each headless
 * client's FPS and AI count.
 *
 * Runs on the server once a minute from a per-frame handler (see XEH_postInitServer). The
 * connect/disconnect events alone cannot do this: a mission restart fires no connect for
 * players already on, and a crash fires no disconnect, so the site reads these snapshots.
 *
 * Performance:
 * - Server only. Nothing is broadcast, so clients and JIP never see it.
 * - Nothing new crosses the network: player and headless FPS are values the server already
 *   receives (clients send PlayerFPS to the server only, every 5s by default; headless HCFPS);
 *   ping and desync come from getUserInfo.
 * - Async extDB3 ("1:"): each insert is queued on extDB3's worker thread and the call returns
 *   at once, so a slow or unreachable database never stalls the mission.
 * - Two inserts a minute (players, machines), the players split only if a very large session
 *   would make the message too long for extDB3.
 * - Times come from the database (seen_at defaults to now), never from the game.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Number of players written <NUMBER>
 *
 * Example:
 * call unitaf_server_fnc_logPresence;
 *
 * Public: No
 */

if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { 0 };

// Nothing that could break out of an SQL string or an extDB3 message gets through
private _clean = { ((_this splitString "'""\:") joinString "") select [0, 140] };
private _orNull = { if (_this < 0) then { "NULL" } else { str (floor _this) } };

private _operationID = (str (missionNamespace getVariable ['UNITAF_operationID', 0])) call _clean;
if (_operationID in ["", "0"]) exitWith { 0 };

// AI per machine, by owner id (the server is 2), counted once
private _aiByOwner = createHashMap;
{
	private _owner = owner _x;
	_aiByOwner set [_owner, (_aiByOwner getOrDefault [_owner, 0]) + 1];
} forEach (allUnits - allPlayers);

private _players = [];
private _machines = [];
{
	(getUserInfo _x) params ["", ["_ownerId", 0], ["_playerUID", ""], "", "", "", "", ["_isHC", false, [false]], "", ["_network", [], [[]]], ["_unit", objNull, [objNull]]];
	_network params [["_ping", -1], "", ["_desync", -1]];

	if (_isHC) then {
		private _hcName = name _unit;
		private _hcFPS = missionNamespace getVariable [format ["%1_%2", QEGVAR(headless,HCFPS), _hcName], -1];
		_machines pushBack format ["('%1','%2',%3,NULL,%4,NULL)", _hcName call _clean, _operationID, _hcFPS call _orNull, _aiByOwner getOrDefault [_ownerId, 0]];
	} else {
		// Real players only: no server, and Steam ids are digits only
		if (_playerUID isNotEqualTo "" && {(_playerUID regexMatch "^[0-9]+$")}) then {
			private _fps = if (isNull _unit) then { -1 } else { _unit getVariable [QEGVAR(client,PlayerFPS), -1] };
			_players pushBack format ["('%1','%2',%3,%4,%5)", _playerUID, _operationID, _fps call _orNull, _ping call _orNull, _desync call _orNull];
		};
	};
} forEach allUsers;

// The server: its FPS now, and its lowest since the last snapshot (kept by the 5s FPS handler)
private _serverMin = missionNamespace getVariable [QGVAR(ServerFPSMin), diag_fpsMin];
missionNamespace setVariable [QGVAR(ServerFPSMin), nil];
_machines pushBack format ["('server','%1',%2,%3,%4,%5)", _operationID, diag_fps call _orNull, _serverMin call _orNull, _aiByOwner getOrDefault [2, 0], count _players];

private _insert = {
	params ["_sql"];
	private _result = parseSimpleArray ("extDB3" callExtension ("1:SETDATA:" + _sql));
	if ((_result select 0) isNotEqualTo 1) then {
		diag_log "extDB3: Error inserting presence snapshot";
		diag_log format ["Database Result: %1", _result];
	};
};

// About 60 characters a player; keep each message well inside extDB3's limit
private _perInsert = 120;
for "_i" from 0 to (count _players - 1) step _perInsert do {
	[format ["INSERT INTO game_presence (game_user_id, event_reference, fps, ping, desync) VALUES %1", (_players select [_i, _perInsert]) joinString ","]] call _insert;
};

[format ["INSERT INTO game_server_frames (machine, event_reference, fps, fps_min, ai_units, players) VALUES %1", _machines joinString ","]] call _insert;

count _players
