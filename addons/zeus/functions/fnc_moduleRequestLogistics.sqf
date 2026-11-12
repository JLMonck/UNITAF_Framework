#include "script_component.hpp"

// Logistics Request
[
	"[UNITAF]",
	"Logistics Request",
	{
		// Ask the server for this deployment's crates; it answers with crateList, which opens the dialog
		params ["_position"];
		[QEGVAR(ServerEvent,listCrates), [_position, player]] call CBA_fnc_serverEvent;
	},
	""	// Icon
] call zen_custom_modules_fnc_register;
