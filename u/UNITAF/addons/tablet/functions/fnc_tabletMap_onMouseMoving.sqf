#include "script_component.hpp"

params ["_control", "_xPos", "_yPos", "_mouseOver"];

diag_log format ["onMouseMoving: %1, %2, %3, %4", _control, _xPos, _yPos, _mouseOver];

if (_mouseOver) then {
	_control ctrlMapScreenToWorld [_xPos, _yPos];

	_pos = getPosASL player;
	//_secondPos = _control ctrlMapScreenToWorld [_xPos, _yPos];
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
};