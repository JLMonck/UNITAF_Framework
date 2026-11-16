#include "script_component.hpp"
/*
 * Author: JLMonck
 * Who sent the remote execution the server is running now: the machine the engine says it came
 * from (remoteExecutedOwner), and that machine's player, from the server's own list of who is
 * connected. A CBA event does not say who sent it, so whatever only some may ask for comes in by
 * remoteExecCall and asks this first (UNITAF tracker #199, #202).
 *
 * Arguments:
 * None
 *
 * Return Value:
 * [machine <NUMBER>, UID <STRING>, name <STRING>, unit <OBJECT>, from the server itself <BOOL>]
 *
 * Example:
 * (call unitaf_server_fnc_requestSender) params ["_owner", "_uid", "_name", "_unit", "_fromServer"];
 *
 * Public: No
 */

// Run on the server itself (single player, a host's own client, or server code), that is this machine
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

[_owner, _uid, _name, _unit, _fromServer]
