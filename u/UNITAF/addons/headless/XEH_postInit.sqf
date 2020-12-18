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

if (isServer) then {
	// Run on server only
	if (QGVAR(HCBalancer) call CBA_settings_fnc_get) then {
		[] spawn {
			while {true} do {
				sleep 10;
				call FUNC(darc_aiToHc);
			};
		};
	};
};