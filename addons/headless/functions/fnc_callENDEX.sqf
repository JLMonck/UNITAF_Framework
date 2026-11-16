#include "script_component.hpp"
/*
 * Author: Grezvany13, JLMonck
 * ENDEX on this machine's AI: every AI unit local here stops (disableAI works where the unit is
 * local). Run by the server's unitaf_server_fnc_callENDEX, on the server and by remoteExecCall on
 * each headless client. Taken only from the server (UNITAF tracker #202): any other sender is
 * logged and ignored, so no client can stop the AI.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_headless_fnc_callENDEX;
 *
 * Public: No
 */

if (isRemoteExecuted && {remoteExecutedOwner isNotEqualTo 2}) exitWith {
	diag_log format ["UNITAF: ignored ENDEX for the AI from client %1: only the server sends it", remoteExecutedOwner];
};

// disable all AI local to this machine (server or HC)
{
	_x disableAI "ALL";
} forEach (allUnits select { local _x && {!isPlayer _x} });
