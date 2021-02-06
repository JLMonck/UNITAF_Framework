#include "script_component.hpp"

/**
 * Author: Grezvany13
 * Hide all ControlGroups, except current
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

params ["_current"];

_display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

HIDE_NOT_CURRENT(GET_WELCOME,_current)
HIDE_NOT_CURRENT(GET_MAP,_current)
HIDE_NOT_CURRENT(GET_MAIN,_current)
HIDE_NOT_CURRENT(GET_ADMIN,_current)
HIDE_NOT_CURRENT(GET_OPORD,_current)
HIDE_NOT_CURRENT(GET_ORBAT,_current)
HIDE_NOT_CURRENT(GET_LOGISTICS,_current)

ctrlShow [IDC_Tablet_MapFlat_Control, false];