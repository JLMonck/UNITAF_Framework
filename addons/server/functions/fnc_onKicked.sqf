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
_userInfo params ["_playerID", "_ownerId", "_playerUID", "_profileName", "_displayName", "_steamName", "_userState", ["_isHC", false, [false]]];

private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { true };

// Only log real players, and only once the database has been set up for this mission
if (_isHC || {_playerUID isEqualTo ""}) exitWith { true };
if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { true };

// The reason is free text, so nothing that could break out of the SQL string gets through
private _reason = format ["%1: %2", _kickType, ((_kickReason splitString "'""\") joinString "") select [0, 130]];

private _query = "extDB3" callExtension format["1:SETDATA:INSERT INTO game_connections SET game_user_id = '%1', event_reference = '%2', status = '%3', reason = '%4'", _playerUID, _operationID, 'kicked', _reason];

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