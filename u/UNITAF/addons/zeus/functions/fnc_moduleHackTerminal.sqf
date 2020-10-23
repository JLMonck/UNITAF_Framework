#include "script_component.hpp"

// Logistics Request
[
	"[UNITAF]",
	"Hack Terminal",
	{
		// remove to support other items?
		//if !((_this select 1) isKindOf 'Land_DataTerminal_01_F') exitWith {};
		_this call FUNC(dialogHackTerminal);
	},
	""	// Icon
] call zen_custom_modules_fnc_register;
