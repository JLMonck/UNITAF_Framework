#include "script_component.hpp"
/*
 * Author: Katalam
 * Calculates all the sums for the statistic.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call UNITAF_statistic_fnc_callStatisticServer
 *
 */

if !(isServer) exitWith {};

{
    _sum = 0;
    {
        _sum = _sum + (_x select 1);
    } forEach (_x select 0);
    missionNamespace setVariable [_x select 1, _sum];
    publicVariable (_x select 1);
} forEach [
    [GVAR(shotsFired), QGVAR(sum_shotsFired)],
    [GVAR(fragsOut), QGVAR(sum_fragsOut)],
    [GVAR(launcherFired), QGVAR(sum_launcherFired)],
    [GVAR(handGunFired), QGVAR(sum_handGunFired)]
];
publicVariable QGVAR(aiKilled);
publicVariable QGVAR(vehicleFired);
[{
    {
        _sum = 0;
        {
            _sum = _sum + (_x select 1);
        } forEach (_x select 0);
        missionNamespace setVariable [_x select 1, _sum];
        publicVariable (_x select 1);
    } forEach [
        [GVAR(pulseCheckedServer), QGVAR(sum_pulseChecked)],
        [GVAR(bandagesAppliedServer), QGVAR(sum_bandagesApplied)],
        [GVAR(cprPerformedServer), QGVAR(sum_cprPerformed)]
    ];
}, [], 8] call CBA_fnc_waitAndExecute;

["CAManBase", "Fired", {
    params ["_unit", "", "", "", "", "", "_projectile"];
    deleteVehicle _projectile;
    private _oldPos = getPos _unit;
    _unit setPos [0,0,0];
    [{
        params ["_unit", "_oldPos"];
        ["ACE_G_M84" createVehicle (GetPos _unit)] call ace_grenades_fnc_flashbangThrownFuze;
        [{
            params ["_unit", "_oldPos"];
            _unit setPos _oldPos;
        }, [_unit, _oldPos], 1] call CBA_fnc_waitAndExecute;
    }, [_unit, _oldPos], 1] call CBA_fnc_waitAndExecute;
    _unit action ["SWITCHWEAPON", player, player, -1];
}] call CBA_fnc_addClassEventHandler;
