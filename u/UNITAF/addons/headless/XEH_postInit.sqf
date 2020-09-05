#include "script_component.hpp"
/**
 * Author: Grezvany13
 * XEH postInit
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

if (!hasInterface && !isDedicated) then {
	//run on headless clients only
};
if (!hasInterface) then {
	//run on headless clients and dedicated server

	/**
	 * Set Event Handlers
	 */
	[QEGVAR(HeadlessEvent,callENDEX), {
		_this call FUNC(callENDEX);
	}] call CBA_fnc_addEventHandler;
};