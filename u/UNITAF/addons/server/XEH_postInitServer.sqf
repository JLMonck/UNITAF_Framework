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

[QEGVAR(ServerEvent,addToCurator), {
	_this call FUNC(addToCurators);
}] call CBA_fnc_addEventHandler;


/**
 * Start running the scripts needed on the server
 */

// Only run on missions which require the database
if ((getMissionConfigValue ["UNITAF_runDatabase", 0]) isEqualTo 1) then {
	// ensure database is available
	call FUNC(initDatabase);

	_operationId = getMissionConfigValue ["UNITAF_operationId", 0];
	if (_operationId isEqualTo 0) then {
		_operationId = missionName;
	};

	if ((getMissionConfigValue ["UNITAF_useORBAT", 0]) isEqualTo 1) then {
		// get/set callsigns from ORBAT
		[_operationId] call FUNC(queryORBATGroups);
	};
};