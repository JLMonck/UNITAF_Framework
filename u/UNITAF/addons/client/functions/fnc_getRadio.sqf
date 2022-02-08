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
	//TFAR_currentUnit = _player;
	TFAR_currentUnit = call TFAR_fnc_currentUnit;
	private _hasSW = call TFAR_fnc_haveSWRadio;

	if !(_hasSW) then {
		// TODO: add option to get different radio's based on SIDE and ORBAT/Position/Rank (?)

		private _radioObject = QEGVAR(tablet,Oops_Radio_Classname) call CBA_settings_fnc_get;
		if (typeName _radioObject isEqualTo "STRING") then {
			_player linkItem _radioObject;
		} else {
			private _defaultSWRadio = [side _player, 1] call TFAR_fnc_getSideRadio;		// (0 - LR, 1 - SW, 2 - Rifleman)
			_player linkItem _defaultSWRadio;
		};

		hint "Good, a radio, now you can finally hear your buddy screaming at you";

		[QEGVAR(Statistics,getTabletItem), [_player, "radio"]] call CBA_fnc_serverEvent;
	};
};