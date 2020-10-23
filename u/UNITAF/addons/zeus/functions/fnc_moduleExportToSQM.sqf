#include "script_component.hpp"

// Export to SQM
[
	"[UNITAF]",
	"Export to SQM",
	{
		_this call FUNC(actionExportToSQM);
	},
	""	// Icon
] call zen_custom_modules_fnc_register;
