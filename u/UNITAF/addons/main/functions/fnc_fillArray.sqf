#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Fill an array with a range of numbers (starting at 1)
 *
 * Arguments:
 * 0: count <NUMBER>
 *
 * Return Value:
 * <ARRAY>
 *
 * Public: YES
 */

params ["_count"];

_array = [];
_array resize _count;
{
	_array set [_forEachIndex, format["%1", (_forEachIndex + 1)]];
} forEach _array;
_array