#include "script_component.hpp"

class CfgPatches {
	class ADDON {
        name = "Legacy main menu";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "unitaf_main"
        };
        author = "Freddo";
        url = "$STR_unitaf_main_URL";
        VERSION_CONFIG;
	};
};