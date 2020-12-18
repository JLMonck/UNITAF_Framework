#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the Main Page on the tablet
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

_display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

GET_MAIN ctrlShow true;
[GET_MAIN] call FUNC(hideAll);

// Hide ADMIN button by default
GET_IN_MAIN(IDC_Tablet_Main_Button_Admin) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_Admin) ctrlShow false;
// Hide LOGI button by default
GET_IN_MAIN(IDC_Tablet_Main_Button_Logistics) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_Logistics) ctrlShow false;
// Hide REPORTER button by default
GET_IN_MAIN(IDC_Tablet_Main_Button_Reporter) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_Reporter) ctrlShow false;

GET_IN_MAIN(IDC_Tablet_Main_Button_LoadORBAT) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_ORBAT) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_OPORD) ctrlEnable false;

// Disable OOPS buttons by default
GET_IN_MAIN(IDC_Tablet_Main_Button_GetRadio) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_GetNVG) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_GetEarplugs) ctrlEnable false;
GET_IN_MAIN(IDC_Tablet_Main_Button_GetGPS) ctrlEnable false;

if ([player, "radio"] call FUNC(canOOPS)) then {
	GET_IN_MAIN(IDC_Tablet_Main_Button_GetRadio) ctrlEnable true;
};
if ([player, "nvg"] call FUNC(canOOPS)) then {
	GET_IN_MAIN(IDC_Tablet_Main_Button_GetNVG) ctrlEnable true;
};
if ([player, "earplugs"] call FUNC(canOOPS)) then {
	GET_IN_MAIN(IDC_Tablet_Main_Button_GetEarplugs) ctrlEnable true;
};
if ([player, "gps"] call FUNC(canOOPS)) then {
	GET_IN_MAIN(IDC_Tablet_Main_Button_GetGPS) ctrlEnable true;
};

if (
	(missionNamespace getVariable ['UNITAF_useORBAT', false])
) then {
	if ([player] call FUNC(canAccessORBAT)) then {
		GET_IN_MAIN(IDC_Tablet_Main_Button_LoadORBAT) ctrlEnable true;
	};
	GET_IN_MAIN(IDC_Tablet_Main_Button_ORBAT) ctrlEnable true;

	if !((missionNamespace getVariable ['UNITAF_operationID', 0]) isEqualTo 0) then {
		GET_IN_MAIN(IDC_Tablet_Main_Button_OPORD) ctrlEnable true;
	};

	[] spawn {
		// Reset everything
		//GET_IN_MAIN(IDC_Tablet_Main_Callsign) ctrlSetStructuredText parseText "";
		//GET_IN_MAIN(IDC_Tablet_Main_Report) ctrlSetStructuredText parseText "";
		//GET_IN_MAIN(IDC_Tablet_Main_Role) ctrlSetStructuredText parseText "";
		//GET_IN_MAIN(IDC_Tablet_Main_Color) ctrlSetStructuredText parseText "";

		_ctrlTeam = GET_IN_MAIN(IDC_Tablet_Main_Team);
		lnbClear _ctrlTeam; // empty list first!

		// TODO: Use 'waitUntil' or simply 'exitWith' ?
		waitUntil { player getVariable [QEGVAR(client,hasUserData), false] };

		// if ORBAT is loaded, show team stuff
		_playerData = player getVariable [QEGVAR(client,userData), []];
		if !(count _playerData isEqualTo 0) then {
			_playerData params ["_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEgnineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];

			_isAdmin = (_playerAdmin isEqualTo 1 || ({call BIS_fnc_admin} isEqualTo 2));

			// isAdmin in ORBAT/DB or is logged in as admin
			if (_isAdmin) then {
				GET_IN_MAIN(IDC_Tablet_Main_Button_Admin) ctrlEnable true;
				GET_IN_MAIN(IDC_Tablet_Main_Button_Admin) ctrlShow true;
			};
			// isLogi ?
			if (_isAdmin || _isLogistics isEqualTo 1) then {
				GET_IN_MAIN(IDC_Tablet_Main_Button_Logistics) ctrlEnable true;
				GET_IN_MAIN(IDC_Tablet_Main_Button_Logistics) ctrlShow true;
			};
			// isReporter ?
			if (_isAdmin || _isReporter isEqualTo 1) then {
				GET_IN_MAIN(IDC_Tablet_Main_Button_Reporter) ctrlEnable true;
				GET_IN_MAIN(IDC_Tablet_Main_Button_Reporter) ctrlShow true;
			};
			
			GET_IN_MAIN(IDC_Tablet_Main_Callsign) ctrlSetStructuredText parseText _callsign;	// Callsign
			GET_IN_MAIN(IDC_Tablet_Main_Report) ctrlSetStructuredText parseText _leader;			// Report To (aka PltL / SL / FTL)
			GET_IN_MAIN(IDC_Tablet_Main_Role) ctrlSetStructuredText parseText _role;				// Role

			_color = "#ffffff";
			switch (_buddy) do {
				case 'RED': {		_color = "#ff0000"; };
				case 'GREEN': {		_color = "#00ff00"; };
				case 'BLUE': {		_color = "#0000ff"; };
				case 'YELLOW': {	_color = "#ffff00"; };
				case "MAIN";
				default {			_color = "#ffffff"; _buddy = 'WHITE'; };
			};
			GET_IN_MAIN(IDC_Tablet_Main_Color) ctrlSetStructuredText parseText format ["<t color='%1'>%2</t>", _color, _buddy];			// Buddy Color

			// TEST DATA
			_fullORBAT = missionNamespace getVariable ["UNITAF_ORBAT",[]];
			if !(_fullORBAT isEqualTo []) then {
				_ctrlTeam = GET_IN_MAIN(IDC_Tablet_Main_Team);
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
};