#include "script_component.hpp"

disableSerialization;

params ["_player", "_corpse", ["_arsenal", false, [true]]];

// run through spawn to fix timing issues (because scripts can't run on same frame as unit creation)
[_player, _corpse, _arsenal] spawn {
	params ["_player", "_corpse", "_arsenal"];

	//XEH should only be called on local units
	if (!local _player) exitWith {false};
	if(!hasInterface) exitWith {false};
	if(isDedicated) exitWith {false};
	waitUntil {!isNull _player};
	waitUntil {isPlayer _player};

	// not really needed anymore, since ACE fixed this issue themselves
	// people can now still die, but won't bleed out instantly when there's no heart rate
	[_player] call FUNC(godMode);

	if ((getMissionConfigValue ["UNITAF_autoORBAT", 0]) isEqualTo 1) then {
		// check if spawned object is a "humanoid" and if it doesn't have userData yet
		if (_player isKindOf "CAManBase" && (_player getVariable [QGVAR(hasUserData), false]) isEqualTo false) then {
			private _loadingText = format ['<t align="center">
				<img image="\u\UNITAF\addons\assets\images\signage\unitaf-logo.jpg" size="7" with="512" height="251"/><br/>
				<br/>
				Welcome back <t>%1</t>!<br/>
				<br/>
				Loading ORBAT...<br/>
				<br/>
				<br/>
				<t>You can use <t color="#85703a">%2</t> to accesss the UNITAF Tablet</t>
			</t>', profileName, ["open_unitaf_tablet"] call EFUNC(main,keybindToString)];

			private _loadingLayer = "RespawnLoading" cutText [_loadingText, "BLACK", -1, false, true];
			_player enableSimulationGlobal false;

			[_player] call FUNC(getORBAT);
			sleep 3;

			[
				{
					params ["_player"];
					(_player getVariable [QGVAR(hasUserData), false]) isEqualTo true
				},
				{
					params ["_player"];
					_playerData = _player getVariable [QGVAR(userData), []];
					_playerData params ["_armaUID", "_playerRank", "_playerAdmin", "_playerPos", "_playerDir", "_operation", "_isMedic", "_isEgnineer", "_unit", "_callsign", "_freq", "_buddy", "_lr_freq", "_armarank", "_role", "_leader", "_isZeus", "_isEOD", "_isLogistics", "_isReporter"];

					// check if TP marker exists
					if !((_playerPos isEqualTo "") && (getMarkerColor _playerPos isEqualTo "")) then {
						// get marker position
						private _markerPos = getMarkerPos [_playerPos, true];
						// find available position within 10m
						private _position = _markerPos findEmptyPosition [0, 10];
						// make sure it returns a position, otherwise use default
						if (_position isEqualTo []) then {
							_position = _markerPos;
						};

						private _zAxis = _markerPos select 2;
						if !((getMissionConfigValue ["UNITAF_RPHeight", ""]) isEqualTo "") then {
							_zAxis = getMissionConfigValue ["UNITAF_RPHeight", 0];
						};

						// TP player to empty position near marker
						_player setPos [_position select 0, _position select 1, _zAxis];
					};

					[_player] spawn {
						params ["_player"];
						sleep 2;
						_player enableSimulationGlobal true;
						"RespawnLoading" cutFadeOut 1;
					};
				},
				[_player],
				10,
				{
					params ["_player"];
					private _loadingText = '<t align="center">
						Something went wrong with getting data from the ORBAT.<br/>
						This either means you''re not on the ORBAT, you''re on the reserves list, or something went wrong with the database connection.<br/>
						<br/>
						Please contact the Field Leader to get it resolved.
					</t>';

					private _loadingLayer = "RespawnLoading" cutText [_loadingText, "BLACK", -1, false, true];
					
					[_player] spawn {
						params ["_player"];
						sleep 7;
						_player enableSimulationGlobal true;
						"RespawnLoading" cutFadeOut 1;
					};
				}
			] call CBA_fnc_waitUntilAndExecute;
		};
	};
};
true