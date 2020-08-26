#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Create groups based on callsigns from ORBAT
 *
 * Arguments:
 * 0: ORBATGroups <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[42, "PYTHON", "West"]] call unitaf_server_fnc_setORBATGroups
 *
 * Public: No
 */

params ["_ORBATGroups"];

// Create groups based on ORBAT
{
    _x params ["_id", "_callsign", "_side"];
	_group = groupNull;
	switch (toupper _side) do {
		case 'EAST': { _group = createGroup [east, false]; };
		case 'GUER': { _group = createGroup [resistance, false]; };
		case 'CIV': { _group = createGroup [civilian, false]; };
		case 'WEST';
		default { _group = createGroup [west, false]; };
	};
    _group setGroupIdGlobal [_callsign];
} forEach _ORBATGroups;