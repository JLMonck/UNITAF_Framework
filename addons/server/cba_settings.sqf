[
    QGVAR(Server_connectionLog),
    "CHECKBOX",
    ["Enable connection logging", "Will store connect, disconnect and kick events to the UNITAF database"],
    [QUOTE(PREFIX), "UNITAB - SERVER"],
    false,
    true,
    {},
    false
] call CBA_settings_fnc_init;

[
    QGVAR(Zeus_autoZeus),
    "CHECKBOX",
    ["Automatically add Zeus Module", "WARNING: may cause lag spike!!!"],
    [QUOTE(PREFIX), "UNITAB - ADMIN"],
    false,
    true,
    {},
    false
] call CBA_settings_fnc_init;
[
    QGVAR(Zeus_addObjects),
    "CHECKBOX",
    ["Add all mission objects to Zeus", "WARNING: will cause lag spike!!!"],
    [QUOTE(PREFIX), "UNITAB - ADMIN"],
    false,
    true,
    {},
    false
] call CBA_settings_fnc_init;