#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Requests an update of the ORBAT
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

// Fetch this player's slot again: role, traits, group and radios. Their kit is left alone.
// Asked of the server by remoteExecCall, which takes it only for this machine's own unit (UNITAF tracker #202)
[player] remoteExecCall [QEFUNC(server,queryPlayerData), 2];