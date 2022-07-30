#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Open the UNITAF Tablet
 *
 * Arguments:
 * 0: something <???>
 *
 * Return Value:
 * NONE
 *
 * Public: No
 */

params ["_something"];

// close (any) dialog before opening the menu
if (dialog) exitWith {
    closeDialog 0;
};

createDialog QGVAR(Tablet);