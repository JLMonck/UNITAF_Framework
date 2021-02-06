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

private _maxRange = QGVAR(ORBAT_Range) call CBA_settings_fnc_get;

private _return = false;

private _markers = ["UNITAF_base", 10] call EFUNC(main,fillArrayPrefix);

// check if player is inside marker area
{
	// check if marker exists
	if !(getMarkerColor _x isEqualTo "") then {
		// check if player is in area
		if (getPos _player inArea _x) then {
			_return = true;
		};
	};
} count _markers;

// above failed?
if !(_return) then {
	// check if player is within 50m of marker
	{
		// check if marker exists
		if !(getMarkerColor _x isEqualTo "") then {
			// check distance between player and marker
			if (_player distance (getMarkerPos _x) < _maxRange) then {
				_return = true;
			};
		};
	} count _markers;
};

// above failed?
if !(_return) then {
	private _boxes = ["UNITAF_arsenal", 25] call EFUNC(main,fillArrayPrefix);
	// check if player is within 50m range of ORBAT Arsenal
	{
		// check if variable exists
		if !(isNil _x) then {
			_box = missionNamespace getVariable _x;
			// check distance between player and object
			if (_player distance _box < _maxRange) then {
				_return = true;
			};
		};
	} count _boxes;
};

// return false or true...
_return