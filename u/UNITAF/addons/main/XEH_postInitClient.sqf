#include "script_component.hpp"
/**
 * Author: Grezvany13
 * XEH postInitClient
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

if !(hasInterface) exitWith {};

{
	[player] call COMPILE_FILE(briefing);
} call CBA_fnc_execNextFrame;