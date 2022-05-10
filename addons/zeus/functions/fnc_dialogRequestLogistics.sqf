#include "script_component.hpp"

params ["_position", "_object"];

_containers = QUOTE((getNumber (_x >> 'scope') >= 2) && (configName _x) isKindOf SQUOTE(EGVAR(logistics,Container_Base))) configClasses (configFile >> "CfgVehicles");

_containers = [_containers, [], {configName _x}, "DESCEND"] call BIS_fnc_sortBy;
_containers = [_containers, [], {getNumber (_x >> "maximumLoad")}, "ASCEND"] call BIS_fnc_sortBy;

_containerClasses = _containers apply { configName _x };
_containerNames = _containers apply { [(getText (_x >> "displayName")), format ["maxLoad: %1", (getNumber (_x >> "maximumLoad"))], (getText (_x >> "editorPreview"))] };

[
	"Logistics Request",
	[
		[
			"COMBO",
			"Supply Configuration",
			[
				[
					"47/190",
					"47/199",
					"47/200",
					"47/201",
					"47/202",
					"47/203",
					"47/204",
					"47/205",
					"47/206"
				],
				[
					// Get list from DB?
					["47/190 - Medical", "", "", [1,0,0,1]],
					["47/199 - Supply, AT light", "", "", [0,0,1,1]],
					["47/200 - Supply, Platoon", "", "", [0,0,1,1]],
					["47/201 - Supply, AT Medium", "", "", [0,0,1,1]],
					["47/202 - Supply, AT Heavy", "", "", [0,0,1,1]],
					["47/203 - Supply, Humanitairian, Food", "", "", [0,1,0,1]],
					["47/204 - Supply, Construction, FOB", "", "", [0,1,0,1]],
					["47/205 - Supply, Humanitarian, Utility", "", "", [0,1,0,1]],
					["47/206 - Supply, Construction, COP", "", "", [0,1,0,1]]
				],
				0
			],
			true
		],
		[
			"COMBO",
			"Container Type",
			[
				_containerClasses,
				_containerNames,
				0
			],
			false
		],
		[
			"CHECKBOX",
			"Full ACE Arsenal",
			false
		]
	],				
	{
		_this call FUNC(actionRequestLogistics);
	},
	{
		// no nothing on Cancel
	},
	[_position]
] call zen_dialog_fnc_create;