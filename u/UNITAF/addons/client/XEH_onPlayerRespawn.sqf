#include "script_component.hpp"

disableSerialization;

params ["_unit", "_corpse", ["_arsenal", false, [true]]];

if ((getMissionConfigValue ["UNITAF_autoORBAT", 0]) isEqualTo 1) then {
	// run through spawn to fix timing issues (because scripts can't run on same frame as unit creation)
	[_unit, _corpse, _arsenal] spawn {
		params ["_unit", "_corpse", "_arsenal"];

		//XEH should only be called on local units
		if (!local _unit) exitWith {false};
		if(!hasInterface) exitWith {false};
		if(isDedicated) exitWith {false};
		waitUntil {!isNull _unit};
		waitUntil {isPlayer _unit};

		// check if spawned object is a "humanoid" and if it doesn't have userData yet
		if (_unit isKindOf "CAManBase" && (player getVariable [QGVAR(hasUserData), false]) isEqualTo false) then {

			_menuKeybinds = ["UNITAF_menu", "open_unitaf_menu"] call CBA_fnc_getKeybind;
			_menuKeybind = (_menuKeybinds select 5) call CBA_fnc_localizeKey;

			_loadingText = format ['<t align="center">
				<img image="\u\UNITAF\addons\assets\images\signage\unitaf-logo.jpg" with="512" height="251"/><br/>
				<br/>
				Welcome back <t>%1</t>!<br/>
				<br/>
				Loading ORBAT...<br/>
				<br/>
				<br/>
				<t>You can use <t>%2</t> to accesss the UNITAF Menu</t>
			</t>', profileName, _menuKeybind];
			_loadingLayer = "RespawnLoading" cutText [_loadingText, "BLACK", -1, false, true];
			_unit enablesimulation false;

			[player] call FUNC(getORBAT);
			waitUntil { (player getVariable [QGVAR(hasUserData), false]) isEqualTo true };

			sleep 3;
			_unit enablesimulation true;
			"RespawnLoading" cutFadeOut 1;
		};
	};
};
true