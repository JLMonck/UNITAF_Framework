#include "script_component.hpp"
/*
 * Author: JLMonck
 * A client asks for something only some players may do (UNITAF tracker #199): the crates of the
 * tablet's Logistics page and Zeus's "Request logistics", and Zeus for oneself. Clients call it
 * with remoteExecCall on the server (2), so the engine says which machine sent it; a CBA server
 * event does not, and through one any client could list or spawn crates or make anyone Zeus.
 *
 * Who may:
 *	- Crates (listCrates, crateContents, spawnCrate): whom the tablet shows Logistics to, a
 *	  Logistics role or a website admin on this deployment's ORBAT (game_players), or an admin
 *	  logged in on the server; and whoever is Zeus, who can place any box from Zeus already.
 *	- Zeus (addToCurator): whom the client asks it for, a Zeus on the ORBAT while automatic Zeus
 *	  is on, or an admin as above (the tablet's Admin page). Always for the sender's own unit.
 * Anyone else is refused: a line in the server RPT, and a hint on their screen.
 *
 * Arguments:
 * 0: What: "listCrates", "crateContents", "spawnCrate" or "addToCurator" <STRING>
 * 1: Its arguments <ARRAY>
 *	- listCrates: [position, reply event (default unitaf_ClientEvent_crateList)]
 *	- crateContents: [crate id, reply event]
 *	- spawnCrate: spawnCrate's own [choice, box, full arsenal, position ASL]
 *	- addToCurator: []
 *
 * Return Value:
 * None
 *
 * Example:
 * ["listCrates", [getPosATL player]] remoteExecCall ["unitaf_server_fnc_clientRequest", 2];
 *
 * Public: No
 */

params [["_request", "", [""]], ["_arguments", [], [[]]]];

if (!isServer) exitWith {};

// Who sent it: the machine the engine says it came from. Run on the server itself (single
// player, a host's own client, or server code), that is this machine.
private _owner = remoteExecutedOwner;
if (!isMultiplayer || {!isRemoteExecuted} || {_owner isEqualTo 0}) then {
	_owner = clientOwner;
};
// A dedicated server's own code, or single player: nobody else to keep out
private _fromServer = !isMultiplayer || {_owner isEqualTo clientOwner && {!hasInterface}};

// The sender's UID, name and unit, from the server's own list of who is connected
private _user = [];
{
	private _info = getUserInfo _x;
	if ((_info param [1, -1]) isEqualTo _owner) exitWith { _user = _info; };
} forEach allUsers;
_user params ["", "", ["_uid", "", [""]], ["_name", "", [""]], "", "", "", "", "", "", ["_unit", objNull, [objNull]]];
if (!isMultiplayer) then {
	_uid = getPlayerUID player;
	_name = profileName;
	_unit = player;
};
if (isNull _unit) then {
	private _index = allPlayers findIf { owner _x isEqualTo _owner };
	if (_index > -1) then { _unit = allPlayers select _index; };
};

private _isCrates = _request in ["listCrates", "crateContents", "spawnCrate"];
private _allowed = _fromServer;
if (!_allowed && {_isCrates || {_request isEqualTo "addToCurator"}}) then {
	([_uid] call FUNC(queryPlayerRights)) params ["_isLogistics", "_isSiteAdmin", "_isZeus"];
	// An admin as the tablet has it: on the ORBAT, or logged in on the server
	private _isAdmin = _isSiteAdmin || {(admin _owner) isEqualTo 2};
	_allowed = if (_isCrates) then {
		_isLogistics || {_isAdmin} || {!isNull (getAssignedCuratorLogic _unit)}
	} else {
		!isNull _unit && {_isAdmin || {_isZeus && {QGVAR(Zeus_autoZeus) call CBA_settings_fnc_get}}}
	};
};

if !(_allowed) exitWith {
	private _reason = switch (true) do {
		case (_isCrates): { "not Logistics, an admin or Zeus on this deployment" };
		case (_request isEqualTo "addToCurator"): { "not a Zeus on this deployment's ORBAT (with automatic Zeus on) or an admin" };
		default { "not a request the server takes" };
	};
	diag_log format ["UNITAF: refused %1 %2 from %3 (%4, client %5): %6", _request, _arguments, _uid, _name, _owner, _reason];
	[QEGVAR(ClientEvent,requestRefused), [_request], _owner] call CBA_fnc_ownerEvent;
};

switch (_request) do {
	case "listCrates": {
		_arguments params [["_position", [0, 0, 0], [[]]], ["_reply", QEGVAR(ClientEvent,crateList), [""]]];
		[_reply, [_position, call FUNC(queryCrates)], _owner] call CBA_fnc_ownerEvent;
	};
	case "crateContents": {
		_arguments params [["_crate", 0, [0]], ["_reply", "", [""]]];
		if (_reply isEqualTo "") exitWith {};
		[_reply, [_crate, [_crate] call FUNC(queryCrateContents)], _owner] call CBA_fnc_ownerEvent;
	};
	case "spawnCrate": {
		_arguments call FUNC(spawnCrate);
	};
	case "addToCurator": {
		if (isNull _unit) exitWith {};
		[_unit] call FUNC(makeCurator);
	};
};
