#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

ADDON = true;

// Add Custom modules is ZEN is available
if (isClass(configFile >> "CfgPatches" >> "zen_custom_modules")) then {
	// Logistics Request
	[
		"[UNITAF]",
		"Logistics Request",
		{
			params ["_position", "_object"];
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
							[
								// Medium Containers
								QGVAR(Container_Medium_White),
								QGVAR(Container_Medium_Grey),
								QGVAR(Container_Medium_Military_Green),
								QGVAR(Container_Medium_Sand),
								// Small Containers
								QGVAR(Container_Small_White),
								QGVAR(Container_Small_Grey),
								QGVAR(Container_Small_Military_Green),
								QGVAR(Container_Small_Sand),
								// Huron Slingload
								QGVAR(Container_Sling_Ammo),
								QGVAR(Container_Sling_Cargo),
								QGVAR(Container_Sling_Fuel),
								QGVAR(Container_Sling_Medevac),
								QGVAR(Container_Sling_Repair)
							],
							[
								// Medium Containers
								"Container Medium (White)",
								"Container Medium (Grey)",
								"Container Medium (Military Green)",
								"Container Medium (Sand)",
								// Small Containers
								"Container Small (White)",
								"Container Small (Grey)",
								"Container Small (Military Green)",
								"Container Small (Sand)",
								// Huron Slingload
								"Huron Ammo Container",
								"Huron Cargo Container",
								"Huron Fuel Container",
								"Huron Medical Container",
								"Huron Repair Container"
							],
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
					params ["_values", "_arguments"];
					_values params ["_config", "_type", "_arsenal"];
					_arguments params ["_position"];

					// Create container
					_container = createVehicle [_type, [_position select 0, _position select 1, 0]];

					if (_arsenal) then {
						// If ACE Arsenal, add ALL items to container
						[_container, true] call ace_arsenal_fnc_initBox;
					} else {
						// Get content from list or DB
						_contents = [_config] call FUNC(getSupplyContents);

						// empty out container
						clearItemCargoGlobal _container;
						// Add items to container
						{
							_container addItemCargoGlobal [_x select 0, _x select 1];
						} count _contents;
					};
				},
				{
					// no nothing on Cancel
				},
				[_position]
			] call zen_dialog_fnc_create;
		},
		""	// Icon
	] call zen_custom_modules_fnc_register;
};