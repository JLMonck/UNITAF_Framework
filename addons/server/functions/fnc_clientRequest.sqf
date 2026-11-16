#include "script_component.hpp"
/*
 * Author: JLMonck
 * A client asks for something only some players may do (UNITAF tracker #199, #202): the crates of
 * the tablet's Logistics page and Zeus's "Request logistics", Zeus for oneself, and ENDEX. Clients
 * call it with remoteExecCall on the server (2), so the engine says which machine sent it; a CBA
 * event does not, and through one any client could list or spawn crates, make anyone Zeus, or
 * call ENDEX on everyone.
 *
 * Who may (the website's rights are the sender's game_players row for this deployment):
 *	- Crates (listCrates, crateContents, spawnCrate): whom the tablet shows Logistics to, a
 *	  Logistics role or a website admin on this deployment's ORBAT, or an admin logged in on the
 *	  server; and whoever is Zeus, who can place any box from Zeus already.
 *	- Zeus (addToCurator): whom the client asks it for, a Zeus on the ORBAT while automatic Zeus
 *	  is on, or an admin as above (the tablet's Admin page). Always for the sender's own unit.
 *	- ENDEX (callENDEX): whom the tablet's Admin page is for, a website admin (a leadership role
 *	  such as the Field Leader, or whoever holds "Admin in game everywhere", the platform operator
 *	  among them) or an admin logged in on the server; and a Zeus, on the ORBAT or assigned now.
 * A website admin is playerAdmin in game_players, which the platform operator always has on a
 * deployment they are slotted on (site D-508), so none of these checks keeps them out.
 * Anyone else is refused: a line in the server RPT, and a hint on their screen.
 *
 * Arguments:
 * 0: What: "listCrates", "crateContents", "spawnCrate", "addToCurator" or "callENDEX" <STRING>
 * 1: Its arguments <ARRAY>
 *	- listCrates: [position, reply event (default unitaf_ClientEvent_crateList)]
 *	- crateContents: [crate id, reply event]
 *	- spawnCrate: spawnCrate's own [choice, box, full arsenal, position ASL]
 *	- addToCurator: []
 *	- callENDEX: []
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

(call FUNC(requestSender)) params ["_owner", "_uid", "_name", "_unit", "_fromServer"];

private _isCrates = _request in ["listCrates", "crateContents", "spawnCrate"];
private _allowed = _fromServer;
if (!_allowed && {_isCrates || {_request in ["addToCurator", "callENDEX"]}}) then {
	([_uid] call FUNC(queryPlayerRights)) params ["_isLogistics", "_isSiteAdmin", "_isZeus"];
	// An admin as the tablet has it: on the ORBAT, or logged in on the server
	private _isAdmin = _isSiteAdmin || {(admin _owner) isEqualTo 2};
	private _isZeusNow = !isNull _unit && {!isNull (getAssignedCuratorLogic _unit)};
	_allowed = switch (true) do {
		case (_isCrates): { _isLogistics || {_isAdmin} || {_isZeusNow} };
		case (_request isEqualTo "addToCurator"): { !isNull _unit && {_isAdmin || {_isZeus && {QGVAR(Zeus_autoZeus) call CBA_settings_fnc_get}}} };
		case (_request isEqualTo "callENDEX"): { _isAdmin || {_isZeus} || {_isZeusNow} };
		default { false };
	};
};

if !(_allowed) exitWith {
	private _reason = switch (true) do {
		case (_isCrates): { "not Logistics, an admin or Zeus on this deployment" };
		case (_request isEqualTo "addToCurator"): { "not a Zeus on this deployment's ORBAT (with automatic Zeus on) or an admin" };
		case (_request isEqualTo "callENDEX"): { "not an admin (Field Leader, a leadership role with the game's admin tools, the platform operator, or logged in) or a Zeus on this deployment" };
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
	case "callENDEX": {
		diag_log format ["UNITAF: ENDEX called by %1 (%2, client %3)", _uid, _name, _owner];
		call FUNC(callENDEX);
	};
};
