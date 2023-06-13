// fix ACE Interactions for all vehicles
class AllVehicles;

class Air: AllVehicles {
	tf_range = 30000;
	class ACE_SelfActions;
};
class Plane: Air {};
class Plane_Base_F: Plane {};
class Helicopter: Air {};
class Helicopter_Base_F: Helicopter {};
class Helicopter_Base_H: Helicopter_Base_F {};
class Plane_Civil_01_base_F: Plane_Base_F {};
class C_Plane_Civil_01_racing_F: Plane_Civil_01_base_F {};

class Ship: AllVehicles {
	tf_range = 30000;
	class ACE_SelfActions;
};
class Ship_F: Ship {};
class StaticShip;
class CUP_StaticShip: StaticShip {
	tf_range = 30000;
	class ACE_SelfActions;
};
class CUP_StaticLPDShip: StaticShip {
	tf_range = 30000;
	class ACE_SelfActions;
};
class Boat_f;
class Rubber_duck_base_F: Boat_f {
	tf_range = 30000;
	class ACE_SelfActions;
};

class Land: AllVehicles {
	tf_range = 30000;
	class ACE_SelfActions;
};
class LandVehicles: Land {};
class Car: LandVehicles {};
class Tank: Car {};
class Tank_F: Tank {};
class APC_Tracked_02_base_F: Tank_F {};
class Car_F: Car {};
class Truck_F: Car_F {};
class Wheeled_APC_F: Car_F {};
class MRAP_01_base_F: Car_F {};
//class CUP_Ural_BaseTurret: Truck_F {};
// added here to prevent duplicate classes
MACRO_VEC_ISOLATION_LR(CUP_Ural_BaseTurret,Truck_F,0.6,1);                                 // different variants, should be enough though
class CUP_BM21_Base: CUP_Ural_BaseTurret {};

// CUP_AirVehicles_*
MACRO_VEC_ISOLATION_LR(CUP_A10_Base,Plane_Base_F,0.5,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AH1Z_base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AH6_BASE,Helicopter_Base_H,0.3,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AH64_base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ambient_A330_Base,Plane_Base_F,0.7,1,1);            // no interior, but still flyable
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ambient_B737_Base,Plane_Base_F,0.7,1,1);            // no interior, but still flyable
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ambient_Cessna172_Base,Plane_Base_F,0.7,1,1);       // no interior, but still flyable
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AN2_Base,Plane_Base_F,0.7,1,1);
MACRO_VEC_ISOLATION_LR(CUP_AV8B_Base,Plane,0.7,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AW159_Unarmed_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_C130J_Base,Plane_Base_F,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_CH47F_base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_CH53E_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_DC3_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR(CUP_F35B_base,Plane,0.7,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Merlin_HC3_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_KA50_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ka52_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ka60_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_L39_base,Plane_Base_F,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MH47E_base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MH60S_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MI6A_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Mi8_base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Mi24_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MI35_TOH_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_I_Plane_ION,C_Plane_Civil_01_racing_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_C_Plane_Orbit,C_Plane_Civil_01_racing_F,0.6,1,1);
// CUP_MQ9_Base - Drone, so no radio/isolation/intercom
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_MV22_USMC,Plane_Base_F,0.7,1,1);
// CUP_Pchela1T_Base - Drone, so no radio/isolation/intercom
MACRO_VEC_ISOLATION_LR_Intercom(CUP_SA330_Base,Helicopter_Base_H,0.7,1,1);
MACRO_VEC_ISOLATION_LR(CUP_Su25_base,Plane,0.7,1);
MACRO_VEC_ISOLATION_LR(CUP_SU34_BASE,Plane,0.7,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_UH1H_base,Helicopter_Base_H,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_UH1Y_Base,Helicopter_Base_H,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_UH1Y_UNA_USMC,CUP_B_UH1Y_Base,0.4,1,1);    // same as above just no doors, so less isolation
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Uh60_Base,Helicopter_Base_H,0.6,1,1);


