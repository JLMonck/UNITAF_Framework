#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_countAIonHC_arr
//
// [] spawn fn_countAIonHC_arr; 
//
// Count the amount of AI on all HCs
//
// Example: 	
// 	_list = call fn_countAIonHC_arr; 
//----------------------------------------------------------------

//Count the AI amount on each HC
_hcList = call FUNC(darc_getHcList);

_hcAIcount = [];
{
	_hcAIcount pushback 0
} foreach _hcList;
// 1000 is set so that when sorting, these will be at the end. Stupid code...
// _hcAIcount = [1000,1000,1000,1000,1000,1000]; 
	
for "_i" from 0 to ((count _hcList) - 1) step 1 do { 
	// _hcx = owner (_hcList select _i); 
	_hcx = (_hcList select _i); 
	_c = _hcx call FUNC(darc_countAIonHC);  
	_hcAIcount set [_i, _c];  
}; 
_hcAIcount