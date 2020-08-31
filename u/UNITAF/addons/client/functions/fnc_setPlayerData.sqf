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
// _playerData = [playerRank, playerAdmin, playerPos, playerDir, is_medic_level, is_engineer_level, callsign, freq, buddy, lr_freq, armarank];
_playerData params ["_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_is_medic_level", "_is_engineer_level", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank"];

_playerRank = "";		// just override it (for now)

// set tank
player setUnitRank _armarank;

// set ACE traits
player setUnitTrait ["medic", (_is_medic_level > 0)];
player setVariable ["ace_medical_medicClass", _is_medic_level, true];

player setUnitTrait ["engineer", (_is_engineer_level > 0)];
player setVariable ["ACE_IsEngineer", _is_engineer_level, true];

player setUnitTrait ["explosiveSpecialist", false];
player setVariable ["ACE_isEOD", 0, true];

player setUnitTrait ["UAVHacker", false];

// set insignia
[player, ""] call BIS_fnc_setUnitInsignia;
[player, _playerRank] call BIS_fnc_setUnitInsignia;

// set callsign / team
[player, _callsign, _buddy] call FUNC(setGroup);
// set radio frequencies of callsign
[player, _freq, _lr_freq] call FUNC(setRadioFreq);

player setVariable [QGVAR('hasUserData'), true, true];
player setVariable [QGVAR('userData'), _playerData, true];