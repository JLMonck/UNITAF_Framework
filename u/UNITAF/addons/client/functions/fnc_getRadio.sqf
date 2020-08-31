#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Get a "free" SW Radio in case you forgot it, or lost it
 *
 * Arguments:
 * 0: player <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_getRadio;
 *
 * Public: Yes
 */
params ["_player"];

if (isClass(configFile >> "CfgPatches" >> "tfar_core")) then {
	TFAR_currentUnit = _player;
	_hasSW = call TFAR_fnc_haveSWRadio;

	if !(_hasSW) then {
		_defaultSWRadio = [side _player, 1] call TFAR_fnc_getSideRadio;		// (0 - LR, 1 - SW, 2 - Rifleman)
		_player linkItem _defaultSWRadio;

		// TODO: add option to get different radio's based on SIDE and ORBAT/Position/Rank (?)

		hint "Good, a radio, now you can finally hear your buddy screaming at you";
	};
};