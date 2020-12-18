/**
 * Author: Grezvany13
 * CBA Settings related to the tablet (and functions following from that)
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

[
    QGVAR(ORBAT_Range),
    "SLIDER",
    ["Load ORBAT Range", "Maximum range that the ORBAT can be loaded from arsenal or marker"],
    [QUOTE(PREFIX), "UNITAB"],
    [0, 100, 20, 0],
    1,
    {},
	false
] call CBA_settings_fnc_init;

// Earplugs
[
    QGVAR(Oops_Earplugs),
    "LIST",
    ["Get Earplugs", "When and where to get Earplugs"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    [
		[
			"always",
			"orbat_range",
			"admin_only",
			"disabled"
		],
		[
			"Always",
			"ORBAT Range",
			"Admin Only",
			"Disabled"
		],
		0
	],
    1,
    {},
	false
] call CBA_settings_fnc_init;

// GPS
[
    QGVAR(Oops_GPS),
    "LIST",
    ["Get GPS", "When and where to get a GPS"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    [
		[
			"always",
			"orbat_range",
			"admin_only",
			"disabled"
		],
		[
			"Always",
			"ORBAT Range",
			"Admin Only",
			"Disabled"
		],
		0
	],
    1,
    {},
	false
] call CBA_settings_fnc_init;

// Radio
[
    QGVAR(Oops_Radio),
    "LIST",
    ["Get Radio", "When and where to get a Radio"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    [
		[
			"always",
			"orbat_range",
			"admin_only",
			"disabled"
		],
		[
			"Always",
			"ORBAT Range",
			"Admin Only",
			"Disabled"
		],
		0
	],
    1,
    {},
	false
] call CBA_settings_fnc_init;

// RADIO CLASSNAME
[
    QGVAR(Oops_Radio_Classname),
    "EDITBOX",
    ["Radio Classname", "Classname of radio object which will be given when using the OOPS button"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    "TFAR_anprc152",
    1,
    {},
	false
] call CBA_settings_fnc_init;


// NVG
[
    QGVAR(Oops_NVG),
    "LIST",
    ["Get NVG", "When and where to get NVG's"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    [
		[
			"always",
			"orbat_range",
			"admin_only",
			"disabled"
		],
		[
			"Always",
			"ORBAT Range",
			"Admin Only",
			"Disabled"
		],
		0
	],
    1,
    {},
	false
] call CBA_settings_fnc_init;

// NVG CLASSNAME
[
    QGVAR(Oops_NVG_Classname),
    "EDITBOX",
    ["NVG Classname", "Classname of NVG object which will be given when using the OOPS button"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    "NVGoggles",
    1,
    {},
	false
] call CBA_settings_fnc_init;


// GodMode
[
    QGVAR(Oops_NVG),
    "LIST",
    ["Get NVG", "When and where to get NVG's"],
    [QUOTE(PREFIX), "UNITAB - OOPS"],
    [
		[
			"always",
			"orbat_range",
			"admin_only",
			"disabled"
		],
		[
			"Always",
			"ORBAT Range",
			"Admin Only",
			"Disabled"
		],
		0
	],
    1,
    {},
	false
] call CBA_settings_fnc_init;