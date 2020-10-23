#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Get a stringified version of the (first) keybind
 *
 * Arguments:
 * 0: setting <STRING>
 *
 * Return Value:
 * <STRING>
 *
 * Public: YES
 */

params ["_setting"];

_keybind = [QUOTE(PREFIX), _setting] call CBA_fnc_getKeybind;
_string = (_keybind select 5) call CBA_fnc_localizeKey;

_string;