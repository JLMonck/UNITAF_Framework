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

// the server's answer to "Request logistics": this deployment's crates, then the dialog (D-470)
[QEGVAR(ClientEvent,crateList), {
	_this call FUNC(dialogRequestLogistics);
}] call CBA_fnc_addEventHandler;

// Register the module after every addon's preInit: this addon does not require ZEN, so in preInit
// ZEN's own setup could run after ours and drop the registration
if (isClass (configFile >> "CfgPatches" >> "zen_custom_modules")) then {
	call FUNC(moduleRequestLogistics);
};

call FUNC(initClientFPS);