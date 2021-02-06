#include "script_component.hpp"
/*
 * Author: Katalam
 * Zeus module callback for ending a mission with a sucess. Displays statistics
 * and stuff. Also notifies server to write into database.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call UNITAF_statistic_fnc_moduleMissionEndSuccess
 *
 */

if !(isServer) then {
    [GVAR(bandagesApplied), GVAR(pulseChecked), GVAR(cprPerformed), getPlayerUID player] remoteExec [QFUNC(addStatisticValues), 2, false];
} else {
    call FUNC(calcStatisticServer);
};

[] spawn {
    playMusic "LeadTrack01_F_Tank";
    sleep 3;
    ["<t color='#00ff00'>Mission accomplished</t>", 1, 0.8] spawn bis_fnc_dynamicText;
    sleep 5;
    [
        [(format ["%1 players", playersNumber playerSide]), 1, 2],
        [(format ["%1 min in battle", floor (time / 60)]), 1, 3]
    ] spawn bis_fnc_EXP_camp_SITREP;
    sleep 9;
    [
        [format ["%1 bullets shot", GVAR(sum_shotsFired)], 1, 2],
        [format ["%1 grenades thrown", GVAR(sum_fragsOut)], 1, 2],
        [format ["%1 enemies killed", GVAR(aiKilled)], 1, 3]
    ] spawn bis_fnc_EXP_camp_SITREP;
    sleep 12;
    [
        [format ["%1 launcher fired", GVAR(sum_launcherFired)], 1, 2],
        [format ["%1 handgun shots", GVAR(sum_handGunFired)], 1, 2],
        [format ["%1 vehicle bullets shot", GVAR(vehicleFired)], 1, 3]
    ] spawn bis_fnc_EXP_camp_SITREP;
    sleep 12;
    [
        [format ["%1 pulse measurements", GVAR(sum_pulseChecked)], 1, 2],
        [format ["%1 bandages applied", GVAR(sum_bandagesApplied)], 1, 2],
        [format ["%1 times CPR", GVAR(sum_cprPerformed)], 1, 3]
    ] spawn bis_fnc_EXP_camp_SITREP;
    sleep 12;
    5 fadeMusic 0;
    ["end1", true, 5] spawn bis_fnc_endMission;
};
