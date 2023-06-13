#include "\u\unitaf\addons\main\dikCodes.inc"

[
	QUOTE(PREFIX),										// Mod name
	"toggle_HUD",
	"Toggle HUD",
	{
		call FUNC(toggleHUD)
	},
	{},
	[DIK_U, [false, false, true]]				// default keybind: ALT + U (see: https://community.bistudio.com/wiki/DIK_KeyCodes)
] call CBA_fnc_addKeybind;
