#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Request ACE Arsenal items list from server
 *
 * NOTE: not used in any script, but can be used to manually update the arsenal
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call unitaf_client_fnc_getArsenal;
 *
 * Public: Yes
 */
params ["_player"];

// Asked of the server by remoteExecCall, which takes it only for this machine's own unit (UNITAF tracker #202)
[_player] remoteExecCall [QEFUNC(server,queryPlayerArsenal), 2];