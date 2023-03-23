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
if(_runConnectionLog) {
	addMissionEventHandler ["OnUserConnected", { call FUNC(onConnect) }];
	addMissionEventHandler ["OnUserDisconnected", { call FUNC(onDisconnect) }];
	addMissionEventHandler ["OnUserKicked", { call FUNC(onKicked) }];
}

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
}, 5] call CBA_fnc_addPerFrameHandler;