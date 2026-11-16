#include "script_component.hpp"

// Logistics Request
[
	"[UNITAF]",
	"Logistics Request",
	{
		// Ask the server for this deployment's crates; it answers with crateList, which opens the dialog.
		// Through clientRequest, which checks who asks (2.6.1)
		params ["_position"];
		["listCrates", [_position]] remoteExecCall [QEFUNC(server,clientRequest), 2];
	},
	""	// Icon
] call zen_custom_modules_fnc_register;
