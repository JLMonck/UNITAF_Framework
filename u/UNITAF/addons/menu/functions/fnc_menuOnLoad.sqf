params ["_displayorcontrol"];

if ((getMissionConfigValue ['UNITAF_useORBAT', 0]) isEqualTo 1) then {
	ctrlEnable [455001, true];
} else {
	ctrlEnable [455001, false];
};
