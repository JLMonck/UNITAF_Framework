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
// A player's ORBAT data, kit and arsenal, and ENDEX, come from the server only, by remoteExecCall
// of setPlayerData, setInventory, setArsenal and callENDEX, which check the sender (UNITAF tracker
// #202). These CBA events do not say who sent them, so through them any client could put kit on
// another player or call ENDEX on everyone: whatever still sends one is turned down, in the RPT.
{
	[_x, {
		diag_log format ["UNITAF: ignored %1: a CBA event does not say who sent it, so only the server's is taken (2.6.2)", _thisType];
	}] call CBA_fnc_addEventHandlerArgs;
} forEach [
	QEGVAR(ClientEvent,PlayerInventory),
	QEGVAR(ClientEvent,PlayerData),
	QEGVAR(ClientEvent,PlayerArsenal),
	QEGVAR(ClientEvent,callENDEX)
];

// Why the server has no data for this player, for the message on the loading screen
[QEGVAR(ClientEvent,PlayerDataFailed), {
	params ["_reason"];
	player setVariable [QGVAR(orbatFailure), _reason];
}] call CBA_fnc_addEventHandler;

// The server turned down something this player may not ask for (unitaf_server_fnc_clientRequest, 2.6.1)
[QEGVAR(ClientEvent,requestRefused), {
	params [["_request", "", [""]]];
	hint (switch (_request) do {
		case "addToCurator": { "Zeus refused: only a Zeus on the ORBAT or an admin can have Zeus." };
		case "callENDEX": { "ENDEX refused: only the Field Leader, an admin or a Zeus can call ENDEX." };
		case "playerData";
		case "playerInventory";
		case "playerArsenal": { "ORBAT refused: you can only load your own ORBAT data." };
		default { "Logistics refused: only Logistics, admins and Zeus can list or spawn crates." };
	});
}] call CBA_fnc_addEventHandler;


//if (!isMultiplayer && !is3DENMultiplayer) exitWith {};
if (hasInterface) then {
    [
		{time > 0 && !(isNull player)},
        {
			private _startTime = [serverTime, "ARRAY"] call BIS_fnc_timeToString;
			private _detail = serverName;
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

	private _update = QGVAR(FPSUpdate) call CBA_settings_fnc_get;
	if (_update) then {
		private _interval = QGVAR(FPSUpdateInterval) call CBA_settings_fnc_get;
		// send this client's FPS to the server only (2) on a fixed interval; the server passes them on
		// to whoever is Zeus (unitaf_server_curatorPlayerFPS), so no client hears every other client
		[{
			player setVariable [QGVAR(PlayerFPS), floor diag_fps, 2];
		}, _interval] call CBA_fnc_addPerFrameHandler;
	};
};