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

	// let HC's update their FPS into a public variable based on a fixed update interval (5sec)
	[{
		_hcName = QGVAR(HCFPS);
		_hcName = format ["%1_%2", _hcName, (name player)];
		missionNameSpace setVariable [_hcName, floor diag_fps, true];
	}, 5] call CBA_fnc_addPerFrameHandler;
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