#include "script_component.hpp"

params ["_position", "_object"];

_icons = [
	["Connect", "", "\a3\ui_f\data\IGUI\Cfg\HoldActions\holdAction_connect_ca.paa"],
	["Hack", "", "\a3\ui_f\data\IGUI\Cfg\HoldActions\holdAction_hack_ca.paa"],
	["Search", "", "\a3\ui_f\data\IGUI\Cfg\HoldActions\holdAction_search_ca.paa"],
	["Secure", "", "\a3\ui_f\data\IGUI\Cfg\HoldActions\holdAction_secure_ca.paa"]
];
_iconList = _icons apply {_x select 2};

[
	"Hack Terminal",
	[
		[
			"EDIT",
			"Title",
			[
				"Hack Terminal",
				{}
			]
		],
		[
			"LIST",
			"Icon",
			[
				_iconList,
				_icons
			]
		],
		[
			"EDIT:CODE",
			"On Completion",
			[
				"",
				{},
				4
			]
		],
		[
			"SLIDER",
			"Duration",
			[
				1, 60, 10, 0
			]
		]
	],				
	{
		_this call FUNC(actionHackTerminal);
	},
	{
		// no nothing on Cancel
	},
	[_object]
] call zen_dialog_fnc_create;