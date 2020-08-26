#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "\a3\ui_f\hpp\definedikcodes.inc"
#include "dikCodes.inc"

[
	COMPONENT_NAME,										// Mod name
	"open_unitaf_menu",
	"Open Unitaf Menu",
	{
		_this call FUNC(openGUI)
	},
	"",
	[DIK_U, [false, true, false]]				// default keybind: CTRL + U (see: https://community.bistudio.com/wiki/DIK_KeyCodes)
] call CBA_fnc_addKeybind;

ADDON = true;
