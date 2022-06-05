#include "script_component.hpp"
/*
Data pushed to unitaf_logistics_crates can be acsessed like below.

_x params ["_tableID","_displayName","_classnameBox","_contentsArray"];

*/
if !(GVAR(enable)) exitWith {
	systemChat "Server:UNILOG Not enabled";
};
//private _operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
private _operationID = getMissionConfigValue ['UNITAF_operationID', 0];
//Query crates
private _query = "extDB3" callExtension format ["0:FETCHDATA:SELECT * FROM assets WHERE op_id=%1",_operationID];
private _array = parseSimpleArray _query; 
_array params ["_dbID","_tableArray"];
{
	unitaf_logistics_crates pushBack _x;

} forEach _tableArray;

//Vehicles
_queryVehicles = "extDB3" callExtension format ["0:FETCHDATA:SELECT * FROM vehicles WHERE op_id=%1",_operationID];
_data = parseSimpleArray _queryVehicles;
_data params ["_ID","_vehicleArrays"]; 

{
	unitaf_logistics_vehicles pushBack _x;
} forEach _vehicleArrays;

//Data structure test "items" state

_finArray_items = [
	["rhsusf_200Rnd_556x45_box",50],
	["rhsusf_200rnd_556x45_mixed_box",50],
	["rhs_mag_m18_green",50],
	["rhs_mag_m18_purple",50],
	["rhs_mag_m18_red",50],
	["rhs_mag_m18_yellow",50],
	["rhs_mag_an_m8hc",50],
	["ACE_Chemlight_HiBlue",50],
	["ACE_Chemlight_HiGreen",50],
	["ACE_Chemlight_HiRed",50],
	["ACE_Chemlight_HiWhite",50],
	["ACE_Chemlight_HiYellow",50],
	["ACE_Chemlight_IR",50],
	["rhs_mag_30Rnd_556x45_M855A1_Stanag",50],
	["rhs_mag_30Rnd_556x45_M855A1_PMAG",50],
	["rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",50],
	["rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan",50],
	["rhs_mag_30Rnd_556x45_M855A1_PMAG_Tan_Tracer_Red",50],
	["rhs_mag_m713_Red",50],
	["rhs_mag_m714_White",50],
	["rhs_mag_m715_Green",50],
	["rhs_mag_m716_yellow",50],
	["rhsusf_mag_17Rnd_9x19_JHP",50],
	["rhsusf_mag_17Rnd_9x19_FMJ",50],
	["rhs_mag_m67",50],
	["rhs_mag_M433_HEDP",50],
	["rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",50],
	["rhs_mag_M585_white",50],
	["rhs_mag_m661_green",50],
	["rhsusf_100Rnd_556x45_mixed_soft_pouch",50],
	["rhsusf_100Rnd_556x45_soft_pouch",50],
	["rhsusf_mag_7x45acp_MHP",50],
	["rhsusf_100Rnd_762x51",50],
	["rhsusf_100Rnd_762x51_m62_tracer",50],
	["rhs_mag_maaws_HE",50],
	["rhs_mag_maaws_HEDP",50],
	["rhs_mag_maaws_HEAT",50],
	["ACE_M84",50],
	["DemoCharge_Remote_Mag",50],
	["rhs_fgm148_magazine_AT",50],
	["rhs_mag_M397_HET",50],
	["rhs_mag_20Rnd_SCAR_762x51_m118_special",50],
	["rhs_mag_20Rnd_SCAR_762x51_mk316_special",50]
];
/*
//Data structure test "vehicles" state

_fin_array_vic = [
	["rhsusf_m1151_m2crows_usmc_wd",10],
	["rhsusf_m1043_w_s_m2",10],
	["rhsusf_m1043_w_s_mk19",10],
	["rhsusf_m1151_m2_v3_usmc_wd",10],
	["rhsusf_m1151_mk19crows_usmc_wd",10],
	["RHS_AH1Z_wd",10],
	["RHS_UH1Y_FFAR",10]

];
*/
//Sort mags into item array
{
	if (_x select 0 isKindOf ["CA_Magazine", configFile >> "CfgMagazines"]) then {
		unitaf_logistics_items pushBack [_x select 0,_x select 1];
	};
} forEach _finArray_items;

/*
OLD Static data sorter for vehicles


//Sort vics into vic array
{
	unitaf_logistics_vehicles pushBack [_x select 0,_x select 1];
} forEach _fin_array_vic;
*/