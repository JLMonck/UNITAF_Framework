#include "script_component.hpp"

/**
 * Set Event Handlers
 */
[QEGVAR(ServerEvent,ORBATGroups), {
	_this call FUNC(setORBATGroups);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ServerEvent,queryPlayerInventory), {
	_this call FUNC(queryPlayerInventory);
}] call CBA_fnc_addEventHandler;
[QEGVAR(ServerEvent,queryPlayerData), {
	_this call FUNC(queryPlayerData);
}] call CBA_fnc_addEventHandler;
[QEGVAR(ServerEvent,queryPlayerArsenal), {
	_this call FUNC(queryPlayerArsenal);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ServerEvent,getFullORBAT), {
	//_this call FUNC(queryFullORBAT);
}] call CBA_fnc_addEventHandler;
[QEGVAR(ServerEvent,setFullORBAT), {
	//_this call FUNC(setFullORBAT);
}] call CBA_fnc_addEventHandler;

[QEGVAR(ServerEvent,addToCurator), {
	_this call FUNC(makeCurator);
}] call CBA_fnc_addEventHandler;

// Enable connection logging (connect, disconnect, kick)
private _runConnectionLog = QGVAR(Server_connectionLog) call CBA_settings_fnc_get;
if(_runConnectionLog) then {
	addMissionEventHandler ["OnUserConnected", { call FUNC(onConnect) }];
	addMissionEventHandler ["OnUserDisconnected", { call FUNC(onDisconnect) }];
	addMissionEventHandler ["OnUserKicked", { call FUNC(onKicked) }];
};

/**
 * Start running the scripts needed on the server
 */

// Only run on missions which require the database
if ((getMissionConfigValue ["UNITAF_runDatabase", 0]) isEqualTo 1) then {
	// ensure database is available
	private _hasDB = call FUNC(initDatabase);
	missionNamespace setVariable ['UNITAF_databaseAvailable', _hasDB, true];

	// stop doing everything when DB Is not available
	if !(_hasDB) exitWith {
		missionNamespace setVariable ['UNITAF_operationID', 0, true];
		missionNamespace setVariable ['UNITAF_useORBAT', false, true];
	};

	private _operationId = getMissionConfigValue ["UNITAF_operationId", 0];
	if (_operationId isEqualTo 0) then {
		_operationId = missionName;
	};
	missionNamespace setVariable ['UNITAF_operationID', _operationId, true];

	// name the deployment, and notice an id that belongs to nothing
	[_operationId] call FUNC(queryMission);

	// once a minute, tell the website who is on (first run after a minute, once init has settled)
	if (_runConnectionLog) then {
		[{ call FUNC(logPresence) }, 60] call CBA_fnc_addPerFrameHandler;
	};

	if ((getMissionConfigValue ["UNITAF_useORBAT", 0]) isEqualTo 1) then {
		missionNamespace setVariable ['UNITAF_useORBAT', true, true];
		// get Full ORBAT
		// [_operationId] call FUNC(queryFullORBAT);
		
		// get/set callsigns from ORBAT
		[_operationId] call FUNC(queryORBATGroups);
	};
};

// let server update its FPS into a public variable based on a fixed update interval (5sec)
[{
	missionNameSpace setVariable [QGVAR(ServerFPS), floor diag_fps, true];
	// lowest since the last presence snapshot, for the website (local only, never broadcast)
	missionNameSpace setVariable [QGVAR(ServerFPSMin), (missionNameSpace getVariable [QGVAR(ServerFPSMin), diag_fpsMin]) min diag_fpsMin];

	// clients send their FPS to the server only; pass them on in one message to each Zeus for the FPS counter
	private _curators = ((allCurators apply { getAssignedCuratorUnit _x }) select { !isNull _x && { isPlayer _x } });
	if (_curators isNotEqualTo []) then {
		private _pairs = ((allPlayers - entities "HeadlessClient_F") apply { [_x, _x getVariable [QEGVAR(client,PlayerFPS), -1]] }) select { (_x select 1) >= 0 };
		[QGVAR(curatorPlayerFPS), [_pairs], _curators] call CBA_fnc_targetEvent;
	};
}, 5] call CBA_fnc_addPerFrameHandler;
