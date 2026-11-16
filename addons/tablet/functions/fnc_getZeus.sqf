#include "script_component.hpp"
/**
 * Author: Grezvany13
 * local function to trigger 'addToCurator' serverside
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
params ["_player"];

// Through clientRequest, which checks the sender is an admin and makes their own unit Zeus (2.6.1)
["addToCurator", []] remoteExecCall [QEFUNC(server,clientRequest), 2];