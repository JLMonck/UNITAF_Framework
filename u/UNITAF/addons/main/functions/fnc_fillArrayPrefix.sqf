#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Fill an array with a range of string with a counter attached
 *
 * Arguments:
 * 0: prefix <STRING>
 * 1: count <NUMBER>
 *
 * Return Value:
 * <ARRAY>
 *
 * Public: YES
 */

params ["_prefix", "_count"];

private _array = [];
_array resize _count;
{
	_array set [_forEachIndex, format["%1_%2", _prefix, (_forEachIndex + 1)]];
} forEach _array;
_array