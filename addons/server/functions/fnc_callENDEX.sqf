#include "script_component.hpp"
/*
 * Author: JLMonck
 * ENDEX, from the server (UNITAF tracker #202): every AI stops, on the server and each headless
 * client, and every player is healed, made safe and shown the ENDEX screen. The tablet's Admin
 * page asks for it through clientRequest, which checks the sender may; the server then sends it
 * itself. The machines take it only from the server, so no client can call ENDEX on everyone
 * any more.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_server_fnc_callENDEX;
 *
 * Public: No
 */

if (!isServer) exitWith {};

// The server's own AI, then each headless client's (disableAI works where the unit is local)
call EFUNC(headless,callENDEX);
private _headless = (entities "HeadlessClient_F") apply { owner _x };
_headless = _headless select { _x > 2 };
if (_headless isNotEqualTo []) then {
	[] remoteExecCall [QEFUNC(headless,callENDEX), _headless];
};

// Every player (0: a host's own player too; the function does nothing without a screen)
[] remoteExecCall [QEFUNC(client,callENDEX), 0];
