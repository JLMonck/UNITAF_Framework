#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		addonRootClass = "unitaf_mainmenu";
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {
            "unitaf_mainmenu",
            "unitaf_mainmenu_removemenu"
        };
		units[] = {};
		weapons[] = {};
	};
};

#include "RscDisplayMain.hpp"
#include "CfgScriptPaths.hpp"

class CfgFunctions {
    class ADDON {
        class MainMenu {
            class background {
                preInit = 1;		// (formerly known as "forced") 1 to call the function upon mission start, before objects are initialized. Passed arguments are ["preInit"]
				//postInit = 1;		// 1 to call the function upon mission start, after objects are initialized. Passed arguments are ["postInit", didJIP]
				//preStart = 1;		// 1 to call the function upon game start, before title screen, but after all addons are loaded (config.cpp only)
                file = "\u\unitaf\addons\mainmenu\newmenu\fnc_background.sqf";
            };
        };
    };
};