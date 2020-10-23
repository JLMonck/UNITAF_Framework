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
// _playerData = [armauid, playerRank, playerAdmin, playerPos, playerDir, operation, is_medic_level, is_engineer_level, unit, callsign, freq, buddy, lr_freq, armarank, role, leader, is_zeus, is_eod, is_logistics, is_reporter];
_playerData params ["_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEgnineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];

// set tank
player setUnitRank _armarank;

// set ACE traits
player setUnitTrait ["medic", (_isMedic > 0)];
player setVariable ["ace_medical_medicClass", _isMedic, true];

player setUnitTrait ["engineer", (_isEgnineer > 0)];
player setVariable ["ACE_IsEngineer", _isEgnineer, true];

player setUnitTrait ["explosiveSpecialist", false];
player setVariable ["ACE_isEOD", _isEOD, true];

player setUnitTrait ["UAVHacker", false];

// set insignia
[player, ""] call BIS_fnc_setUnitInsignia;
[player, _playerRank] call BIS_fnc_setUnitInsignia;

// set callsign / team
[player, _callsign, _buddy] call FUNC(setGroup);
// set radio frequencies of callsign
[player, _freq, _lr_freq] call FUNC(setRadioFreq);

player setVariable [QGVAR(hasUserData), true, true];
player setVariable [QGVAR(userData), _playerData, true];

if (_isZeus isEqualTo 1) then {
	[QEGVAR(ServerEvent,addToCurator), [player]] call CBA_fnc_serverEvent;
};