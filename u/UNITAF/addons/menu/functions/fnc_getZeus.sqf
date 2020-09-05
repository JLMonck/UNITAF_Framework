#include "script_component.hpp"
params ["_player"];

[QEGVAR(ServerEvent,addToCurator), [_player]] call CBA_fnc_serverEvent;