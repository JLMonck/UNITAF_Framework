#include "script_component.hpp"
/*
[object] call uni_log_logistics_fnc_addAction;
*/
params ["_object"];
[
	_object,
	0,
	["ACE_MainActions"],
	[
		"unitaf_logisticsMenu",
		"Logistic Menu",
		"",
		FUNC(action),
		{true}
	] call ace_interact_menu_fnc_createAction

] call ace_interact_menu_fnc_addActionToObject;