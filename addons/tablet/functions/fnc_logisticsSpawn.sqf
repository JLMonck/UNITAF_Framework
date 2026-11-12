#include "script_component.hpp"
/**
 * Author: JLMonck
 * The Logistics page's Spawn (D-470): what was picked, in the box picked, three metres in front
 * of the player. Only at base, by the same rule as loading the ORBAT (a UNITAF_base marker or an
 * ORBAT arsenal), so supplies are not conjured in the field. The server reads, packs and spawns.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

private _choice = GVAR(logisticsChoice);

if (_choice isEqualTo "") exitWith {
	hint "Pick what to spawn first.";
};

if !([player] call FUNC(canAccessORBAT)) exitWith {
	hint "Crates can only be spawned at base, near the ORBAT arsenal or a base marker.";
};

// Three metres in front, at the player's own height (ASL), so it works on decks and upper floors
private _position = player modelToWorldWorld [0, 3, 0];
[QEGVAR(ServerEvent,spawnCrate), [_choice, GVAR(logisticsContainer), _choice isEqualTo "arsenal", _position]] call CBA_fnc_serverEvent;

hint "Spawning in front of you.";
