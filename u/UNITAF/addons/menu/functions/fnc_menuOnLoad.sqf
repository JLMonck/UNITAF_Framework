#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Automatically runs on OnLoad of UNITAF_Menu_GUI
 * Checks for ORBAT Access, and sets all settings for player
 *
 * Arguments:
 * 0: display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

params ["_display"];

uiNamespace setVariable [QGVAR(menuDisplay), _display];

// hide other controls
GET_OPORD(_display) ctrlShow false;
GET_ORBAT(_display) ctrlShow false;
GET_ADMIN(_display) ctrlShow false;
GET_BACK(_display) ctrlShow false;

// show MAIN control
GET_MAIN(_display) ctrlShow true;
GET_CLOSE(_display) ctrlShow true;

// Hide ADMIN button by default
GET_IN_MAIN(_display,IDC_BUTTON_Admin) ctrlEnable false;
GET_IN_MAIN(_display,IDC_BUTTON_Admin) ctrlShow false;

GET_IN_MAIN(_display,IDC_BUTTON_LoadORBAT) ctrlEnable false;
GET_IN_MAIN(_display,IDC_BUTTON_ORBAT) ctrlEnable false;
GET_IN_MAIN(_display,IDC_BUTTON_OPORD) ctrlEnable false;

if (
	(missionNamespace getVariable ['UNITAF_useORBAT', false])
) then {
	if ([player] call FUNC(canAccessORBAT)) then {
		GET_IN_MAIN(_display,IDC_BUTTON_LoadORBAT) ctrlEnable true;
	};
	GET_IN_MAIN(_display,IDC_BUTTON_ORBAT) ctrlEnable true;

	if !((missionNamespace getVariable ['UNITAF_operationID', 0]) isEqualTo 0) then {
		GET_IN_MAIN(_display,IDC_BUTTON_OPORD) ctrlEnable true;
	};

	[_display] spawn {
		params ["_display"];

		// Reset everything
		GET_IN_MAIN(_display,IDC_Callsign) ctrlSetStructuredText parseText "";
		GET_IN_MAIN(_display,IDC_Report) ctrlSetStructuredText parseText "";
		GET_IN_MAIN(_display,IDC_Role) ctrlSetStructuredText parseText "";
		GET_IN_MAIN(_display,IDC_Color) ctrlSetStructuredText parseText "";

		_ctrlTeam = GET_IN_MAIN(_display,IDC_Team);
		lnbClear _ctrlTeam; // empty list first!

		// TODO: Use 'waitUntil' or simply 'exitWith' ?
		waitUntil { player getVariable [QEGVAR(client,hasUserData), false] };

		// if ORBAT is loaded, show team stuff
		_playerData = player getVariable [QEGVAR(client,userData), []];
		if !(count _playerData isEqualTo 0) then {
			_playerData params ["_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_is_medic_level", "_is_engineer_level", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank"];

			if (_playerAdmin isEqualTo 1) then {
				GET_IN_MAIN(_display,IDC_BUTTON_Admin) ctrlEnable true;
				GET_IN_MAIN(_display,IDC_BUTTON_Admin) ctrlShow true;
			};
			
			GET_IN_MAIN(_display,IDC_Callsign) ctrlSetStructuredText parseText _callsign;	// Callsign
			GET_IN_MAIN(_display,IDC_Report) ctrlSetStructuredText parseText "";			// Report To (aka PltL / SL / FTL)
			GET_IN_MAIN(_display,IDC_Role) ctrlSetStructuredText parseText "";				// Role

			_color = "#ffffff";
			switch (_buddy) do {
				case 'RED': {		_color = "#ff0000"; };
				case 'GREEN': {		_color = "#00ff00"; };
				case 'BLUE': {		_color = "#0000ff"; };
				case 'YELLOW': {	_color = "#ffff00"; };
				case "MAIN";
				default {			_color = "#ffffff"; _buddy = 'WHITE'; };
			};
			GET_IN_MAIN(_display,IDC_Color) ctrlSetStructuredText parseText format ["<t color='%1'>%2</t>", _color, _buddy];			// Buddy Color

			// TEST DATA
			_fullORBAT = missionNamespace getVariable ["UNITAF_ORBAT",[]];

			_ctrlTeam = GET_IN_MAIN(_display,IDC_Team);
			lnbClear _ctrlTeam; // empty list first!
			{
				if ((_x select 4) isEqualTo _callsign) then {
					_ctrlTeam lnbAddRow [(_x select 1)];
					_ctrlTeam lnbSetText [[_foreachIndex, 1], (_x select 1)];

					_rank = "";
					switch (toUpper (_x select 0)) do {
						case "REC": {};
						case "PVT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
							case "PFC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
							case "SPC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
							case "MSP": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
						case "CPL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa"; };
						case "SGT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
							case "SSGT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
							case "SFC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
							case "1SG": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
							case "SGTMAJ": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
						case "2LT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa"; };
							case "1LT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa"; };
						case "CAPT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\captain_gs.paa"; };
						case "MAJ": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\major_gs.paa"; };
							case "LTCOL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\major_gs.paa"; };
						case "COL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa"; };
					};
					_icon = "\A3\ui_f\data\map\vehicleicons\iconMan_ca.paa";
					switch (toUpper (_x select 2)) do {
						case "TEAM LEADER";
						case "SQUAD LEADER";
						case "PLATOON LEADER": {
							_icon = "\A3\ui_f\data\map\vehicleicons\iconManLeader_ca.paa";
						};
						case "COMBAT LIFE SAVER";
						case "SQUAD MEDIC";
						case "PLATOON MEDIC": {
							_icon = "\A3\ui_f\data\map\vehicleicons\iconManMedic_ca.paa";
						};
						case "AUTOMATIC RIFLEMAN": {
							_icon = "\A3\ui_f\data\map\vehicleicons\iconManMG_ca.paa";
						};
						case "ANTI-TANK RIFLEMAN, LIGHT";
						case "AT SPECIALIST, MEDIUM";
						case "AT SPECIALIST, HEAVY": {
							_icon = "\A3\ui_f\data\map\vehicleicons\iconManAT_ca.paa";
						};
						case "	COMBAT ENGINEER": {
							_icon = "\A3\ui_f\data\map\vehicleicons\iconManEngineer_ca.paa";
						};
					};

					_ctrlTeam lnbSetPicture [[_foreachIndex, 0], _rank];
					_ctrlTeam lnbSetPicture [[_foreachIndex, 2], _icon];
				};
			} forEach _fullORBAT;
		};
	};
};