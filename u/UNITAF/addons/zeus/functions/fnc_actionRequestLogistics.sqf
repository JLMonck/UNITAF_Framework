#include "script_component.hpp"

params ["_values", "_arguments"];
_values params ["_config", "_type", "_arsenal"];
_arguments params ["_position"];

// Create container
_container = createVehicle [_type, [_position select 0, _position select 1, 0]];

if (_arsenal) then {
	// If ACE Arsenal, add ALL items to container
	[_container, true] call ace_arsenal_fnc_initBox;
} else {
	// Get content from list or DB
	_contents = [_config] call EFUNC(logistics,getSupplyContents);

	// empty out container
	clearItemCargoGlobal _container;
	// Add items to container
	{
		_container addItemCargoGlobal [_x select 0, _x select 1];
	} count _contents;
};
// ensure all curators get access to the container
[QEGVAR(ServerEvent,addToCurator), [_container]] call CBA_fnc_serverEvent;