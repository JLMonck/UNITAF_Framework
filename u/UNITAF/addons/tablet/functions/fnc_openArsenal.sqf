params ["_unit"];

if (isClass (configFile >> "CfgPatches" >> "ace_arsenal")) then {
    [_unit, _unit, true] call ace_arsenal_fnc_openBox;
} else {
    ["Open", [true, nil, _unit]] call BIS_fnc_arsenal;
};

closeDialog 0;