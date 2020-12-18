#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_ai_to_hc; 
//
// This will move the 
//
// Example: 	
// 	[] spawn fn_ai_to_hc; 
//----------------------------------------------------------------

//Parameters
_timeout = 20;
_group_cnt_to_send = 4;

//---------------

_hcList = call FUNC(darc_getHcList);
_ai_groups = call FUNC(darc_aiGroups);
diag_log format ["@darcAiMover: Headless client process running. (%1)", _hcList];

if ( count _hcList > 0) then {
	//Count AI on HCs
	_hcAIcount = call FUNC(darc_countAIonAllHC);

	//Find the HC with lowest amount AI
	_small_idx = 0;
	_smallest = _hcAIcount select _small_idx;
	{
		if (_x < _smallest) then {
			_small_idx = _foreachindex;
		};
	} forEach _hcAIcount;
	
	_HC = owner (_hcList select _small_idx);
	diag_log format ["@darcAiMover: AI on HC: %1 . Sending to %2.", _hcAIcount, (_hcList select _small_idx)];
	// diag_log format ["@darcAiMover: (%1) is smallest %2", _small_idx, _hcAIcount];

	// Check if chosen HC is ready
	if (_HC > 0) then {	
		_g_fr = [];
		_g_nonfr = [];
		{
			// Read timeBorn from groups
			private _timeBorn = _x getVariable ["timeBorn", -1];
			if (_timeBorn isEqualTo -1) then {
				// If timeBorn does not exist, create one
				// diag_log format ["@darcAiMover: Group %1 set timeBorn=%2", _x, time];
				_x setVariable ["timeBorn", time, true];
			} else {	
				// A group can only be moved after a minimum of 20 secs in game
				// Find the groups that are still on server and collect to _g_fr.
				if ( ( (_timeborn + _timeout) < time ) AND ( groupOwner _x == 2 ) ) then {		
					// diag_log format ["@darcAiMover: Group %1 (o: %4) timeBorn=%2 (< %3)", _x, (_timeborn + 20), time, groupOwner _x];
					_g_fr pushback _x;
				} else {
					// diag_log format ["@darcAiMover: Group %1 (o: %4) timeBorn=%2 (< %3) - nonmovable", _x, (_timeborn + 20), time, groupOwner _x];
					_g_nonfr pushback _x;
				};
			};
		} foreach _ai_groups;

		diag_log format ["@darcAiMover: %1 movable groups. %2 non movable groups.", count _g_fr, count _g_nonfr];

		if (count _g_fr > _group_cnt_to_send) then {
			// We move _group_cnt_to_send groups at a time. This will share the load more evenly.
			_g_fr resize _group_cnt_to_send;
		};
		
		{
			diag_log format ["@darcAiMover: Group %1 moved to HC %2 from %3", _x, _HC, groupOwner _x];
			_x setGroupOwner _HC;
		} foreach _g_fr;
	};
} else {
	diag_log format["@darcAiMover: No headless clients in use."];
};