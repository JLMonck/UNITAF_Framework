#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Set player inventory based on ORBAT
 *
 * Arguments:
 * 0: inventory <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */

params ["_inventory"];
// _inventory = setUnitLoadout array

// set loadout
player setUnitLoadout (configFile >> "EmptyLoadout"); // first, remove everything!
player setUnitLoadout _inventory;