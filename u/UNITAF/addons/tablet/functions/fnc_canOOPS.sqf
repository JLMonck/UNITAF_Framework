#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Check if player can access the UNITAF ORBAT functions
 * Will check if inside marker area, OR within 50m of marker, OR within 50m of ORBAT arsenal
 *
 * Arguments:
 * 0: player <OBJECT>
 * 1: object <STRING>
 *
 * Return Value:
 * <BOOLEAN>
 *
 * Public: No
 */

params ["_player", "_object"];

private _oops = "disabled";
private _return = false;
private _isAdmin = false;

/**
 * Should also work without an ORBAT, or better said, ignore it
 */
_playerData = _player getVariable [QEGVAR(client,userData), []];
if !(count _playerData isEqualTo 0) then {
	_playerData params ["_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEgnineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];
	_isAdmin = (_playerAdmin isEqualTo 1);
};

// Check the object setting
switch (_object) do {
	case "radio": {
		_oops = QGVAR(Oops_Radio) call CBA_settings_fnc_get;
	};
	case "nvg": {
		_oops = QGVAR(Oops_NVG) call CBA_settings_fnc_get;
	};
	case "earplugs": {
		_oops = QGVAR(Oops_Earplugs) call CBA_settings_fnc_get;
	};
	case "gps": {
		_oops = QGVAR(Oops_GPS) call CBA_settings_fnc_get;
	};
};

// Check the setting value
switch (_oops) do {
	case "disabled": {
		// do nothing, keep disabled
	};
	case "orbat_range": {
		if ([_player] call FUNC(canAccessORBAT)) then {
			_return = true;
		};
	};
	case "admin": {
		if ({call BIS_fnc_admin} isEqualTo 2 || _isAdmin) then {
			_return = true;
		};
	};
	case "always": {
		_return = true;
	};
};

_return