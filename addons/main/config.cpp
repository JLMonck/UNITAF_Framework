#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "A3_Data_F_Oldman_Loadorder",
            "cba_main",
            "cba_xeh",
            "cba_settings",
            "cba_keybinding"
        };
        author = ECSTRING(main,author);
        url = ECSTRING(main,url);
        VERSION_CONFIG;
    };
};

class CfgMods {
    class PREFIX {
        dir = "@UNITAF_Framework";
        author = ECSTRING(main,author);
        url = ECSTRING(main,url);
        name = "UNITAF - Framework";
        hidePicture = 0;
        hideName = 1;
        actionName = "Website";


        description = "This work is licensed under ARMA PUBLIC LICENSE SHARE ALIKE (APL-SA)";

        //artwork = "\u\UNITAF\addons\main\ui\unitaf_icon.paa";
        picture = "\u\unitaf\addons\main\ui\unitaf_icon.paa";
        logo = "\u\unitaf\addons\main\ui\unitaf_icon.paa";
        logoOver = "\u\unitaf\addons\main\ui\unitaf_icon.paa";
        logoSmall = "\u\unitaf\addons\main\ui\unitaf_icon.paa";
        logoTitle = "\u\unitaf\addons\main\ui\unitaf_icon.paa";
        //video = "\u\UNITAF\addons\main\ui\unitaf_icon.paa";
        contentBrowserPicture = "\u\unitaf\addons\main\ui\unitaf_logo.jpg";

        overview = "Mission Framework for UNITAF servers.";
        overviewPicture = "\u\unitaf\addons\main\ui\unitaf_logo.jpg";
        overviewText = "Mission Framework for UNITAF servers.";
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
class CfgVehicleClasses {
    class EdSubcat_UNITAF_Logistics_Empty {
		displayName = "Containers (Empty)";
	};
    class EdSubcat_UNITAF_Logistics_Prebuild {
		displayName = "Containers (Prebuild)";
	};
};
class CfgEditorCategories {
    class EdCat_UNITAF_Base {
        displayName = "[UNITAF Base]";
    };
    class EdCat_UNITAF_Logistics {
        displayName = "[UNITAF Logistics]";
    };
};
class CfgEditorSubcategories {
	class EdSubcat_UNITAF_Training {
		displayName = "Training";
	};
    class EdSubcat_UNITAF_Liberation {
        displayName = "Liberation";
    };
    class EdSubcat_UNITAF_Logistics_Empty {
		displayName = "Containers (Empty)";
	};
    class EdSubcat_UNITAF_Logistics_Prebuild {
		displayName = "Containers (Prebuild)";
	};

    class EdSubcat_UNITAF_Base_Flags {
		displayName = "Flags";
	};
    class EdSubcat_UNITAF_Base_Signs {
		displayName = "Signs";
	};
    class EdSubcat_UNITAF_Base_Equipment {
		displayName = "Equipment";
	};
};

// Minor Easter Egg
class CfgVehicles {
    class Land_FlatTV_01_F;

    class UNITAF_GamerScreen: Land_FlatTV_01_F {
        displayName = "Gamer Screen (ArmA: Cold War Assault)";
        editorCategory = QUOTE(EdCat_UNITAF_Base);
		editorSubcategory = QUOTE(EdSubcat_UNITAF_Base_Equipment);
        class EventHandlers {
			init = QUOTE((_this select 0) remoteExec ['BIS_fnc_laptopPlayVideo', 0]);
		};
    };
};

// Discord Rich Presence
class CfgDiscordRichPresence {
    applicationID           = "753242663616249906";         // Provided by discord
    defaultDetails          = "UNITAF Operation";           // Upper text
    defaultState            = "unitedtaskforce.net";        // Lower text
    defaultLargeImageKey    = "unitaf";                     // Large image
    defaultLargeImageText   = "";                           // Large image hover text
    defaultSmallImageKey    = "arma3-logo";                 // Small image
    defaultSmallImageText   = "";                           // Small image hover text
    useTimeElapsed          = 1;                            // Show time elapsed since the player connected (1 - true, 0 - false)
};

/*
// Remove complete center bar with 3 squares
class RscStandardDisplay;
class RscDisplayMain: RscStandardDisplay {
//	enableDisplay = 0;
	delete Spotlight;
//	class controls {
//		delete Spotlight1;
//		delete Spotlight2;
//		delete Spotlight3;
//		delete BackgroundSpotlightRight;
//		delete BackgroundSpotlightLeft;
//		delete BackgroundSpotlight;
//	};
};

// Custom "Spotlight" blocks for quick access to UNITAF servers
class CfgMainMenuSpotlight {
    // remove default ones
    delete OldMan;
    delete Bootcamp;
    delete EastWind;
    delete ApexProtocol;
    delete Orange_Showcase_IDAP;
    delete Orange_Showcase_LoW;
    delete Orange_CampaignGerman;
    delete Orange_Campaign;
    delete Tanks_Campaign_01;
    delete Showcase_TankDestroyers;

    delete Contact_Campaign;
    delete Tacops_Campaign_03;
    delete Tacops_Campaign_02;
    delete Tacops_Campaign_01;

    // add custom spotlights
    class UNITAF_Liberation {
        text            = "[UNITAF] Liberation";
        textIsQuote     = 0;
        //picture         = "\amp_spotlight\button.paa";
        video           = "\a3\Ui_f\Video\spotlight_1_Apex.ogv";
        action          = QUOTE([_this, '88.99.211.37', '2302', ''] call FUNC(joinServer));
        actionText      = "Join server: [UNITAF] EU1 - KP Liberation";
        condition       = "true";
    };
    class UNITAF_Operations {
        text            = "[UNITAF] Operations";
        textIsQuote     = 0;
        //picture         = "\amp_spotlight\button.paa";
        video           = "\a3\Ui_f\Video\spotlight_1_Apex.ogv";
        action          = QUOTE([_this, '88.99.211.37', '2402', ''] call FUNC(joinServer));
        actionText      = "Join server: [UNITAF] Operation Server";
        condition       = "true";
    };
};
*/
