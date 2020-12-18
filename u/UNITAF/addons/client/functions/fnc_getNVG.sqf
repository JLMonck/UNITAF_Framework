#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Get "free" NVG's in case you forgot it, or lost it
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

_items = (assignedItems _player) + (items _player);
_hasNVG = false;
{
	if (_x isKindOf  "NVGoggles") then {
		_hasNVG = true;
	};
} forEach _items;


if !(_hasNVG) then {
	_nvgObject = QGVAR(Oops_NVG_Classname) call CBA_settings_fnc_get;
	_player linkItem _nvgObject;

	//_player linkItem "rhsusf_ANPVS_15";
	//_player linkItem "NVGoggles";
	hint "Now you can finally see in the dark, you chicken";
};