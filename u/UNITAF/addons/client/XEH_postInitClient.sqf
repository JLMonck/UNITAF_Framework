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

/**
 * Set Event Handlers
 */
[QEGVAR(ClientEvent,PlayerInventory), {
	_this call FUNC(setInventory);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ClientEvent,PlayerData), {
	_this call FUNC(setPlayerData);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ClientEvent,PlayerArsenal), {
	_this call FUNC(setArsenal);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ClientEvent,callENDEX), {
	_this call FUNC(callENDEX);
}] call CBA_fnc_addEventHandler;


//if (!isMultiplayer && !is3DENMultiplayer) exitWith {};
if (hasInterface) then {
    [
		{time > 0 && !(isNull player)},
        {
			_startTime = [serverTime, "ARRAY"] call BIS_fnc_timeToString;
			_detail = serverName;
			switch (true) do {
				case !(briefingName isEqualTo ""): {
					_detail = briefingName;
				};
				case !(getText (missionConfigFile >> 'onLoadName') isEqualTo ""): {
					_detail = getText (missionConfigFile >> 'onLoadName');
				};
				case !((str missionName) isEqualTo (str parseNumber missionName)): {
					_detail = missionName;
				};
			};

			[
				["UpdateDetails",			_detail],
				["UpdateState",				"unitedtaskforce.net"],
				["UpdateLargeImageKey",		"unitaf"],
				["UpdateSmallImageKey",		"arma3-logo"],
				["UpdateStartTimestamp",	_startTime] // 1 Hour 30 Mins since mission start
			] call (missionNameSpace getVariable ["DiscordRichPresence_fnc_update",{}]);
		}
    ] call CBA_fnc_waitUntilAndExecute;
};