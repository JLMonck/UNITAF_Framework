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

_display = uiNamespace getVariable [QGVAR(menuDisplay), displayNull];

if (_display isEqualTo displayNull) exitWith {};

// hide other controls
GET_MAIN(_display) ctrlShow false;
GET_CLOSE(_display) ctrlShow false;

// show OPORD control
GET_OPORD(_display) ctrlShow true;
GET_BACK(_display) ctrlShow true;


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
	_ctrlHTML = GET_IN_OPORD(_display,IDC_OPORD_HTML);
	_ctrlHTML htmlLoad _OPORDOnline;

	//Offline back-up
	_htmlLoaded = ctrlHTMLLoaded _ctrlHTML;
	if (!_htmlLoaded) then {
		_ctrlHTML htmlLoad _OPORDOffline;
	};
};