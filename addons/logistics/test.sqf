//DB Connect + protocol
_result = "extDB3" callExtension "9:ADD_DATABASE:UTFN";
_resultPROT = "extDB3" callExtension "9:ADD_DATABASE_PROTOCOL:UTFN:SQL:FETCHDATA:TEXT";
hint format ["Connection: %1 -- Protocol: %2",_result,_resultPROT];
_query = "extDB3" callExtension "0:FETCHDATA:SELECT * FROM assets";
//SELECT * FROM assets

[1/*select 0*/,
	[
		[1,"[RHS]Squad Resupply TEST","Box_NATO_Ammo_F",[["rhs_mag_30Rnd_556x45_M855A1_Stanag", 50], ["rhsusf_200Rnd_556x45_soft_pouch_coyote", 10], ["rhs_mag_m67", 10], ["rhs_mag_an_m8hc", 6], ["rhs_mag_m18_green", 4], ["rhs_mag_m18_purple", 2], ["rhs_mag_M441_HE", 8], ["rhs_mag_M433_HEDP", 4]]]
	]
]

_query = "extDB3" callExtension "0:FETCHDATA:SELECT * FROM assets";
_array = (parseSimpleArray _query);
_arrayData = _array select 1 select 0;
_arrayData params ["_id","_display_name","_crate_class","_crate_items"];
//Result output ex
/*
id:1 
--
displayName:[RHS]Squad Resupply TEST
--
crate_class:Box_NATO_Ammo_F
--
crate_items: [["rhs_mag_30Rnd_556x45_M855A1_Stanag",50],["rhsusf_200Rnd_556x45_soft_pouch_coyote",10],["rhs_mag_m67",10],["rhs_mag_an_m8hc",6],["rhs_mag_m18_green",4],["rhs_mag_m18_purple",2],["rhs_mag_M441_HE",8],["rhs_mag_M433_HEDP",4]]
*/