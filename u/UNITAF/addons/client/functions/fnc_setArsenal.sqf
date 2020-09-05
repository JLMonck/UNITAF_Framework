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

if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
	_boxes = ["UNITAF_arsenal", 25] call EFUNC(main,fillArrayPrefix);
	{
		if !(isNil _x) then {
			_box = missionNamespace getVariable _x;
			[_box, true, false] call ace_arsenal_fnc_removeVirtualItems;
			[_box, _items, false] call ace_arsenal_fnc_initBox;
		};
	} count _boxes;
	
	player setVariable [QGVAR(hasArsenal), true, true];
};