#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the Map on the tablet
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

_display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_MAP] call FUNC(hideAll);
GET_MAP ctrlShow true;

addMissionEventHandler ["Draw3D",{
	//_ctrlMapInfo = GET_IN_MAP(IDC_Tablet_MapInfo_Control);

	_veh = vehicle player;
	_playerPos = getPosASL _veh;
	_heading = direction _veh;

	_date = date;
	_hour = _date select 3;
	_min = _date select 4;
	if (_hour < 10) then {_hour = format ["0%1", _hour];};
	if (_min < 10) then {_min = format ["0%1", _min];};
	_time = format ["%1:%2", _hour, _min];

	_dir = round (_heading / 45);
	_octant = ["N ","NE","E ","SE","S ","SW","W ","NW","N "] select _dir;
	
	// update time
	GET_IN_MAP(IDC_Tablet_MapInfo_Time) ctrlSetText _time;
	// update grid position
	GET_IN_MAP(IDC_Tablet_MapInfo_Grid) ctrlSetText format ["%1", mapGridPosition _playerPos];
	// update current heading
	GET_IN_MAP(IDC_Tablet_MapInfo_Degree) ctrlSetText format ["%1°",[direction _veh,3] call CBA_fnc_formatNumber];
	GET_IN_MAP(IDC_Tablet_MapInfo_Octant) ctrlSetText _octant;
	// update current elevation (ASL) on TAD
	GET_IN_MAP(IDC_Tablet_MapInfo_Elevation) ctrlSetText format ["%1m",[round (_playerPos select 2),4] call CBA_fnc_formatNumber];
}];

//_control = GET_IN_MAP(IDC_Tablet_Map_Control);
_control = GET_IN_MAP(IDC_Tablet_MapFlat_Control);

GVAR(mousePosition) = [];

_control ctrlAddEventHandler ["MouseMoving", {

	params ["_control", "_xPos", "_yPos", "_mouseOver"];

	_pos = position player;
	_secondPos = _control ctrlMapScreenToWorld [_xPos, _yPos];

	GVAR(mousePosition) = _secondPos;

	_dirToSecondPos = [_pos, _secondPos] call BIS_fnc_dirTo;
	_dstToSecondPos = [_pos, _secondPos] call BIS_fnc_distance2D;

	_dir = round (_dirToSecondPos / 45);
	_octant = ["N ","NE","E ","SE","S ","SW","W ","NW","N "] select _dir;

	GET_IN_MAP(IDC_Tablet_MapInfo_HookGrid) ctrlSetText format ["%1", mapGridPosition _secondPos];
	GET_IN_MAP(IDC_Tablet_MapInfo_hookElevation) ctrlSetText format ["%1m", round getTerrainHeightASL _secondPos];
	GET_IN_MAP(IDC_Tablet_MapInfo_HookDst) ctrlSetText format ["%1° %2", [_dirToSecondPos,3] call CBA_fnc_formatNumber, _octant];
	GET_IN_MAP(IDC_Tablet_MapInfo_HookDir) ctrlSetText format ["%1km", [_dstToSecondPos / 1000, 1, 2] call CBA_fnc_formatNumber];
}];
_control ctrlAddEventHandler ["Draw", {
	params ["_control"];

	_pos = position player;
	_secondPos = GVAR(mousePosition);

	if !(_secondPos isEqualTo []) then {
		// draw arrow from current position to map centre
		_control drawArrow [_pos, _secondPos, [1,0,0,1]];
	};
}];

/*
_ctrlMap 	 = GET_IN_MAP(IDC_Tablet_Map_Control);
_ctrlMapFlat = GET_IN_MAP(IDC_Tablet_MapFlat_Control);

_currentVision = uiNamespace getVariable [QGVAR(Map_Type), "normal"];

if (_currentVision isEqualTo "flat") then {
	_ctrlMap ctrlShow false;
	_ctrlMapFlat ctrlShow true;
	uiNamespace setVariable [QGVAR(Map_Type), "normal"];
} else {
	_ctrlMap ctrlShow true;
	_ctrlMapFlat ctrlShow false;
	uiNamespace setVariable [QGVAR(Map_Type), "flat"];
};
*/