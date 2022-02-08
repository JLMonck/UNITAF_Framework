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

private _items = (assignedItems _player) + (items _player);
private _hasNVG = false;
{
	if (_x isKindOf  "NVGoggles") then {
		_hasNVG = true;
	};
} forEach _items;


if !(_hasNVG) then {
	private _nvgObject = QEGVAR(tablet,Oops_NVG_Classname) call CBA_settings_fnc_get;
	if (typeName _nvgObject isEqualTo "STRING") then {
		_player linkItem _nvgObject;
	} else {
		if (isClass(configFile >> "CfgPatches" >> "ace_nightvision")) then {
			_player linkItem "ACE_NVG_Wide";
		} else {
			_player linkItem "NVGoggles";
		}
	};
	hint "Now you can finally see in the dark, you chicken";
};