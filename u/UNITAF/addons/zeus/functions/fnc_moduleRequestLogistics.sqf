#include "script_component.hpp"

// Logistics Request
[
	"[UNITAF]",
	"Logistics Request",
	{
		_this call FUNC(dialogRequestLogistics);
	},
	""	// Icon
] call zen_custom_modules_fnc_register;
