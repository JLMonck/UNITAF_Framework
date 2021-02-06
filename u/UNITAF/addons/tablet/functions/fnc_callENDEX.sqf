#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Call ENDEX for all AI and players
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

[] spawn {
	private _display = GET_TABLET;

	private _result = ["Are you sure?", "Call ENDEX", "Yes, do it!", "Nope!", _display, false] call BIS_fnc_guiMessage;
	if (_result) then {
		// disable all AI (on Server AND HC)
		[QEGVAR(HeadlessEvent,callENDEX), [(allUnits - allPlayers)], (allUnits - allPlayers)] call CBA_fnc_targetEvent;

		// heal players and show ENDEX message
		[QEGVAR(ClientEvent,callENDEX), [], allPlayers] call CBA_fnc_targetEvent;

		closeDialog 0;
	};
};