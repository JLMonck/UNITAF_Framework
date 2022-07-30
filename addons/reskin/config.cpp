#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            // CfgVehicles_Vehicles
            QGVAR(Training_Van_Black),
            QGVAR(Training_Van_Khaki),
            QGVAR(Training_Offroad_Black),
            QGVAR(Training_Offroad_Khaki),
            QGVAR(Training_Offroad_KhakiCI),
            // CgfVehicles_Signs
            QGVAR(Sign_Base_Warning),
            QGVAR(Sign_Training_MedicalA),
            QGVAR(Sign_Training_MedicalB),
            QGVAR(Flag_UTF),
            QGVAR(Billboard_Training_Movement),
            QGVAR(Billboard_Training_Formations),
            QGVAR(Billboard_Training_CQBPie),
            QGVAR(Billboard_Training_ATShots),
            QGVAR(Billboard_Training_Vehicle1),
            QGVAR(Billboard_Training_Vehicle2),
            QGVAR(Billboard_Training_Vehicle3),
            QGVAR(Billboard_Training_Vehicle4),
            QGVAR(Billboard_Training_FormationsBunching),
            QGVAR(Billboard_Training_TypesOfFire),
            QGVAR(Billboard_Training_TypesOfFire2),
            QGVAR(Billboard_Training_DeadSpace),
            QGVAR(Billboard_Training_IDF),
            QGVAR(Billboard_Training_AmbushL),
            QGVAR(Billboard_Training_AmbushLS),
            QGVAR(Billboard_Training_Flank1),
            QGVAR(Billboard_Training_Flank2),
            QGVAR(Billboard_Training_Flank3),
            QGVAR(Billboard_Base_AARS),
            QGVAR(Billboard_Base_Team),
            QGVAR(Billboard_Base_CPR),
            QGVAR(Billboard_Base_Backblast),
            QGVAR(Billboard_Base_Brevity),
            QGVAR(Billboard_Base_Exercise),
            QGVAR(Billboard_Base_Earplugs),
            QGVAR(Billboard_Base_BigRed),
            QGVAR(Banner_Base_UTF),
            QGVAR(Laptop_Base_NoSignal_Black),
            QGVAR(Laptop_Base_NoSignal_Sand),
            QGVAR(Laptop_Base_UTF_Black),
            QGVAR(Laptop_Base_UTF_Sand),
            QGVAR(Laptop_Base_Login_Black),
            QGVAR(Laptop_Base_Login_Sand),
            QGVAR(Screen_Base_NoSignal_Black),
            QGVAR(Screen_Base_NoSignal_Sand),
            QGVAR(Screen_Base_UTF_Black),
            QGVAR(Screen_Base_UTF_Sand),
            QGVAR(Screen_Base_Login_Black),
            QGVAR(Screen_Base_Login_Sand),
            QGVAR(Texture_1m_Base_BannerA),
            QGVAR(Texture_1m_Base_BannerB),
            QGVAR(Texture_1m_Base_BannerC),
            QGVAR(Texture_1m_Base_BannerD),
            QGVAR(Texture_1m_Base_BannerE),
            QGVAR(Texture_1m_Base_BannerF),
            QGVAR(Texture_1m_Base_BannerG),
            QGVAR(Texture_1m_Base_BannerH),
            QGVAR(Texture_1m_Base_Briefing),
            QGVAR(Texture_1m_Base_OpsRoom),
            QGVAR(Texture_1m_Base_AuthPers),
            QGVAR(Texture_10m_Base_TextXS),
            QGVAR(MapBoard_Wall_Base_Notice5)
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QMAIN_ADDON
        };
        author = ECSTRING(main,author);
        url = ECSTRING(main,url);
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
