#include "script_component.hpp"

params ["_display"];

_ctrLoadORBAT = _display displayCtrl 455001;	// IDC_LoadORBAT

if (
	(getMissionConfigValue ['UNITAF_useORBAT', 0]) isEqualTo 1
	&& {[player] call FUNC(canAccessORBAT)}
) then {
	_ctrLoadORBAT ctrlEnable true;
	// _ctrLoadORBAT ctrlShow true;
	systemChat "ORBAT Enabled";
} else {
	_ctrLoadORBAT ctrlEnable false;
	// _ctrLoadORBAT ctrlShow false;
	systemChat "ORBAT Disabled";
};
