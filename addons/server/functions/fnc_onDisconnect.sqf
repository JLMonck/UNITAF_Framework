/**
	networkId: String - user network id (see getPlayerID, allUsers)
	clientStateNumber: Number - client state number (see getClientStateNumber) - always 0
	clientState: String - client state (see getClientState) - always "NONE"
 */
params ["_networkId", "_clientStateNumber", "_clientState"];

private _userInfo = getUserInfo _networkId;
_userInfo params ["_playerID", "_ownerId", "_playerUID", "_profileName", "_displayName", "_steamName"];

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { true };

private _query = "extDB3" callExtension format["0:SETDATA:INSERT INTO connection_log SET armauid = '%1', operation = '%2', status = '%3'", _playerUID, _operationID, "disconnected"];

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