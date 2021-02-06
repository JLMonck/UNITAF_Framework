#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // GET LIST WITH
            // ("(getNumber (_x >> 'scope') >= 2) && (configName _x) isKindOf 'UNITAF_logistics_Container_Base'" configClasses (configFile >> "CfgVehicles")) apply { configName _x };
            "UNITAF_logistics_DroneCase_150_White","UNITAF_logistics_DroneCase_150_White_Medical","UNITAF_logistics_DroneCase_150_LightGreen","UNITAF_logistics_DroneCase_150_LightGreen_Medical","UNITAF_logistics_DroneCase_150_Olive","UNITAF_logistics_DroneCase_150_Olive_Medical","UNITAF_logistics_DroneCase_150_Black","UNITAF_logistics_DroneCase_150_Yellow_Medical","UNITAF_logistics_DroneCase_150_Red_Medical","UNITAF_logistics_DroneCase_150_Swifd","UNITAF_logistics_DroneCase_150_IDAP","UNITAF_logistics_MetalCase_300","UNITAF_logistics_PlasticCase_300_Sand","UNITAF_logistics_PlasticCase_300_Sand_CBRN","UNITAF_logistics_PlasticCase_300_Black","UNITAF_logistics_PlasticCase_300_Black_CBRN","UNITAF_logistics_PlasticCase_300_Olive","UNITAF_logistics_PlasticCase_300_Olive_CBRN","UNITAF_logistics_PlasticCase_300_White","UNITAF_logistics_PlasticCase_300_White_IPAD","UNITAF_logistics_MetalCase_500","UNITAF_logistics_PlasticCase_500_Sand","UNITAF_logistics_PlasticCase_500_Sand_CBRN","UNITAF_logistics_PlasticCase_500_Black","UNITAF_logistics_PlasticCase_500_Black_CBRN","UNITAF_logistics_PlasticCase_500_Olive","UNITAF_logistics_PlasticCase_500_Olive_CBRN","UNITAF_logistics_PlasticCase_500_White","UNITAF_logistics_PlasticCase_500_White_IPAD","UNITAF_logistics_MetalCase_1000","UNITAF_logistics_PlasticCase_1000_Sand","UNITAF_logistics_PlasticCase_1000_Sand_CBRN","UNITAF_logistics_PlasticCase_1000_Black","UNITAF_logistics_PlasticCase_1000_Black_CBRN","UNITAF_logistics_PlasticCase_1000_Olive","UNITAF_logistics_PlasticCase_1000_Olive_CBRN","UNITAF_logistics_PlasticCase_1000_White","UNITAF_logistics_PlasticCase_1000_White_IPAD"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "unitaf_main",
            "A3_Air_F_Orange",
			"A3_Structures_F_Heli"
            // "A3_Props_F_Enoch"
        };
        author = "$STR_unitaf_main_Author";
        url = "$STR_unitaf_main_URL";
        VERSION_CONFIG;
    };
};
//#include "CfgAddons.hpp"

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgSupplies.hpp"