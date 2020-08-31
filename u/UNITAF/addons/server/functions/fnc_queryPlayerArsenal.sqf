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

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ClientEvent,PlayerArsenal), [
		(parseSimpleArray "[1, [""ACE_EarPlugs"",""TFAR_anprc152"", ""ItemGPS""]]")  select 1
	], [_player]] call CBA_fnc_targetEvent;
};

_playerID = getPlayerUID _player;
// return flat array with items allowed in ACE Arsenal for this specific player
_playerArsenal = parseSimpleArray ("extDB3" callExtension format["0:FETCHDATA:SELECT * FROM table", _playerID]);

if (!((_playerArsenal select 0) isEqualTo 1)) exitWith { diag_log "extDB3: Error retrieving Player Arsenal"; };

[QEGVAR(ClientEvent,PlayerArsenal), [_playerArsenal select 1], [_player]] call CBA_fnc_targetEvent;