#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		addonRootClass = "unitaf_mainmenu";

		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {
            "unitaf_mainmenu",
            "ace_optionsmenu",  // adds crap
            "ace_arsenal",      // adds crap
            "cba_settings"      // adds crap
        };
		units[] = {};
		weapons[] = {};
	};
};

#include "RscDisplayMain.hpp"


class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMain {
        ACE_optionsmenu_loadMainMenuBox = "";
    };
};