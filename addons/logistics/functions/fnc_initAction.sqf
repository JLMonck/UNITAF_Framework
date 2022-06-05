#include "script_component.hpp"
if !(GVAR(enable)) exitWith {
	systemChat "Client:UNILOG Not enabled";
};
_action = 	[
			"unitaf_logisticsMenu",
			"Logistic Menu",
			"",
			FUNC(action),
			{true}
			] call ace_interact_menu_fnc_createAction;
["unitaf_logistics_logistics_depot_master", 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToClass;
