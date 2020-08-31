#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve Player Data from ORBAT
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [42] call unitaf_server_fnc_queryPlayerData;
 *
 * Public: No
 */
params ["_player"];

_operationID = missionName;
_playerUID = str (getPlayerUID _player);

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ClientEvent,PlayerData), [
		(parseSimpleArray "[1, [""Pvt"",0,0,0,2,1,""MONTY"",42,""GREEN"",100,""PRIVATE""]]")  select 1
	], [_player]] call CBA_fnc_targetEvent;	
};

_playerData = parseSimpleArray ("extDB3" callExtension format["0:FETCHDATA:SELECT playerRank,playerAdmin,playerPos,playerDir,is_medic_level,is_engineer_level,callsign,freq,buddy,lr_freq,armarank FROM operation_players WHERE armauid = '%1' AND operation = '%2' GROUP BY armauid", _playerUID, _operationID]);

if (!((_playerData select 0) isEqualTo 1)) exitWith { diag_log "extDB3: Error retrieving player data"; };

[QEGVAR(_ClientEvent,PlayerData), [_playerData select 1], [_player]] call CBA_fnc_targetEvent;