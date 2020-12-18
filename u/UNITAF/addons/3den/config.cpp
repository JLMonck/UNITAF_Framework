#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "unitaf_main"
        };
        author = "$STR_unitaf_main_Author";
        url = "$STR_unitaf_main_URL";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
//#include "CfgVehicles.hpp"