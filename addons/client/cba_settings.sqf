[
    QGVAR(BleedOut),
    "CHECKBOX",
    ["Enable No Bleedout", "Prevents players to die from bleeding out"],
    [QUOTE(PREFIX), "Medical"],
    true,
    1,
    {},
	false
] call CBA_settings_fnc_init;

[
    QGVAR(FPSUpdate),
    "CHECKBOX",
    ["Player FPS Update", "Allow the FPS of each client to be updated and shown under the name of the client in Zeus"],
    [QUOTE(PREFIX), "ZEUS"],
    true,
    1,
    {},
	false
] call CBA_settings_fnc_init;
[
    QGVAR(FPSUpdateInterval),
    "SLIDER",
    ["Player FPS Update Interval", "Interval in seconds on which the FPS is updated"],
    [QUOTE(PREFIX), "ZEUS"],
    [0, 30, 1, 0],
    3,
    {},
	false
] call CBA_settings_fnc_init;