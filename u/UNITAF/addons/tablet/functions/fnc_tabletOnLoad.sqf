#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Automatically runs on OnLoad of UNITAF_Menu_Tablet
 * Checks for ORBAT Access, and sets all settings for player
 *
 * Arguments:
 * 0: display <DISPLAY>
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

params ["_display"];

uiNamespace setVariable [QGVAR(tabletDisplay), _display];

// hide all controls, except welcome
[GET_WELCOME] call FUNC(hideAll);
[] spawn {
	// add animation to fill out name/password
	// uisleep 3;
	[] call FUNC(openTabletMain);
};
