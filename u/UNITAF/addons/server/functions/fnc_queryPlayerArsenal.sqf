#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve personal Arsenal items
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryPlayerArsenal;
 *
 * Public: No
 */
 
params ["_player"];
_operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
_playerUID = getPlayerUID _player;

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	_query = "[1, [[""ACE_EarPlugs"",""TFAR_anprc152"",""ItemGPS"",""ACE_Flashlight_Maglite_ML300L"",""ACE_IR_Strobe_Item""]]]";
	_result = (parseSimpleArray _query);
	[QEGVAR(ClientEvent,PlayerArsenal), (_result select 1), [_player]] call CBA_fnc_targetEvent;
};

// @TODO: query must be updated to support personal arsenals based on ORBAT role
_query = "extDB3" callExtension "0:FETCHDATA:SELECT inventory FROM arsenals WHERE faction = 1";
_result = (parseSimpleArray _query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving Player Arsenal";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		// only get the first result
		[QEGVAR(ClientEvent,PlayerArsenal), (_result select 1 select 0), [_player]] call CBA_fnc_targetEvent;
	};
	default {
		diag_log "extDB3: Something went wrong with Player Arsenal";
		diag_log format["Database Result: %1", _result];
	};
};