/**
	networkId: String - user network id (see getPlayerID, allUsers)
	kickTypeNumber: Number - kick type number (see above)
	kickType: String - kick type (see above)
	kickReason: String - reason given for the kick by the admin or by other means
	kickMessageIncReason: String - formatted engine message including the given reason

	The possible values for 'kickTypeNumber' and 'kickType' are:
	0 : "TIMEOUT",
	1 : "DISCONNECTED",
	2 : "KICKED",
	3 : "BANNED",
	4 : "MISSING ADDON",
	5 : "BAD CD KEY",
	6 : "CD KEY IN USE",
	7 : "SESSION LOCKED",
	8 : "BATTLEYE",
	9 : "STEAM CHECK",
	10 : "DLC CONTENT",
	11 : "GS TIMEOUT",
	12 : "SCRIPT",
	13 : "OTHER"
 */
params ["_networkId", "_kickTypeNumber", "_kickType", "_kickReason", "_kickMessageIncReason"];

private _userInfo = getUserInfo _networkId;
_userInfo params ["_playerID", "_ownerId", "_playerUID", "_profileName", "_displayName", "_steamName"];

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { true };

private _query = "extDB3" callExtension format["0:SETDATA:INSERT INTO connection_log SET armauid = '%1', operation = '%2', status = '%3', reason = '%3'", _playerUID, _operationID, 'kicked', _kickType];

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