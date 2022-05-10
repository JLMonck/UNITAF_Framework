#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the OPORD part of the GUI
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

private _display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_OPORD] call FUNC(hideAll);
GET_OPORD ctrlShow true;

private _operationId = getMissionConfigValue ["UNITAF_operationId", 0];
if (_operationId isEqualTo 0) then {
	_operationId = missionName;
};

[_display, _operationId] spawn {
	params ["_display", "_operationId"];

	//private _OPORDOnline = format["https://unitedtaskforce.net/operations/auth/%1/opord/raw", _operationId];
	private _OPORDOnline = QPATHTOF(opord_offline.html);
	private _OPORDOffline = QPATHTOF(opord_offline.html);

	//Load the correct HTML into the control
	private _ctrlHTML = GET_IN_OPORD(IDC_Tablet_OPORD_HTML);
	_ctrlHTML htmlLoad _OPORDOnline;

	//Offline back-up
	private _htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
	if (!_htmlLoaded) then {
		_ctrlHTML htmlLoad _OPORDOffline;
	};
};