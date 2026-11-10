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

// the server passes every player's FPS to Zeus every 5 seconds; keep them where the counter reads them
[QEGVAR(server,curatorPlayerFPS), {
	params [["_pairs", [], [[]]]];
	{
		_x params ["_unit", "_fps"];
		if (!isNull _unit) then { _unit setVariable [QEGVAR(client,PlayerFPS), _fps]; };
	} forEach _pairs;
}] call CBA_fnc_addEventHandler;

call FUNC(initClientFPS);