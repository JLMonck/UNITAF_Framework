#include "script_component.hpp"
/*
 * Author: Grezvany13, JLMonck
 * Create groups based on callsigns from ORBAT
 *
 * One empty group per callsign, made at mission start on the server and kept when empty, for
 * players to join when their ORBAT data arrives (unitaf_client_fnc_setGroup). A callsign already
 * held by a group on that side (the mission's own, or a second element of the same name) is not
 * made twice. The website knows no sides yet and says WEST: when the mission has no playable
 * WEST slots, the groups go on the side its players are, since joining a group changes a
 * player's side (UNITAF tracker #202).
 *
 * Arguments:
 * 0: ORBATGroups, the rows of game_groups <ARRAY of [unit <NUMBER>, callsign <STRING>, side <STRING>]>
 *
 * Return Value:
 * Groups made <NUMBER>
 *
 * Example:
 * [[[42, "PYTHON", "WEST"], [43, "REAPER 1-1", "WEST"]]] call unitaf_server_fnc_setORBATGroups
 *
 * Public: No
 */

params [["_ORBATGroups", [], [[]]]];

if (!isServer) exitWith { 0 };

// The side the mission's players are: the one with the most playable slots
private _sides = [west, east, resistance, civilian];
private _slots = _sides apply { playableSlotsNumber _x };
private _playerSide = _sides select (_slots find (selectMax _slots));
if ((selectMax _slots) isEqualTo 0) then { _playerSide = west; };

private _made = 0;
private _skipped = [];
{
	if !(_x isEqualType []) then { _skipped pushBack _x; continue; };
	_x params [["_id", 0], ["_callsign", "", [""]], ["_sideName", "WEST", [""]]];
	if (_callsign isEqualTo "") then { _skipped pushBack _x; continue; };

	private _side = switch (toUpper _sideName) do {
		case "EAST";
		case "OPFOR": { east };
		case "GUER";
		case "INDEPENDENT";
		case "RESISTANCE": { resistance };
		case "ZEUS";
		case "CIV": { civilian };
		default { west };
	};
	// a side with no playable slots in this mission: the players' side
	if ((playableSlotsNumber _side) isEqualTo 0) then { _side = _playerSide; };

	// a group on that side already has this callsign: join that one, make no second
	private _upper = toUpper _callsign;
	if ((allGroups findIf { side _x isEqualTo _side && {toUpper groupId _x isEqualTo _upper} }) > -1) then { continue; };

	private _group = createGroup [_side, false];
	if (isNull _group) then { _skipped pushBack _x; continue; };
	_group setGroupIdGlobal [_callsign];
	_made = _made + 1;
} forEach _ORBATGroups;

diag_log format ["UNITAF: made %1 ORBAT groups on %2 from %3 rows", _made, _playerSide, count _ORBATGroups];
if (_skipped isNotEqualTo []) then {
	diag_log format ["UNITAF: could not make ORBAT groups for %1", _skipped];
};

_made
