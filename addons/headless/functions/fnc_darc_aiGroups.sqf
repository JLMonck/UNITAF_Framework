#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_ai_groups; 
//
// List of groups with only AI.
//
//----------------------------------------------------------------
private _plr_grp = []; 
{
	_plr_grp pushBackUnique group _x
} forEach allPlayers;
private _ai_grp = allGroups - _plr_grp;
_ai_grp