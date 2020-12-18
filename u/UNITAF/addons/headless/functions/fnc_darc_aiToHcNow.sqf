#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_ai_to_hc_now; 
//
// Move all AI to random HC immediately. This is for debugging.
//
// Example: 	
// 	[] spawn fn_ai_to_hc_now; 
//----------------------------------------------------------------
_hcList = call FUNC(darc_getHcList);
systemChat format ["@darcAiMover: Moving all to HC. (%1)", _hcList];

if ( count _hcList > 0 ) then {
	{
		private _timeBorn = _x getVariable "timeBorn";
		
		if ( (_timeborn + 20) < time ) then {
			_HC = selectRandom _hcList;			
			diag_log format ["@darcAiMover: Group %1 moved to HC %2 from %3", _x, _HC, groupOwner _x];
			_x setGroupOwner (owner _HC);
		} else {
			diag_log format ["@darcAiMover: Group %1 is too young (%2 < %3).", _x, (_timeborn + 20), time];
		};
	} foreach allGroups;
};
