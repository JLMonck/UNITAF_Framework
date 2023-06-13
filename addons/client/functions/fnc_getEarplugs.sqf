#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Get "free" Earplugs in case you forgot it, or lost it
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call unitaf_client_fnc_getEarplugs;
 *
 * Public: Yes
 */

params ["_player"];

if (isClass(configFile >> "CfgPatches" >> "ace_hearing")) then {
	if (!("ACE_EarPlugs" in (items _player)) && !((_player getVariable ["ACE_hasEarPlugsIn", false]) isEqualTo true)) then {
		_player addItem "ACE_EarPlugs";
		hint "Have a pair of earplugs before you go combat deaf";
	};
};