#include "\u\unitaf\addons\main\dikCodes.inc"

[
	QUOTE(PREFIX),										// Mod name
	"toggle_zeus_fps_counter",
	"Toggle Zeus FPS Counter",
	{
		GVAR(toggle_zeus_fps_counter) = !GVAR(toggle_zeus_fps_counter);
		//if (GVAR(toggle_zeus_fps_counter)) then {
        	//[QGVAR(hudToggled), [GVAR(toggle_zeus_fps_counter)]] call CBA_fnc_localEvent;
		//};
    },
	{},
	[DIK_I, [false, false, false]]				// default keybind: I (see: https://community.bistudio.com/wiki/DIK_KeyCodes)
] call CBA_fnc_addKeybind;