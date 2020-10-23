#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "\u\UNITAF\addons\main\dikCodes.inc"

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

ADDON = true;