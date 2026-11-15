#include "script_component.hpp"
/*
 * Author: JLMonck
 * The crate boxes the website allows for this deployment (2.6.0, UNITAF tracker #119):
 * game_crate_boxes, every allowed box in the deployment's camo (a UNICRATES box in snow, sand or
 * green, as its Logistics or its terrain says). Read once when the mission starts and handed to
 * every machine, so the tablet, Zeus and the packing on the server offer the same boxes. Which
 * of them this game has is decided where they are used (unitaf_logistics_fnc_getBoxes); with
 * none, the mod's own boxes are used as before 2.6.0.
 *
 * Arguments:
 * 0: Deployment id <NUMBER|STRING>
 *
 * Return Value:
 * Boxes, [[class, name, space, kind, automatic, empty box only, camo], ...]; empty without the database <ARRAY>
 *
 * Example:
 * [42] call unitaf_server_fnc_queryCrateBoxes;
 *
 * Public: No
 */

params ["_operationID"];

if !(missionNamespace getVariable ['UNITAF_databaseAvailable', false]) exitWith { [] };

private _result = parseSimpleArray ("extDB3" callExtension format ["0:FETCHDATA:SELECT class, name, space, kind, carryable, empty_only, camo FROM game_crate_boxes WHERE deployment = '%1' ORDER BY space, class", _operationID]);

if ((_result select 0) isNotEqualTo 1) exitWith {
	diag_log "extDB3: Error retrieving the crate boxes; the mod's own boxes are used";
	diag_log format ["Database Result: %1", _result];
	[]
};

private _boxes = _result select 1;

if (_boxes isEqualTo []) then {
	diag_log "UNITAF logistics: the website allows no crate boxes for this deployment; the mod's own boxes are used";
} else {
	diag_log format ["UNITAF logistics: the website allows %1 crate boxes for this deployment, in its %2 camo", count _boxes, (_boxes select 0) param [6, ""]];
};

// Every machine reads the same list: the tablet and Zeus list it, the server packs into it
missionNamespace setVariable [QEGVAR(logistics,siteBoxes), _boxes, true];

_boxes
