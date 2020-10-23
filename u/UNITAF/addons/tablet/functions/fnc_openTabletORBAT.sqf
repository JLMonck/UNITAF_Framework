#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the ORBAT part of the GUI
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

[GET_ORBAT] call FUNC(hideAll);
GET_ORBAT ctrlShow true;

// Clear table when opening (again)
ctClear GET_IN_ORBAT(IDC_Tablet_ORBAT_Table);

_ORBAT = missionNamespace getVariable ["UNITAF_ORBAT", []];
if (count _ORBAT isEqualTo 0) exitWith {};

_totalHeight = 0;

_prevCallsign = "";
{
	if !(_prevCallsign isEqualTo (_x select 4)) then {
		_headerCtrls = ctAddHeader GET_IN_ORBAT(IDC_Tablet_ORBAT_Table);
		(_headerCtrls select 1) params ["_HBack", "_HCol1", "_HCol2"];
		_HCol1 ctrlSetText (_x select 4);
		_HCol2 ctrlSetText format ["%1 Mhz", (_x select 6)];
		buttonSetAction [_HCol2, QUOTE([(_x select 6)] call EFUNC(client,setTempFreq))];
		_HBack ctrlSetBackgroundColor [0,0,0,1];

		_prevCallsign = (_x select 4);
		_totalHeight = _totalHeight + 1.2;
	};
	

	_color = [0,0,0,0];	// default transparent
	switch (_x select 5) do {
		case "WHITE": { _color = [1,1,1,1] };
		case "RED": { _color = [1,0,0,1] };
		case "GREEN": { _color = [0,1,0,1] };
		case "BLUE": { _color = [0,0,1,1] };
		case "YELLOW": { _color = [1,1,0,1] };
	};
	_rank = "";
	switch (toUpper (_x select 1)) do {
		case "REC": {};
		case "PVT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
			case "PFC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
			case "SPC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
			case "MSP": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\private_gs.paa"; };
		case "CPL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa"; };
		case "SGT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
			case "SSGT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
			case "SFC": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
			case "1SG": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
			case "SGTMAJ": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa"; };
		case "2LT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa"; };
			case "1LT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa"; };
		case "CAPT": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\captain_gs.paa"; };
		case "MAJ": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\major_gs.paa"; };
			case "LTCOL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\major_gs.paa"; };
		case "COL": { _rank = "a3\ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa"; };
	};

	_rowCtrls = ctAddRow GET_IN_ORBAT(IDC_Tablet_ORBAT_Table);
	(_rowCtrls select 1) params ["_RBack", "_RCol1", "_RCol2", "_RCol3", "_RCol4"];
	_RCol1 ctrlSetText " ";
	_RCol1 ctrlSetBackgroundColor _color;
	_RCol2 ctrlSetText _rank;
	_RCol3 ctrlSetText (_x select 0);
	_RCol4 ctrlSetText (_x select 3);

	_totalHeight = _totalHeight + 1;

} forEach _ORBAT;

 GET_IN_ORBAT(IDC_Tablet_ORBAT_Table) ctrlSetPosition [0, 0, 1, ((GUI_GRID_H * 1) * _totalHeight)];