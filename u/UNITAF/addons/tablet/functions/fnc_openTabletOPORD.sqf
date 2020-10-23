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

_display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_OPORD] call FUNC(hideAll);
GET_OPORD ctrlShow true;

diag_log '>> open OPORD';

_operationId = getMissionConfigValue ["UNITAF_operationId", 0];
if (_operationId isEqualTo 0) then {
	_operationId = missionName;
};

[_display, _operationId] spawn {
	params ["_display", "_operationId"];

	//_OPORDOnline = format["https://unitedtaskforce.net/operations/auth/%1/opord/raw", _operationId];
	_OPORDOnline = QPATHTOF(opord_offline.html);
	_OPORDOffline = QPATHTOF(opord_offline.html);

	//Load the correct HTML into the control
	_ctrlHTML = GET_IN_OPORD(IDC_Tablet_OPORD_HTML);
	_ctrlHTML htmlLoad _OPORDOnline;

	//Offline back-up
	_htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
	if (!_htmlLoaded) then {
		_ctrlHTML htmlLoad _OPORDOffline;
	};

	diag_log format ['>> loaded: %1', (str _htmlLoaded)];
	diag_log format ['>> file: %1', (_OPORDOffline)];
};