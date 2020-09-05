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

_operationID = missionName;
_playerUID = str (getPlayerUID _player);

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith {
	[QEGVAR(ClientEvent,PlayerInventory), [
		(parseSimpleArray "[1, [[""arifle_MXC_Holo_pointer_F"", """", ""acc_pointer_IR"", ""optic_Holosight"", [""30Rnd_65x39_caseless_mag"", 30], [], """"],[""launch_B_Titan_short_F"", """", """", """", [""Titan_AT"", 1], [], """"],[""hgun_P07_F"", """", """", """", [""16Rnd_9x21_Mag"", 16], [], """"],[""U_B_CombatUniform_mcam"", [[""FirstAidKit"", 1], [""30Rnd_65x39_caseless_mag"", 2, 30], [""Chemlight_green"", 1, 1]]],[""V_PlateCarrier1_rgr"", [[""30Rnd_65x39_caseless_mag"", 3, 30], [""16Rnd_9x21_Mag"", 2, 16], [""SmokeShell"", 1 ,1], [""SmokeShellGreen"", 1, 1], [""Chemlight_green"", 1, 1]]],[""B_AssaultPack_mcamo_AT"",[[""Titan_AT"", 2, 1]]],""H_HelmetB_light_desert"", ""G_Bandanna_tan"",[],[""ItemMap"","""",""TFAR_anprc152"",""ItemCompass"",""ItemWatch"",""NVGoggles""]]]")  select 1
	], [_player]] call CBA_fnc_targetEvent;	
};

_inventory = "extDB3" callExtension format["0:FETCHDATA:SELECT opl.inventory as playerInv FROM operation_layout ol LEFT JOIN roster_view rv ON rv.userid = ol.user LEFT JOIN operation_positions_loadouts opl ON opl.position = ol.position WHERE ol.operation = '%2' AND rv.armauid = '%1' AND opl.faction = 5", _playerUID, _operationID];

if (!((parseSimpleArray (_inventory) select 0) isEqualTo 1)) exitWith { diag_log "extDB3: Error retrieving player inventory"; };

[QEGVAR(ClientEvent,PlayerInventory), [parseSimpleArray (_inventory) select 1], [_player]] call CBA_fnc_targetEvent;