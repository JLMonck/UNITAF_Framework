#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // Empty Containers
            QGVAR(Container_Medium_White),
            QGVAR(Container_Medium_Sand),
            QGVAR(Container_Medium_Military_Green),
            QGVAR(Container_Medium_Grey),
            QGVAR(Container_Small_White),
            QGVAR(Container_Small_Sand),
            QGVAR(Container_Small_Military_Green),
            QGVAR(Container_Small_Grey),
            QGVAR(Container_Sling_Ammo),
            QGVAR(Container_Sling_Cargo),
            QGVAR(Container_Sling_Fuel),
            QGVAR(Container_Sling_Medevac),
            QGVAR(Container_Sling_Repair),
            // Prefilled Containers
            QGVAR(Container_Medium_Supply_Platoon)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
         requiredAddons[] = {
            "unitaf_main",
        };
        author = "$STR_unitaf_main_Author";
        url = "$STR_unitaf_main_URL";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"