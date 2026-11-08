/**
	networkId: String - user network id (see getPlayerID, allUsers)
	clientStateNumber: Number - client state number (see getClientStateNumber) - always 0
	clientState: String - client state (see getClientState) - always "NONE"
 */
params ["_networkId", "_clientStateNumber", "_clientState"];

private _userInfo = getUserInfo _networkId;
_userInfo params ["_playerID", "_ownerId", "_playerUID", "_profileName", "_displayName", "_steamName", "_userState", ["_isHC", false, [false]]];

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { true };

// Only log real players, and only once the database has been set up for this mission
if (_isHC || {_playerUID isEqualTo ""}) exitWith { true };
if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { true };

private _query = "extDB3" callExtension format["1:SETDATA:INSERT INTO game_connections SET game_user_id = '%1', event_reference = '%2', status = '%3'", _playerUID, _operationID, "disconnected"];

private _result = (parseSimpleArray _query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error inserting connection status";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		// ignore "first" result
		// no actions needed
	};
	default {
		diag_log "extDB3: Something went wrong with inserting connection status";
		diag_log format["Database Result: %1", _result];
	};
};