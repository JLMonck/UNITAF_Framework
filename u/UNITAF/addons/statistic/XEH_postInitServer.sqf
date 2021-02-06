#include "script_component.hpp"

GVAR(fragsOut) = [];
GVAR(shotsFired) = [];
GVAR(launcherFired) = [];
GVAR(handGunFired) = [];
GVAR(aiKilled) = 0;
GVAR(bandagesAppliedServer) = [];
GVAR(pulseCheckedServer) = [];
GVAR(cprPerformedServer) = [];
GVAR(vehicleFired) = 0;

addMissionEventHandler ["EntityKilled", {
    params ["_unit"];

    if (_unit isKindOf "Man") then {
        if (!(isPlayer _unit)) then {
            GVAR(aiKilled) = GVAR(aiKilled) + 1;
        };
    };
}];

["CAManBase", "Fired", {
    params ["_unit", "_weapon"];

    _fnc_increaseGVAR = {
        params [
            ["_array", [], [[]]],
            ["_uid", "", [""]]
        ];

        _idx = _array findIf {
            _x params ["_uidArray", "_value"];
            _uid == _uidArray;
        };
        if (_idx > -1) then {
            _val = _array select _idx select 1;
            _array set [0, [_array select _idx select 0, _val + 1]];
        } else {
            _array append [[_uid, 1]];
        };
    };

    if (isPlayer _unit) then {
        if (_weapon isEqualTo "Throw") then {
            [GVAR(fragsOut), getPlayerUID _unit] call _fnc_increaseGVAR;
        };
        if (_weapon isEqualTo primaryWeapon _unit) then {
            [GVAR(shotsFired), getPlayerUID _unit] call _fnc_increaseGVAR;
        };
        if (_weapon isEqualTo secondaryWeapon _unit) then {
            [GVAR(launcherFired), getPlayerUID _unit] call _fnc_increaseGVAR;
        };
        if (_weapon isEqualTo handgunWeapon _unit) then {
            [GVAR(handGunFired), getPlayerUID _unit] call _fnc_increaseGVAR;
        };
    };
}] call CBA_fnc_addClassEventHandler;

["Car", "Fired", {
    params ["_unit", "", "", "", "", "", "", "_vehicle"];

    if (isPlayer _unit && !(_vehicle isEqualTo objNull)) then {
        GVAR(vehicleFired) = GVAR(vehicleFired) + 1;
    };
}] call CBA_fnc_addClassEventHandler;
