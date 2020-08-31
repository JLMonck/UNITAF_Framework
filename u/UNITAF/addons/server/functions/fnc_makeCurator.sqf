#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Give player Zeus access
 *
 * Arguments:
 * 0: player <ARRAY>
 *
 * Return Value:
 * None
 *
 * Public: No
 */
params ["_player"];

private _curVarName = (str _player)+"Cur";

// delete any curator modules for this unit if already existing
if (!isNil _curVarName) then {
	deleteVehicle (missionNamespace getVariable [_curVarName, objNull]);
	missionNamespace setVariable [_curVarName, nil, true];
};

if (isNil _curVarName) then {
	// create single Curator Group (to prevent hitting the 144 group limit)
	if (isNil "CuratorGroup") then {
		CuratorGroup = creategroup sideLogic;
	};
	// create a new Curator Module in the group
	private _curObject = CuratorGroup createunit["ModuleCurator_F", [0, 0, 0], [], 0.5, "NONE"];

	// set Curator settings
	_curObject setVariable ["showNotification", false];
	_curObject setVariable ["birdType", "", true];
	_curObject setCuratorWaypointCost 0;
	_curObject setcuratorcoef ["place", 0];
	_curObject setcuratorcoef ["edit", 0];
	_curObject setcuratorcoef ["delete", 0];
	_curObject setcuratorcoef ["destroy", 0];
	_curObject setcuratorcoef ["group", 0];
	_curObject setcuratorcoef ["synchronize", 0];

	// add Curator Object to Mission Variable (for future use)
	missionNamespace setVariable [_curVarName, _curObject, true];

	publicVariable "CuratorGroup";
	unassignCurator _curObject;

	// add all active mods/addons to the curator
	_cfg = (configFile >> "CfgPatches");
	_newAddons = [];
	{
		_name = configName _x;
		_newAddons pushBack _name;
	} count _cfg;
	if (count _newAddons > 0) then {
		_curObject addCuratorAddons _newAddons;
	};

	// add all current objects to Curator
	[_curObject] spawn {
		params ["_curObject"];
		_curObject addCuratorEditableObjects[(allMissionObjects "All"), true];
	};

	private _curObject = missionNamespace getVariable [_curVarName, objNull];
	unassignCurator _curObject;
	sleep 0.4;
	_player assignCurator _curObject;

	// remove Curator rights when unit gets killed
	private _eh_id = _player addEventHandler ["killed", {
		params ["_player"];
		private _curVarName = (str _player)+"Cur";

		private _curObject = missionNamespace getVariable [_curVarName, objNull];
		if (!isNull _curObject) then {
			(group _curObject) deleteGroupWhenEmpty true;
			deleteVehicle _curObject;
		};
		_player removeEventHandler ["killed", _player getVariable QGVAR(curatorKEH)];
	}];
	_player setVariable [QGVAR(curatorKEH), _eh_id];

};