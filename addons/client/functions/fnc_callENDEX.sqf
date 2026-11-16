#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Heal player and show ENDEX message
 *
 * Sent to every machine by the server's unitaf_server_fnc_callENDEX, once clientRequest has
 * checked who asked. Taken only from the server (UNITAF tracker #202): any other sender is logged
 * and ignored, so no client can call ENDEX on everyone.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: Yes
 */

if (!hasInterface) exitWith {};
if (isRemoteExecuted && {remoteExecutedOwner isNotEqualTo 2}) exitWith {
	diag_log format ["UNITAF: ignored ENDEX from client %1: only the server sends it", remoteExecutedOwner];
};

// Fully heal player
if (isClass(configFile >> "CfgPatches" >> "ace_medical_treatment")) then {
	[player, player] call ace_medical_treatment_fnc_fullHeal;
} else {
	player setDamage 0;
};
[player, currentWeapon player, true] call ace_safemode_fnc_setWeaponSafety;

// Show ENDEX message
[] spawn {
	"ENDEX" cutText [
		"<t size='6' color='#85703a'>ENDEX, ENDEX, ENDEX</t><br/><t size='2'>Mission Complete, get ready for AAR and R&amp;R</t>",
		"PLAIN",
		1,
		true,
		true
	];
	sleep 10;
	"ENDEX" cutFadeOut 1;
};
