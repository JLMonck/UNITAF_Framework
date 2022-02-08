#define UNITAF_Class(CLASS,PARENT,CATEGORY,SUBCATEGORY,NAME,TEXTURE) \
	class GVAR(CLASS): PARENT { \
		scope = 2; \
		scopeCurator = 2; \
		displayName = QUOTE(NAME); \
		editorCategory = QUOTE(CATEGORY); \
		editorSubcategory = QUOTE(SUBCATEGORY); \
		hiddenSelectionsTextures[] = {QUOTE(PATHTOF_SYS(PREFIX,assets,TEXTURE))}; \
		class EventHandlers { \
			init = QUOTE((_this select 0) allowdamage false); \
		}; \
		dlc = QUOTE(PREFIX); \
	};
	
#define UNITAF_Class_Tex0(CLASS,PARENT,CATEGORY,SUBCATEGORY,NAME,TEXTURE) \
	class GVAR(CLASS): PARENT { \
		scope = 2; \
		scopeCurator = 2; \
		displayName = QUOTE(NAME); \
		editorCategory = QUOTE(CATEGORY); \
		editorSubcategory = QUOTE(SUBCATEGORY); \
		class EventHandlers { \
			init = QUOTE((_this select 0) allowdamage false; (_this select 0) setObjectTextureGlobal [0,QUOTE(QUOTE(PATHTOF_SYS(PREFIX,assets,TEXTURE)))]); \
		}; \
		dlc = QUOTE(PREFIX); \
	};
#define UNITAF_Class_Tex1(CLASS,PARENT,CATEGORY,SUBCATEGORY,NAME,TEXTURE) \
	class GVAR(CLASS): PARENT { \
		scope = 2; \
		scopeCurator = 2; \
		displayName = QUOTE(NAME); \
		editorCategory = QUOTE(CATEGORY); \
		editorSubcategory = QUOTE(SUBCATEGORY); \
		class EventHandlers { \
			init = QUOTE((_this select 0) allowdamage false; (_this select 0) setObjectTextureGlobal [1,QUOTE(QUOTE(PATHTOF_SYS(PREFIX,assets,TEXTURE)))]); \
		}; \
		dlc = QUOTE(PREFIX); \
	};

#define UNITAF_Class_Flag(CLASS,PARENT,CATEGORY,SUBCATEGORY,NAME,TEXTURE) \
	class GVAR(CLASS): PARENT { \
		scope = 2; \
		scopeCurator = 2; \
		displayName = QUOTE(NAME); \
		editorCategory = QUOTE(CATEGORY); \
		editorSubcategory = QUOTE(SUBCATEGORY); \
		class EventHandlers { \
			init = QUOTE((_this select 0) allowdamage false; (_this select 0) setFlagTexture QUOTE(QUOTE(PATHTOF_SYS(PREFIX,assets,TEXTURE)))); \
		}; \
		dlc = QUOTE(PREFIX); \
	};

class SignAd_Sponsor_F;
class Flag_White_F;
class Land_Billboard_03_ygont_F;
class Banner_01_NATO_F;

// Base Signs
UNITAF_Class(Sign_Base_Warning,SignAd_Sponsor_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Sign Warning,images\signage\training\base\sign\utf-warning.jpg)

// Training Signs
UNITAF_Class(Sign_Training_MedicalA,SignAd_Sponsor_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Sign Medical A,images\signage\training\base\course\medical\utf-medicalA.jpg)
UNITAF_Class(Sign_Training_MedicalB,SignAd_Sponsor_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Sign Medical B,images\signage\training\base\course\medical\utf-medicalB.jpg)

// Flags
UNITAF_Class_Flag(Flag_UTF,Flag_White_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Flags,Flag UTF,images\signage\training\base\banner\utf-flag.jpg)

