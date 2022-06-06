#include "script_component.hpp"
_depot = unilog_master_supply_depot;
//Remove helper
deleteVehicle unitaf_logistics_vehicle_spawn_helper;

{
	_depot addMagazineCargoGlobal [_x select 0,_x select 1];
} forEach unitaf_logistics_items;

