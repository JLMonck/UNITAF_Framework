#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Call ENDEX for all AI and players
 *
 * Asks the server, which checks this player may (an admin or a Zeus on this deployment) and
 * then sends ENDEX to every machine itself (UNITAF tracker #202).
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

[] spawn {
	private _display = GET_TABLET;

	private _result = ["Are you sure?", "Call ENDEX", "Yes, do it!", "Nope!", _display, false] call BIS_fnc_guiMessage;
	if (_result) then {
		// disable all AI (on Server AND HC), heal players and show the ENDEX message: the server does it
		["callENDEX", []] remoteExecCall [QEFUNC(server,clientRequest), 2];

		closeDialog 0;
	};
};
