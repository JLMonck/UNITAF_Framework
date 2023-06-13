#include "script_component.hpp"
/**
 * Author: Grezvany13
 * XEH postInitClient
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

GVAR(toggle_zeus_fps_counter) = true;
GVAR(inCuratorInterface) = false;

call FUNC(initClientFPS);