#include "script_component.hpp"
/**
 * source: https://github.com/mokdevel/darcAiMover
 */

//----------------------------------------------------------------
// fn_countAIonHC
//
// [HC1] spawn fnc_countAIonHC; 
//
// Count the amount of AI on certain HC
//
// Example: 	
// 	[] spawn fnc_countAIonHC; 
//----------------------------------------------------------------
params [["_hc", ""]];
_hc_owner = owner _hc;

_c = 0;
_c = count ((allUnits - allPlayers) select {(owner _x == _hc_owner)});
_c 