// Billboards
UNITAF_Class(Billboard_Training_Movement,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Movement,images\signage\training\movement.jpg)
UNITAF_Class(Billboard_Training_Formations,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Formations,images\signage\training\formations.jpg)
UNITAF_Class(Billboard_Training_CQBPie,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard CQB Pie,images\signage\training\cqb-pie.jpg)
UNITAF_Class(Billboard_Training_ATShots,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard AT Shots,images\signage\training\at-shots.jpg)
UNITAF_Class(Billboard_Training_Vehicle1,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Vehicle 1,images\signage\training\vehicle1.jpg)
UNITAF_Class(Billboard_Training_Vehicle2,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Vehicle 2,images\signage\training\vehicle2.jpg)
UNITAF_Class(Billboard_Training_Vehicle3,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Vehicle 3,images\signage\training\vehicle3.jpg)
UNITAF_Class(Billboard_Training_Vehicle4,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Vehicle 4,images\signage\training\vehicle4.jpg)
UNITAF_Class(Billboard_Training_FormationsBunching,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Formations Bunching,images\signage\training\formations-bunching.jpg)
UNITAF_Class(Billboard_Training_TypesOfFire,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Types of Fire,images\signage\training\types-of-fire.jpg)
UNITAF_Class(Billboard_Training_TypesOfFire2,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Types of Fire 2,images\signage\training\types-of-fire2.jpg)
UNITAF_Class(Billboard_Training_DeadSpace,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Dead Space,images\signage\training\dead-space.jpg)
UNITAF_Class(Billboard_Training_IDF,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard IDF,images\signage\training\idf.jpg)
UNITAF_Class(Billboard_Training_AmbushL,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Ambush Linear,images\signage\training\ambush-l.jpg)
UNITAF_Class(Billboard_Training_AmbushLS,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Ambush L-Shape,images\signage\training\ambush-ls.jpg)
UNITAF_Class(Billboard_Training_Flank1,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Flank 1,images\signage\training\flank1.jpg)
UNITAF_Class(Billboard_Training_Flank2,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Flank 2,images\signage\training\flank2.jpg)
UNITAF_Class(Billboard_Training_Flank3,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Flank 3,images\signage\training\flank3.jpg)

UNITAF_Class(Billboard_Base_AARS,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard AARs,images\signage\billboards\1-aars.jpg)
UNITAF_Class(Billboard_Base_Team,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard One Team One Goal,images\signage\billboards\2-one-team-one-goal.jpg)
UNITAF_Class(Billboard_Base_CPR,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard CPR,images\signage\billboards\3-cpr-cpr-check-pulse.jpg)
UNITAF_Class(Billboard_Base_Backblast,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Backblast,images\signage\billboards\4-backblast.jpg)
UNITAF_Class(Billboard_Base_Brevity,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Brevity,images\signage\billboards\5-brevity.jpg)
UNITAF_Class(Billboard_Base_Exercise,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Exercise,images\signage\billboards\6-exercise.jpg)
// 7 is broken, not n2
UNITAF_Class(Billboard_Base_Earplugs,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Earplugs,images\signage\billboards\8-earplugs.jpg)
UNITAF_Class(Billboard_Base_BigRed,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard BigRed,images\signage\billboards\9-bigred.jpg)

UNITAF_Class(Billboard_Lib_Info,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (Information),images\signage\liberation\lib_info.png)
UNITAF_Class(Billboard_Lib_Welcome,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (Welcome),images\signage\liberation\lib_welcome.png)
UNITAF_Class(Billboard_Lib_Logo,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (UNITAF Logo),images\signage\liberation\unitaf_logo.png)
UNITAF_Class(Billboard_Lib_LogoLink,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (UNITAF Logo + Link),images\signage\liberation\unitaf_logo_link.png)
UNITAF_Class(Billboard_Lib_LogoLinkPublic,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (UNITAF Logo + Link + Public),images\signage\liberation\unitaf_logo_link_public.png)
UNITAF_Class(Billboard_Lib_Apply,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Liberation,Billboard Liberation (Apply),images\signage\liberation\unitaf_apply.png)

// Banners
class Banner_01_F;
UNITAF_Class(Banner_Base_UTF,Banner_01_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Flags,Banner UTF,images\signage\ops_center\utf-banner.jpg)

// Monitors
class Land_Laptop_03_black_F;
class Land_Laptop_03_sand_F;
UNITAF_Class_Tex1(Laptop_Base_NoSignal_Black,Land_Laptop_03_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop No Signal (Black),images\signage\no-signal.jpg)
UNITAF_Class_Tex1(Laptop_Base_NoSignal_Sand,Land_Laptop_03_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop No Signal (Sand),images\signage\no-signal.jpg)

UNITAF_Class_Tex1(Laptop_Base_UTF_Black,Land_Laptop_03_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop UTF (Black),images\signage\unitaf-logo.jpg)
UNITAF_Class_Tex1(Laptop_Base_UTF_Sand,Land_Laptop_03_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop UTF (Sand),images\signage\unitaf-logo.jpg)

UNITAF_Class_Tex1(Laptop_Base_Login_Black,Land_Laptop_03_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop UTFN Login (Black),images\signage\utfn-logo.jpg)
UNITAF_Class_Tex1(Laptop_Base_Login_Sand,Land_Laptop_03_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Laptop UTFN Login (Sand),images\signage\utfn-logo.jpg)


