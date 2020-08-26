#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Set Group based on ORBAT
 *
 * Arguments:
 * 0: player <OBJECT>
 * 1: callsign <STRING>
 * 2: teamColo <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_setGroup;
 *
 * Public: No
 */

params ["_player", "_callsign", "_teamColor"];

/**
 * Ugly hack to make sure the group exists, due to stupid bug with automaticly removing empty groups...
 * /
_groupExists = false;
{
	if ((toUpper groupId _x) isEqualTo (toUpper _callsign)) then {
		_groupExists = true;
	};
} forEach allGroups;

if !(_groupExists) then {
	_group = createGroup [west, false];
	_group setGroupIdGlobal [_callsign];
};
/**
 * END Ugly hack
 */

{
	if ((toUpper groupId _x) isEqualTo (toUpper _callsign)) then {
		[_player] joinSilent _x;
		_player assignTeam _teamColor;
	};
} forEach allGroups;