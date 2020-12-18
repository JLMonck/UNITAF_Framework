#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Query Database to retrieve Player Inventory based on ORBAT
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

_operationID = missionNamespace getVariable ['UNITAF_operationID', 0];
_playerUID = getPlayerUID _player;

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	_query = "[1, [[[""srifle_DMR_03_tan_AMS_LP_F"","""",""acc_pointer_IR"",""optic_AMS_snd"",[""20Rnd_762x51_Mag"",20],[],""bipod_01_F_snd""],[],[""hgun_P07_F"","""","""","""",[""16Rnd_9x21_Mag"",16],[],""""],[""U_B_CombatUniform_mcam"",[[""FirstAidKit"",1],[""20Rnd_762x51_Mag"",1,20],[""Chemlight_green"",1,1]]],[""V_PlateCarrier1_rgr"",[[""20Rnd_762x51_Mag"",6,20],[""16Rnd_9x21_Mag"",2,16],[""SmokeShell"",1,1],[""SmokeShellGreen"",1,1],[""Chemlight_green"",1,1],[""HandGrenade"",2,1]]],[],""H_HelmetB"","""",[""Binocular"","""","""","""",[],[],""""],[""ItemMap"","""",""ItemRadio"",""ItemCompass"",""ItemWatch"",""NVGoggles""]]]]";
	_result = (parseSimpleArray _query);
	[QEGVAR(ClientEvent,PlayerInventory), (_result select 1), [_player]] call CBA_fnc_targetEvent;
};

_query = "extDB3" callExtension format["0:FETCHDATA:SELECT opl.inventory as playerInv FROM operation_layout ol LEFT JOIN roster_view rv ON rv.userid = ol.user LEFT JOIN operation_positions_loadouts opl ON opl.position = ol.position LEFT JOIN operations op ON op.id = ol.operation WHERE ol.operation = '%2' AND rv.armauid = '%1' AND opl.faction = op.faction", _playerUID, _operationID];
_result = (parseSimpleArray _query);

switch (_result select 0) do {
	case 0: {
		 diag_log "extDB3: Error retrieving Player Inventory";
		 diag_log format["Database Error: %1", (_result select 1)];
	};
	case 1: {
		// only get the first result
		[QEGVAR(ClientEvent,PlayerInventory), (_result select 1 select 0), [_player]] call CBA_fnc_targetEvent;
	};
	default {
		diag_log "extDB3: Something went wrong with Player Inventory";
		diag_log format["Database Result: %1", _result];
	};
};
