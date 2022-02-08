#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the Admin Page on the tablet
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

private _display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_ADMIN] call FUNC(hideAll);
GET_ADMIN ctrlShow true;

[] spawn {
	private _ctrlAdmin = GET_ADMIN;
	while {ctrlShown _ctrlAdmin} do {
		private _playerFPS =  player getVariable [QEGVAR(client,PlayerFPS), -1];
		_playerFPS = format ["<t color='%2'>%1</t>", _playerFPS, ["", "#ff0000"] select {_playerFPS < 20}];
		GET_IN_ADMIN(IDC_Tablet_Admin_FPS_local) ctrlSetStructuredText parseText format ["Local FPS: %1 fps", _playerFPS];

		private _serverFPS = missionNamespace getVariable [QEGVAR(server,ServerFPS), -1];
		private _serverUnits = missionNamespace getVariable [QEGVAR(server,ServerUnits), -1];
		//private _serverUnits = count ((allUnits - allPlayers) select {(owner _x == 2)});

		_serverFPS = format ["<t color='%2'>%1</t>", _serverFPS, ["", "#ff0000"] select {_serverFPS < 20}];

		GET_IN_ADMIN(IDC_Tablet_Admin_FPS_Server) ctrlSetStructuredText parseText format ["Server FPS: %1 - Units: %2", _serverFPS, _serverUnits];

		private _hcList = allPlayers - (allPlayers - entities "HeadlessClient_F"); // only get active HC's
		for [{private _i = 0}, {_i < ((count _hcList) min 6)}, {_i = _i + 1}] do {
			private _hc = _hcList select _i;

			private _hcFPS = missionNameSpace getVariable [format ["%1_%2", QEGVAR(headless,HCFPS), (name _hc)], -1];
			//private _hcGroups = missionNameSpace getVariable [format ["%1_%2", QEGVAR(headless,HCGroups), (name _hc)], -1];
			private _hcUnits = missionNameSpace getVariable [format ["%1_%2", QEGVAR(headless,HCUnits), (name _hc)], -1];
			//private _hcUnits = count ((allUnits - allPlayers) select {(owner _x == owner _hc)});
			

			if (_hcFPS > -1) then {
				_hcFPS = format ["<t color='%2'>%1</t>", _hcFPS, ["", "#ff0000"] select {_hcFPS < 20}];

				// ugly hack to get the correct IDC per HC
				switch (_i) do {
					case 0: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC1) ctrlSetStructuredText parseText format["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
					case 1: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC2) ctrlSetStructuredText parseText format ["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
					case 2: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC3) ctrlSetStructuredText parseText format ["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
					case 3: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC4) ctrlSetStructuredText parseText format ["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
					case 4: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC5) ctrlSetStructuredText parseText format ["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
					case 5: {
						GET_IN_ADMIN(IDC_Tablet_Admin_FPS_HC6) ctrlSetStructuredText parseText format ["%1 FPS: %2 - Units: %3", (name _hc), _hcFPS, _hcUnits];
					};
				};
			};
		};
		sleep 1;
	};
};
