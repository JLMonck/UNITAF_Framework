#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_get_hcList; 
//
// Get a list of _actual_ headless clients that are in game. 
// NOTE: entities "HeadlessClient_F" returns a list of HC slots in a mission.
//
// Example: 	
// 	_hcList = call fn_get_hcList;
//----------------------------------------------------------------

_hcList = allPlayers - (allPlayers - entities "HeadlessClient_F");
_hcList
