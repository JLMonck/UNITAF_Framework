#include "script_component.hpp"
/*
 * Author: Sinus, Schwaggot
 * Used to sum up all statistic values on server.
 *
 * Arguments:
 * 0: Applied bandages count <NUMBER>
 * 1: Times pulse was measured <NUMBER>
 * 2: Times CPR was administered <NUMBER>
 * 3: uid of player <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_bandagesApplied, _pulseChecked, _cprPerformed, _uid] remoteExec ["UNITAF_statistic_fnc_addStatisticValues", 2, false]
 *
 */

params [
    ["_bandages", 0, [0]],
    ["_pulse", 0, [0]],
    ["_cpr", 0, [0]],
    ["_uid", "", [""]]
];

GVAR(bandagesAppliedServer) append [[_uid , _bandages]];
GVAR(pulseCheckedServer) append [[_uid , _pulse]];
GVAR(cprPerformedServer) append [[_uid , _cpr]];
