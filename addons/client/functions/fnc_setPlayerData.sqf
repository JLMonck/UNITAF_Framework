#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Set player data based on ORBAT
 *
 * Arguments:
 * 0: playerData <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_playerData"];
_playerData params ["_nickname","_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEngineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];

// set rank
player setUnitRank _armarank;

//check if name is correct
_msg = profileName + " profile name error - change to: " + _nickname;
 
if (profileName isEqualTo _nickname) then {
} else {
	_msg remoteExec ["systemchat", 0]; 
}

// set ACE traits
if !((_isMedic call BIS_fnc_parseNumber) > -1) then {
	_isMedic = parseNumber _isMedic;
};
player setUnitTrait ["medic", (_isMedic > 0)];
player setVariable ["ace_medical_medicClass", _isMedic, true];

if !((_isEngineer call BIS_fnc_parseNumber) > -1) then {
	_isEngineer = parseNumber _isEngineer;
};
player setUnitTrait ["engineer", (_isEngineer > 0)];
player setVariable ["ACE_IsEngineer", _isEngineer, true];

if !((_isEOD call BIS_fnc_parseNumber) > -1) then {
	_isEOD = parseNumber _isEOD;
};
player setUnitTrait ["explosiveSpecialist", (_isEOD > 0)];
player setVariable ["ACE_isEOD", (_isEOD > 0), true];	// must be boolean, otherwise DUI breaks...

[_role] call FUNC(setRoleHacks);

// set insignia (with small sleep between emptying and adding)
[_playerRank] spawn {
	params ["_playerRank"];
	// let's wait till an inventory has been set...
	waitUntil {(player getVariable [QGVAR(hasInventory), false]) isEqualTo true};

	[player, ""] call BIS_fnc_setUnitInsignia;
	sleep 0.3;
	[player, _playerRank] call BIS_fnc_setUnitInsignia;
};

// set callsign / team
[player, _callsign, _buddy] call FUNC(setGroup);
// set radio frequencies of callsign
[player, _freq, _lr_freq] call FUNC(setRadioFreq);

player setVariable [QGVAR(hasUserData), true, true];
player setVariable [QGVAR(userData), _playerData, true];

private _autoZeus = QEGVAR(server,Zeus_autoZeus) call CBA_settings_fnc_get;
if (_autoZeus && _isZeus isEqualTo 1) then {
	[QEGVAR(ServerEvent,addToCurator), [player]] call CBA_fnc_serverEvent;
};

// Calls "UNITAF_localEvent_playerData" locally
// sends all the playerData
//
// ["UNITAF_localEvent_playerData", {
//    params ["_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEngineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];
//    ..code..
// }] call CBA_fnc_addEventHandler;
[QEGVAR(localEvent,playerData), _playerData] call CBA_fnc_localEvent;