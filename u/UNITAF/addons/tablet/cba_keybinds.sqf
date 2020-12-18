#include "\u\UNITAF\addons\main\dikCodes.inc"

[
	QUOTE(PREFIX),										// Mod name
	"open_unitaf_tablet",
	"Open Unitaf Tablet",
	{
		_this call FUNC(openTablet)
	},
	{},
	[DIK_U, [false, true, false]]				// default keybind: CTRL + U (see: https://community.bistudio.com/wiki/DIK_KeyCodes)
] call CBA_fnc_addKeybind;