// CUP_TrackedVehicles_*
MACRO_VEC_ISOLATION_LR_Intercom(CUP_2S6_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_AAV_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BMP1_base,APC_Tracked_02_base_F,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BMP3_Base,Tank_F,0.9,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_M2Bradley_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_FV432_Bulldog_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Challenger2_base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_FV510_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_LCAC_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Leopard2_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_M1_Abrams_base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_M60A3_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_M113_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_M270_HE_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MCV80_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_MTLB_Base,Tank_F,1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_T34_Base,Tank_F,0.9,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_T55_Base,Tank_F,0.9,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_T72_Base,Tank_F,0.9,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_T90_Base,Tank_F,0.9,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_ZSU23_Base,Tank_F,0.9,1,1);


// CUP_WaterVehicles_*
MACRO_VEC_LR(CUP_Fishing_Boat_Base,Ship_F,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Frigate_Base,Ship_F,1,1,1);
MACRO_VEC_ISOLATION_LR(CUP_LCU1600_Base,Ship_F,0.1,1);
MACRO_VEC_ISOLATION_LR(CUP_LCVP_Base,Ship_F,0.1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_LHD_BASE,CUP_StaticShip,1,1,1);         // LHD aka "Landing Helicopter Dock, Wasp-class", static?
MACRO_VEC_ISOLATION_LR_Intercom(CUP_LPD_BASE,CUP_StaticLPDShip,1,1,1);      // LPD aka "LPD 28 San Antonio", static?
MACRO_VEC_ISOLATION_LR(CUP_MK10_Base,Ship_F,0.1,1);
MACRO_VEC_LR(CUP_O_PBX_RU,Rubber_duck_base_F,1);
MACRO_VEC_LR(CUP_RHIB_Base,Ship_F,1);
//CUP_Seafox_Base: Ship_F       // Seafox (target)
MACRO_VEC_LR(CUP_B_Zodiac_USMC,Rubber_duck_base_F,1);


