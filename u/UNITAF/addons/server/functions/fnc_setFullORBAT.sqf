#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Set global variable based on full ORBAT
 *
 * Arguments:
 * 0: ORBAT <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[42, "PYTHON", "West"]] call unitaf_server_fnc_setORBAT
 *
 * Public: No
 */

params ["_ORBAT"];

/**
 * EXAMPLE
_ORBAT = [
	[
		"Pvt Grezvany13",			// Name
		"Pvt",						// Rank
		"insignia123",				// ORBAT specific insignia
		"Squad Leader",				// Role
		"PYTHON 1",					// Callsign
		"WHITE",					// Buddy colour
		"250",						// Group Frequency
		"50"						// Parent Group Frequency
	]
];
 */
/*
_ORBAT = [
	["Capt James", "Capt", "", "Squad Leader", "PHANTOM 1", "WHITE", 250.0, null],
	["2Lt Kevin", "2Lt", "", "Squad Medic", "PHANTOM 1", "WHITE", 250.0, null],

	["Sgt Jari", "Sgt", "", "Fireteam Leader", "ADDER 1-1", "RED", 251.0, 250.0],
	["Pvt Flubber Dubber", "Pvt", "", "Designated Marksman", "ADDER 1-1", "RED", 251.0, 250.0],
	["PFC BigRed", "PFC", "", "Automatic Rifleman", "ADDER 1-1", "GREEN", 251.0, 250.0],
	["PFC Bradley", "PFC", "", "Combat Life Saver", "ADDER 1-1", "GREEN", 251.0, 250.0],
	["Cpl Skelly", "Cpl", "", "Anti-Tank Rifleman, Light", "ADDER 1-1", "GREEN", 251.0, 250.0],

	["2Lt Zero", "2Lt", "", "Fireteam Leader", "VIXEN 1-2", "BLUE", 252.0, 250.0],
	["Sgt Attackbee", "Sgt", "", "Grenadier", "VIXEN 1-2", "BLUE", 252.0, 250.0],
	["Cpl Mattjamco", "Cpl", "", "Automatic Rifleman", "VIXEN 1-2", "YELLOW", 252.0, 250.0],
	["PFC Johannes", "PFC", "", "Combat Life Saver", "VIXEN 1-2", "YELLOW", 252.0, 250.0],
	["Pvt Milky", "Pvt", "", "Anti-Tank Rifleman, Light", "VIXEN 1-2", "YELLOW", 252.0, 250.0],

	["Cpl J. ""Willy"" Wilson", "Cpl", "", "Fixed Wing Pilot (CAS)", "LIGHTNING 9", "", 70.0, null]
];
*/
//missionNamespace setVariable ["UNITAF_ORBAT", _ORBAT, true];
missionNamespace setVariable ["UNITAF_ORBAT", [], true];