class Land_TripodScreen_01_large_black_F;
class Land_TripodScreen_01_large_sand_F;
UNITAF_Class_Tex0(Screen_Base_NoSignal_Black,Land_TripodScreen_01_large_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen No Signal (Black),images\signage\no-signal.jpg)
UNITAF_Class_Tex0(Screen_Base_NoSignal_Sand,Land_TripodScreen_01_large_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen No Signal (Sand),images\signage\no-signal.jpg)

UNITAF_Class_Tex0(Screen_Base_UTF_Black,Land_TripodScreen_01_large_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen UTF (Black),images\signage\unitaf-logo.jpg)
UNITAF_Class_Tex0(Screen_Base_UTF_Sand,Land_TripodScreen_01_large_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen UTF (Sand),images\signage\unitaf-logo.jpg)

UNITAF_Class_Tex0(Screen_Base_Login_Black,Land_TripodScreen_01_large_black_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen UTFN Login (Black),images\signage\utfn-logo.jpg)
UNITAF_Class_Tex0(Screen_Base_Login_Sand,Land_TripodScreen_01_large_sand_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Equipment,Screen UTFN Login (Sand),images\signage\utfn-logo.jpg)

// Special
class UserTexture1m_F;
UNITAF_Class(Texture_1m_Base_BannerA,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner A,images\signage\ops_center\bannera.paa)
UNITAF_Class(Texture_1m_Base_BannerB,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner B,images\signage\ops_center\bannerb.paa)
UNITAF_Class(Texture_1m_Base_BannerC,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner C,images\signage\ops_center\bannerc.paa)
UNITAF_Class(Texture_1m_Base_BannerD,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner D,images\signage\ops_center\bannerd.paa)
UNITAF_Class(Texture_1m_Base_BannerE,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner E,images\signage\ops_center\bannere.paa)
UNITAF_Class(Texture_1m_Base_BannerF,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner F,images\signage\ops_center\bannerf.paa)
UNITAF_Class(Texture_1m_Base_BannerG,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner G,images\signage\ops_center\bannerg.paa)
UNITAF_Class(Texture_1m_Base_BannerH,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Banner H,images\signage\ops_center\bannerh.paa)

UNITAF_Class(Texture_1m_Base_Briefing,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Briefing,images\signage\ops_center\briefing.paa)
UNITAF_Class(Texture_1m_Base_OpsRoom,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Ops Room,images\signage\ops_center\ops_room.paa)
UNITAF_Class(Texture_1m_Base_AuthPers,UserTexture1m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 1m Auth Pers,images\signage\ops_center\auth_pers.paa)

class UserTexture10m_F;
UNITAF_Class(Texture_10m_Base_TextXS,UserTexture10m_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Texture 10m TextXS,images\signage\ops_center\textxs.paa)

// Boards
class Land_MapBoard_01_Wall_Altis_F;
UNITAF_Class(MapBoard_Wall_Base_Notice5,Land_MapBoard_01_Wall_Altis_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Base_Signs,Map Board Wall Notice 5,images\signage\ops_center\notice5.paa)

// Vehicle Identification
UNITAF_Class(Billboard_Training_Identification_BMP_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BMP notext),images\signage\training\identification\BMP_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_BMP,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BMP),images\signage\training\identification\BMP.jpg)
UNITAF_Class(Billboard_Training_Identification_BRDM_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BRDM notext),images\signage\training\identification\BRDM_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_BRDM,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BRDM),images\signage\training\identification\BRDM.jpg)
UNITAF_Class(Billboard_Training_Identification_BTR_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BTR notext),images\signage\training\identification\BTR_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_BTR,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (BTR),images\signage\training\identification\BTR.jpg)
UNITAF_Class(Billboard_Training_Identification_IFV_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (IFV notext),images\signage\training\identification\IFV_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_IFV,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (IFV),images\signage\training\identification\IFV.jpg)
UNITAF_Class(Billboard_Training_Identification_MBT_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (MBT notext),images\signage\training\identification\MBT_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_MBT,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (MBT),images\signage\training\identification\MBT.jpg)
UNITAF_Class(Billboard_Training_Identification_SHILKA_notext,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (SHILKA notext),images\signage\training\identification\SHILKA_notext.jpg)
UNITAF_Class(Billboard_Training_Identification_SHILKA,Land_Billboard_03_ygont_F,EdCat_UNITAF_Base,EdSubcat_UNITAF_Training,Billboard Identification (SHILKA),images\signage\training\identification\SHILKA.jpg)