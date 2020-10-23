#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

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

ADDON = true;
