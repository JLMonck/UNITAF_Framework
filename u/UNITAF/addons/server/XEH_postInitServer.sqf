#include "script_component.hpp"

/**
 * Set Event Handlers
 */
["UNITAF_ServerEvent_ORBATGroups", {
	_this call FUNC(setORBATGroups);
}] call CBA_fnc_addEventHandler;

["UNITAF_ServerEvent_queryPlayerInventory", {
	_this call FUNC(queryPlayerInventory);
}] call CBA_fnc_addEventHandler;
["UNITAF_ServerEvent_queryPlayerData", {
	_this call FUNC(queryPlayerData);
}] call CBA_fnc_addEventHandler;
["UNITAF_ServerEvent_queryPlayerArsenal", {
	_this call FUNC(queryPlayerArsenal);
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