#include "script_component.hpp"

params ["_control", "_xPos", "_yPos", "_mouseOver"];

if (_mouseOver) then {
	_control ctrlMapScreenToWorld [_xPos, _yPos];


	_display = GET_TABLET;
	_ctrlScreen = GET_IN_MAP(IDC_Tablet_MapFlat_Control);

	_pos = _control ctrlMapWorldToScreen position player;
	_secondPos = [_xPos, _yPos];

	// draw arrow from current position to map centre
	_dirToSecondPos = call {
		if (_this select 4 == 0) exitWith {
			_ctrlScreen drawArrow [_pos, _secondPos, [1,0,0,1]];
			[_pos,_secondPos] call BIS_fnc_dirTo;
		};
		_ctrlScreen drawArrow [_secondPos, _pos, [1,0,0,1]];
		[_secondPos,_pos] call BIS_fnc_dirTo;
	};
	_dstToSecondPos = [_pos,_secondPos] call BIS_fnc_distance2D;

	_dir = round (_dirToSecondPos / 45);
	_octant = ["N ","NE","E ","SE","S ","SW","W ","NW","N "] select _dir;

	(_display displayCtrl IDC_Tablet_MapInfo_HookGrid) ctrlSetText format ["%1", mapGridPosition _secondPos];
	(_display displayCtrl IDC_Tablet_MapInfo_hookElevation) ctrlSetText format ["%1m", round getTerrainHeightASL _secondPos];
	(_display displayCtrl IDC_Tablet_MapInfo_HookDst) ctrlSetText format ["%1° %2", [_dirToSecondPos,3] call CBA_fnc_formatNumber, _octant];
	(_display displayCtrl IDC_Tablet_MapInfo_HookDir) ctrlSetText format ["%1km", [_dstToSecondPos / 1000, 1, 2] call CBA_fnc_formatNumber];
};
