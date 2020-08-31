#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_main",
            "cba_xeh",
            "acex_headless"
        };
        author = "$STR_unitaf_main_Author";
        url = "$STR_unitaf_main_URL";
        VERSION_CONFIG;
    };
};

class CfgMods {
    class PREFIX {
        dir = "@UNITAF_Framework";
        name = "UNITAF - Framework";
        picture = "";
        hidePicture = "true";
        hideName = "true";
        actionName = "Website";
        action = "$STR_unitaf_main_URL";
        description = "This work is licensed under ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)";
    };
};

#include "CfgEventHandlers.hpp"

class CfgFactionClasses {
    class Faction_UNITAF {
        displayName = "[UNITAF]";
        side = 1;
        // icon = "";
        // flag = "";
        priority = 1;
    };
};
class CfgEditorCategories {
    class EdCat_UNITAF {
        displayName = "[UNITAF]";
    };
};
class CfgEditorSubcategories
{
    class EdSubcat_UNITAF_Base {
		displayName = "Base";
	};
	class EdSubcat_UNITAF_Training {
		displayName = "Training";
	};
    class EdSubcat_UNITAF_Logistics {
		displayName = "Logistics";
	};
};

// Minor Easter Egg
class CfgVehicles {
    class Land_FlatTV_01_F;

    class UNITAF_GamerScreen: Land_FlatTV_01_F {
        displayName = "Gamer Screen";
        class EventHandlers {
			init = QUOTE((_this select 0) remoteExec ['BIS_fnc_laptopPlayVideo', 0]);
		};
    };
};