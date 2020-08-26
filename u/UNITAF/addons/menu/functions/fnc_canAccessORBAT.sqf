#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Check if player can access the UNITAF ORBAT functions
 * Will check if inside marker area, OR within 50m of marker, OR within 50m of ORBAT arsenal
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * <BOOLEAN>
 *
 * Public: No
 */

params ["_player"];

_return = false;

_markers = ["UNITAF_base", 10] call EFUNC(main,fillArrayPrefix);

// check if player is inside marker area
{
	if (getPos _player inArea _x) then {
		_return = true;
	};
} count _markers;

// above failed?
if !(_return) then {
	// check if player is within 50m of marker
	{
		if (_player distance _x < 50) then {
			_return = true;
		};
	} count _markers;
};

// above failed?
if !(_return) then {
	_boxes = ["UNITAF_arsenal", 25] call EFUNC(main,fillArrayPrefix);
	// check if player is within 50m range of ORBAT Arsenal
	{
		if !(isNil _x) then {
			_box = missionNamespace getVariable _x;
			if (_player distance _box < 50) then {
				_return = true;
			};
		};
	} count _boxes;
};

// return false or true...
_return