// CUP_WheeledVehicles_*
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BRDM2_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BTR40_MG_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BTR60_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BTR80A_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BTR80_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BTR90_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BAF_Coyote_BASE_D,Car_F,0.1,1,1);
MACRO_VEC_ISOLATION(CUP_Datsun_Base,Car_F,0.6);                                             // Civilian car, no LR
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Dingo_Base,MRAP_01_base_F,0.8,1,1);
MACRO_VEC_ISOLATION_LR(CUP_Hilux_Base,Car_F,0.4,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_HMMWV_Base,Car_F,0.7,1,1);
MACRO_VEC_ISOLATION_LR(CUP_Ikarus_Base,Car_F,0.6,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_BAF_Jackal2_BASE_D,Car_F,0.1,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Kamaz_5350_Base,Truck_F,0.6,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Kamaz_5350_Open_Base,CUP_Kamaz_5350_Base,0.4,1,0);      // Open Truck, no intercom and reduced isolation
MACRO_VEC_ISOLATION(CUP_Lada_Base,Car_F,0.6);                                               // Civilian car, no LR
MACRO_VEC_ISOLATION_LR_Intercom(CUP_LAV25_Base,Wheeled_APC_F,0.7,1,1);
MACRO_VEC_ISOLATION_LR(CUP_LR_Base,Car_F,0.6,1);
MACRO_VEC_ISOLATION_LR(CUP_LR_MG_Base,CUP_LR_Base,0.2,1);                                   // Open vehicle, reduced isolation
MACRO_VEC_ISOLATION_LR_Intercom(CUP_LR_Ambulance_Base,CUP_LR_Base,0.6,1,1);                 // Ambulance variant, add intercom
MACRO_VEC_ISOLATION_LR(CUP_LR_Special_Base,CUP_LR_Base,0.2,1);                              // Open vehicle, reduced isolation
MACRO_VEC_ISOLATION_LR(CUP_LR_SPG9_Base,CUP_LR_Base,0.2,1);                                 // Open vehicle, reduced isolation
// LSV - default A3 vehicles, just reskins, should work without an issue
// CUP_M1030_Base: Motorcycle
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Mastiff_Base,Wheeled_APC_F,0.8,1,1);
// MATV - default A3 vehicles, just reskins, should work without an issue
MACRO_VEC_ISOLATION_LR(CUP_MTVR_Base,Car_F,0.8,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_MTVR_USA,CUP_MTVR_Base,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_MTVR_USMC,CUP_MTVR_Base,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_I_MTVR_RACS,CUP_MTVR_Base,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_MTVR_BAF_DES,CUP_MTVR_Base,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_MTVR_BAF_WOOD,CUP_MTVR_Base,0.8,1,1);
MACRO_VEC_ISOLATION(CUP_C_Octavia_CIV,Car_F,0.6);                                           // Civilian car, no LR
// Offroad - default A3 vehicles, just reskins, should work without an issue
MACRO_VEC_ISOLATION_LR_Intercom(CUP_RG31_BASE,Car_F,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Ridgback_Base,Wheeled_APC_F,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_B_RM70_Base,CUP_BM21_Base,0.8,1,1);
MACRO_VEC_ISOLATION_LR_Intercom(CUP_S1203_Base,Car_F,0.6,1,1);
MACRO_VEC_ISOLATION(CUP_Skoda_Base,Car_F,0.6);
// Strider - default A3 vehicles, just reskins, should work without an issue
MACRO_VEC_ISOLATION_LR_Intercom(CUP_StrykerBase,Wheeled_APC_F,0.8,1,1);                     // CUP version has tfar support, but no intercom
MACRO_VEC_ISOLATION_LR(CUP_SUV_Base,Car_F,0.7,1);
MACRO_VEC_ISOLATION_LR(CUP_C_SUV_TK,CUP_SUV_Base,0.7,0);                                    // Civilian variant, no LR
MACRO_VEC_ISOLATION_LR(CUP_C_SUV_CIV,CUP_SUV_Base,0.7,0);                                   // Civilian variant, no LR
MACRO_VEC_ISOLATION_LR_Intercom(CUP_T810_Base,Car_F,0.7,1,1);
MACRO_VEC_LR(CUP_TowingTractor_Base,Car_F,1);                                               // LR only
MACRO_VEC_ISOLATION(CUP_Tractor_Base,Car_F,0.3);                                            // Civilian vehicle, no LR
// CUP_TT650_Base: Motorcycle
MACRO_VEC_ISOLATION_LR(CUP_UAZ_Base,Car_F,0.6,1);
MACRO_VEC_ISOLATION_LR(CUP_UAZ_Armed_Base,CUP_UAZ_Base,0.1,1);                              // Open vehicle, reduced isolation
class CUP_UAZ_Unarmed_Base: CUP_UAZ_Base {};
MACRO_VEC_ISOLATION_LR(CUP_UAZ_Open_Base,CUP_UAZ_Unarmed_Base,0.1,1);                       // Open vehicle, reduced isolation
MACRO_VEC_ISOLATION_LR_Intercom(CUP_UpHMMWV_Base,Car_F,0.7,1,1);
// added sooner due to inheritence
//MACRO_VEC_ISOLATION_LR(CUP_Ural_BaseTurret,Truck_F,0.6,1);                                 // different variants, should be enough though
MACRO_VEC_ISOLATION_LR(CUP_V3S_Open_Base,Car_F,0.6,1);                                      // different variants, should be enough though
// Van - default A3 vehicles, just reskins, should work without an issue
MACRO_VEC_ISOLATION_LR_Intercom(CUP_GAZ_Vodnik_Base,Wheeled_APC_F,0.6,1,1);
MACRO_VEC_ISOLATION(CUP_Volha_Base,Car_F,0.6);                                              // Civilian car, no LR
MACRO_VEC_ISOLATION_LR(CUP_O_Volha_SLA,CUP_Volha_Base,0.6,1);                               // Militia variant, add LR
MACRO_VEC_ISOLATION(CUP_C_Golf4_Base,Car_F,0.6);                                            // Civilian car, no LR
MACRO_VEC_ISOLATION_LR_Intercom(CUP_Wolfhound_Base,Wheeled_APC_F,0.8,1,1);