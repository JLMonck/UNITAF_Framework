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
    ["Player FPS Update", "Send each client's FPS to the server, for the Zeus FPS counter and the operation's performance record on the website"],
    [QUOTE(PREFIX), "ZEUS"],
    true,
    1,
    {},
	false
] call CBA_settings_fnc_init;
[
    QGVAR(FPSUpdateInterval),
    "SLIDER",
    ["Player FPS Update Interval", "Interval in seconds on which each client sends its FPS to the server"],
    [QUOTE(PREFIX), "ZEUS"],
    [1, 30, 5, 0],
    3,
    {},
	false
] call CBA_settings_fnc_init;