#include "script_component.hpp"

params ["_values", "_arguments"];
_values params ["_title", "_icon", "_code", "_duration"];
_arguments params ["_object"];

[
	_object,											// Object the action is attached to
	_title,												// Title of the action
	_icon,												// Idle icon shown on screen
	"",													// Progress icon shown on screen
	"_this distance _target < 3",						// Condition for the action to be shown
	"_caller distance _target < 3",						// Condition for the action to progress
	{},													// Code executed when action starts
	{},													// Code executed on every progress tick
	{
		params ["_target", "_caller", "_actionId", "_arguments"];
		_arguments params ["_code"];
		call compile _code
	},													// Code executed on completion
	{},													// Code executed on interrupted
	[_code],											// Arguments passed to the scripts as _this select 3
	_duration,											// Action duration [s]
	0,													// Priority
	true,												// Remove on completion
	false												// Show in unconscious state 
] remoteExec ["BIS_fnc_holdActionAdd", 0, _object];		// MP compatible implementation



// \a3\sounds_f_orange\MissionSFXOrange_Journalist_Laptop_Typing_01.wss
// A3\Sounds_F\sfx\objects\upload_terminal\Upload_terminal_loop