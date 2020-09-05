#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Handles 'Back' button on sub controls of UI
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

[_display] call FUNC(menuOnLoad);