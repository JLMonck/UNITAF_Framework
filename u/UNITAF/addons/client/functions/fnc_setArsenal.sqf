#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Set ACE Arsenal items list from server
 *
 * Arguments:
 * 0: items <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_setArsenal;
 *
 * Public: No
 */
params ["_items"];

// loop over 50 numbers ("unitaf_arsenal_1" till "unitaf_arsenal_50")
for [{ _i = 1 }, { _i <= 50 }, { _i = _i + 1 }] do {
	// get the box variable name
	_boxName = format ["unitaf_arsenal_%1", _i];
	if !(isNil _boxName) then {
		// if the variable exist, run some scripts
		_box = missionNamespace getVariable _boxName;
		[_box, true, false] call ace_arsenal_fnc_removeVirtualItems;
		[_box, _items, false] call ace_arsenal_fnc_initBox;
	} else {
		// after first time a variable doesn't exist, kill the loop
		_i = 999;
	};
};