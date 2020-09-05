#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the ADMIN part of the GUI
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

// show ADMIN control
GET_ADMIN(_display) ctrlShow true;
GET_BACK(_display) ctrlShow true;