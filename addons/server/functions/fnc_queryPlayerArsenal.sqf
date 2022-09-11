#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve personal Arsenal items
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryPlayerArsenal;
 *
 * Public: No
 */
 
params ["_player"];
private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
private _playerUID = getPlayerUID _player;

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	_query = '[1, [42, 1, """rhs_weap_m4a1_blockII_d"",""rhs_weap_m4a1_d"",""rhsusf_weap_glock17g4"",""rhsusf_acc_ACOG_RMR"",""rhsusf_acc_ACOG_d"",""rhsusf_acc_eotech_552"",""rhsusf_acc_eotech_552_d"",""rhsusf_acc_anpeq15side"",""rhsusf_acc_anpeq15_top"",""rhsusf_acc_anpeq15side_bk"",""rhsusf_acc_anpeq15_bk_top"",""acc_flashlight_pistol"",""rhsusf_acc_grip2"",""rhsusf_acc_grip2_tan"",""rhsusf_acc_grip1"",""rhsusf_200Rnd_556x45_box"",""rhsusf_200rnd_556x45_mixed_box"",""rhs_googles_black"",""rhs_googles_orange"",""rhs_googles_yellow"",""rhs_googles_clear"",""G_Bandanna_tan"",""rhsusf_shemagh_tan"",""rhsusf_shemagh2_tan"",""rhsusf_oakley_goggles_blk"",""rhsusf_oakley_goggles_clr"",""rhsusf_oakley_goggles_ylw"",""rhsusf_ANPVS_14"",""Binocular"",""ItemMap"",""ItemCompass"",""ItemWatch"",""rhs_mag_m18_green"",""rhs_mag_m18_purple"",""rhs_mag_m18_red"",""rhs_mag_m18_yellow"",""rhs_mag_an_m8hc"",""ACE_Chemlight_HiBlue"",""ACE_Chemlight_HiGreen"",""ACE_Chemlight_HiRed"",""ACE_Chemlight_HiWhite"",""ACE_Chemlight_HiYellow"",""ACE_Chemlight_IR"",""ACE_elasticBandage"",""ACE_bloodIV"",""ACE_bloodIV_250"",""ACE_bloodIV_500"",""ACE_bodyBag"",""ACE_CableTie"",""ACE_EarPlugs"",""ACE_epinephrine"",""ACE_Flashlight_XL50"",""ACE_MapTools"",""ACE_morphine"",""ACE_packingBandage"",""ACE_wirecutter"",""ACE_tourniquet"",""ACE_fieldDressing"",""ACE_quikclot"",""rhs_mag_30Rnd_556x45_M855A1_Stanag"",""rhs_mag_30Rnd_556x45_M855A1_PMAG"",""rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red"",""rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan"",""rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red"",""rhs_mag_m713_Red"",""rhs_mag_m714_White"",""rhs_mag_m715_Green"",""rhs_mag_m716_yellow"",""rhsusf_mag_17Rnd_9x19_JHP"",""rhsusf_mag_17Rnd_9x19_FMJ"",""rhsusf_acc_harris_bipod"",""rhsusf_shemagh_gogg_tan"",""rhsusf_shemagh2_gogg_tan"",""ACE_SpraypaintRed"",""rhs_weap_m16a4"",""rhs_weap_m16a4_carryhandle"",""rhs_weap_m4_carryhandle"",""rhs_weap_m4a1_carryhandle"",""rhsusf_acc_mrds"",""rhsusf_acc_mrds_c"",""rhsusf_acc_su230a_mrds_c"",""rhsusf_acc_su230a_mrds"",""ACE_adenosine"",""rhs_mag_m67"",""rhsusf_acc_M952V"",""rhsusf_acc_anpeq15_bk"",""rhsusf_acc_anpeq15"",""rhsusf_acc_nt4_black"",""rhsusf_acc_nt4_tan"",""rhsusf_acc_rotex5_grey"",""rhsusf_acc_rotex5_tan"",""rhsusf_acc_rotex_mp7"",""rhsusf_acc_rotex_mp7_desert"",""ACE_muzzle_mzls_L"",""rhsusf_acc_grip3_tan"",""rhsusf_acc_grip3"",""rhsusf_acc_tdstubby_tan"",""rhsusf_acc_tdstubby_blk"",""rhsusf_acc_rvg_blk"",""rhsusf_acc_rvg_de"",""rhsusf_acc_grip4"",""rhsusf_acc_compm4"",""rhsusf_acc_g33_T1"",""rhsusf_acc_su230a"",""rhsusf_acc_su230a_c"",""rhsusf_weap_m9"",""rhsusf_weap_m1911a1"",""rhsusf_acc_T1_high"",""rhsusf_acc_T1_low"",""rhsusf_acc_T1_low_fwd"",""rhsusf_acc_SF3P556"",""rhsusf_acc_SFMB556"",""rhs_mag_M433_HEDP"",""rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red"",""rhs_mag_M585_white"",""rhs_mag_m661_green"",""rhsusf_100Rnd_556x45_mixed_soft_pouch"",""rhsusf_100Rnd_556x45_soft_pouch"",""rhsusf_acc_tacsac_blk"",""rhsusf_acc_tacsac_blue"",""rhsusf_acc_tacsac_tan"",""rhsusf_acc_omega9k"",""rhsusf_mag_7x45acp_MHP"",""rhs_weap_m4a1"",""G_Spectacles"",""rhsusf_100Rnd_762x51"",""rhsusf_100Rnd_762x51_m62_tracer"",""rhs_mag_maaws_HE"",""rhs_mag_maaws_HEDP"",""rhs_mag_maaws_HEAT"",""ACE_surgicalKit"",""ACE_EntrenchingTool"",""ACE_M84"",""rhsusf_acc_saw_bipod"",""rhsusf_acc_grip4_bipod"",""rhsusf_acc_saw_lw_bipod"",""rhs_weap_m4a1_blockII"",""rhsusf_acc_ACOG3"",""ACE_Tripod"",""ACE_VMH3"",""DemoCharge_Remote_Mag"",""rhsusf_ANPVS_15"",""ItemGPS"",""ACE_splint"",""rhs_weap_m4_carryhandle_mstock"",""rhs_weap_m4_mstock"",""rhs_weap_m4a1_carryhandle_mstock"",""rhs_weap_m4a1_blockII_bk"",""rhs_weap_m4a1_blockII_KAC_bk"",""rhs_weap_m4a1_blockII_KAC_d"",""rhs_weap_m4a1_blockII_KAC"",""rhs_weap_m4a1_mstock"",""rhs_weap_m4a1_wd"",""rhs_weap_m4a1_wd_mstock"",""rhs_weap_rsp30_white"",""rhs_weap_rsp30_green"",""rhs_weap_rsp30_red"",""ACE_Can_RedGull"",""ACE_personalAidKit"",""ACE_SpraypaintGreen"",""ACE_SpraypaintBlue"",""ACE_SpraypaintBlack"",""ACE_NVG_Wide"",""TFAR_rf7800str"",""TFAR_anprc152"",""TFAR_anprc148jem"",""rhs_fgm148_magazine_AT"",""rhs_mag_M397_HET"",""ItemRadio"",""rhs_weap_m4a1_blockII_wd"",""rhs_weap_m4a1_blockII_KAC_wd"",""rhs_weap_m4"",""rhs_weap_m16a4_imod"",""VSM_M81_Boonie"",""VSM_M81_Cap"",""VSM_Mich2000_M81"",""VSM_Mich2000_2_M81"",""VSM_M81_OPS"",""VSM_M81_OPS_2"",""VSM_Peltor_M81"",""rhsusf_ach_helmet_M81"",""rhs_Booniehat_m81"",""VSM_M81_Crye_Camo"",""VSM_M81_Crye_SS_Camo"",""VSM_FAPC_Breacher_M81"",""VSM_FAPC_MG_M81"",""VSM_FAPC_Operator_M81"",""VSM_M81_carryall"",""VSM_M81_Backpack_Compact"",""VSM_M81_Backpack_Kitbag"",""VSM_CarrierRig_Breacher_M81"",""VSM_CarrierRig_Gunner_M81"",""VSM_CarrierRig_Operator_M81"",""VSM_Shemagh_OD"",""VSM_Shemagh_tan"",""VSM_Shemagh_Glasses_OD"",""VSM_Shemagh_glasses_tan"",""VSM_Shemagh_Goggles_OD"",""VSM_Shemagh_goggles_tan"",""G_Bandanna_oli"",""rhsusf_shemagh_gogg_grn"",""rhsusf_shemagh2_gogg_grn"",""rhsusf_shemagh_gogg_od"",""rhsusf_shemagh2_gogg_od"",""rhsusf_shemagh2_od"",""rhsusf_shemagh_od"",""rhsusf_shemagh_grn"",""rhsusf_shemagh2_grn"",""rhs_weap_mk17_CQC"",""rhs_weap_mk17_LB"",""rhs_weap_mk17_STD"",""rhs_mag_20Rnd_SCAR_762x51_m118_special"",""rhs_mag_20Rnd_SCAR_762x51_mk316_special"",""rhs_mag_20Rnd_SCAR_762x51_m80a1_epr"",""rhs_mag_20Rnd_SCAR_762x51_m80_ball"",""rhs_mag_20Rnd_SCAR_762x51_m62_tracer"",""rhs_mag_20Rnd_SCAR_762x51_m61_ap"""]]';
	_result = (parseSimpleArray _query);
	[QEGVAR(ClientEvent,PlayerArsenal), (_result select 1), [_player]] call CBA_fnc_targetEvent;
};

// @TODO: query must be updated to support personal arsenals based on ORBAT role
private _query = "extDB3" callExtension format ["0:FETCHDATA:SELECT faction, rankid, CONCAT('[',inventory,']') as inv FROM arsenals WHERE faction = (SELECT faction FROM operations WHERE id = '%1') LIMIT 1", _operationID];
//private _query = "extDB3" callExtension "0:FETCHDATA:SELECT faction, rankid, CONCAT('[',inventory,']') as inv FROM arsenals WHERE faction = 1 LIMIT 1";
private _result = (parseSimpleArray _query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving Player Arsenal";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		// only get the first result, fix into actual array (instead of comma seperated string)
		[QEGVAR(ClientEvent,PlayerArsenal), (_result select 1), [_player]] call CBA_fnc_targetEvent;
	};
	default {
		diag_log "extDB3: Something went wrong with Player Arsenal";
		diag_log format["Database Result: %1", _result];
	};
};