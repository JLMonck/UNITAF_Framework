params ["_setting"];

getMissionConfigValue [_setting, {_setting call CBA_settings_fnc_get}];