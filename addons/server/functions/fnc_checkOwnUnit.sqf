#include "script_component.hpp"
/*
 * Author: JLMonck
 * Whether a client asked about its own unit (UNITAF tracker #202). queryPlayerData,
 * queryPlayerInventory and queryPlayerArsenal take a unit and send its ORBAT data back to it, so a
 * client naming someone else's unit would have that player's kit, group and radios put on again.
 * They are only taken for the unit of the machine that sent them. The server's own code (a
 * mission script, a module) may still name any unit, as it may call the functions directly.
 *
 * Refused: a line in the server RPT with who asked and for whom, and a hint for the sender.
 *
 * Arguments:
 * 0: The unit asked about <OBJECT>
 * 1: What was asked: "playerData", "playerInventory" or "playerArsenal" <STRING>
 *
 * Return Value:
 * Allowed <BOOL>
 *
 * Example:
 * if !([_player, "playerData"] call unitaf_server_fnc_checkOwnUnit) exitWith {};
 *
 * Public: No
 */

params [["_unit", objNull, [objNull]], ["_request", "", [""]]];

// Called on the server, not sent to it: the server's own code
if (!isRemoteExecuted) exitWith { true };

(call FUNC(requestSender)) params ["_owner", "_uid", "_name", "_sendersUnit", "_fromServer"];

// Their own unit: the engine's owner of it, or the unit the server has for that player. The
// second covers the moment after a respawn when the new body's owner may not have settled yet.
if (_fromServer || {!isNull _unit && {(owner _unit) isEqualTo _owner || {_unit isEqualTo _sendersUnit}}}) exitWith { true };

diag_log format ["UNITAF: refused %1 for %2 (%3) from %4 (%5, client %6): only for the sender's own unit", _request, name _unit, getPlayerUID _unit, _uid, _name, _owner];
[QEGVAR(ClientEvent,requestRefused), [_request], _owner] call CBA_fnc_ownerEvent;
false
