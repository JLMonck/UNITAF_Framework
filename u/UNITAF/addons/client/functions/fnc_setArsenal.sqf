#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Set ACE Arsenal items list from server
 *
 * Arguments:
 * 0: items <ARRAY>
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_setArsenal;
 *
 * Public: No
 */
params ["_arsenalData"];
//_arsenalData = parseSimpleArray format ["%1", _arsenalData];	// ugly hack to make an array out of a string

if (isClass(configFile >> "CfgPatches" >> "ace_arsenal")) then {
	[
		{
			params ["_player", "_arsenal"];
			(_player getVariable [QGVAR(hasInventory), false]) isEqualTo true
		},
		{
			params ["_player", "_arsenal"];
			_loadout = _player getVariable [QGVAR(defaultInventory), []];

			_flat = _loadout call EFUNC(main,arrayFlattenUnordered);
			_flat = _flat select { !(_x isEqualTo "") && !(typeName _x isEqualTo "SCALAR") };
			_arsenal = _arsenal + _flat;

			_boxes = ["UNITAF_arsenal", 25] call EFUNC(main,fillArrayPrefix);

			{
				if !(isNil _x) then {
					_box = missionNamespace getVariable _x;
					[_box, true, false] call ace_arsenal_fnc_removeVirtualItems;
					[_box, _arsenal, false] call ace_arsenal_fnc_initBox;
				};
			} count _boxes;
			
			_player setVariable [QGVAR(hasArsenal), true, true];
			hint "Your personal arsenal has been loaded";
		},
		[player, _arsenalData],
		10,
		{}
	] call CBA_fnc_waitUntilAndExecute;
};