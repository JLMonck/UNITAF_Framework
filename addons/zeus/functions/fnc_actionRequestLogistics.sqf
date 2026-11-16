#include "script_component.hpp"
/*
 * Author: Grezvany13, JLMonck
 * "Request logistics" confirmed: the server reads the crate, packs it and spawns the boxes.
 *
 * Arguments:
 * 0: Dialog values [supplies, container type, full arsenal] <ARRAY>
 * 1: Arguments [position] <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_values", "_arguments"];
_values params ["_choice", "_type", "_arsenal"];
_arguments params ["_position"];

// Through clientRequest, which checks who asks (2.6.1)
["spawnCrate", [_choice, _type, _arsenal, _position]] remoteExecCall [QEFUNC(server,clientRequest), 2];
