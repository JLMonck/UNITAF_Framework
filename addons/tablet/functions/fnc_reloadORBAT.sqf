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
[QEGVAR(ServerEvent,queryPlayerData), [player]] call CBA_fnc_serverEvent;