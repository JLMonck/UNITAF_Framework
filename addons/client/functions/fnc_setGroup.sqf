#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Set Group based on ORBAT
 *
 * Joins the group with the player's callsign, on the player's own side: the one the server made
 * at mission start (unitaf_server_fnc_setORBATGroups), or the mission's own. A group on another
 * side is never joined, as joining it would change the player's side. When there is none (the
 * server could not make it, or the engine removed it), the player makes it, so a callsign group
 * always exists for whoever comes after (UNITAF tracker #202).
 *
 * Arguments:
 * 0: player <OBJECT>
 * 1: callsign <STRING>
 * 2: teamColour <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, "REAPER 1-1", "RED"] call unitaf_client_fnc_setGroup;
 *
 * Public: No
 */

params ["_player", ["_callsign", "", [""]], ["_teamColor", "MAIN", [""]]];

if (_callsign isEqualTo "") exitWith {
	_player setVariable [QGVAR(hasGroup), true, true];
};

private _side = side group _player;
private _upper = toUpper _callsign;
private _index = allGroups findIf { side _x isEqualTo _side && {toUpper groupId _x isEqualTo _upper} };
private _group = if (_index > -1) then { allGroups select _index } else { grpNull };

if (isNull _group) then {
	diag_log format ["UNITAF: no %1 group for %2 on %3, making it", _callsign, name _player, _side];
	_group = createGroup [_side, true];
	_group setGroupIdGlobal [_callsign];
};

if (group _player isNotEqualTo _group) then {
	[_player] joinSilent _group;
};
_player assignTeam _teamColor;

_player setVariable [QGVAR(hasGroup), true, true];
