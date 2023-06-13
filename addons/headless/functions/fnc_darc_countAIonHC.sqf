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
private _hc_owner = owner _hc;

private _c = 0;
private _g = 0;
_c = count ((allUnits - allPlayers) select {(owner _x == _hc_owner)});
_g = count (allGroups select {(groupOwner _x == _hc_owner)});

missionNameSpace setVariable [format ["%1_%2", QGVAR(HCUnits), (name _hc)], _c, true];
missionNameSpace setVariable [format ["%1_%2", QGVAR(HCGroups), (name _hc)], _g, true];

_c 