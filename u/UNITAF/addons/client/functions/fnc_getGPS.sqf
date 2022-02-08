#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Get "free" GPS in case you forgot it, or lost it
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_getNVG;
 *
 * Public: Yes
 */

params ["_player"];

private _items = (assignedItems _player) + (items _player);
private _hasGPS = false;
{
	if (_x isKindOf  "ItemGPS") then {
		_hasGPS = true;
	};
} forEach _items;


if !(_hasGPS) then {
	_player linkItem "ItemGPS";
	hint "Let the satellites do the hard work for you";
};