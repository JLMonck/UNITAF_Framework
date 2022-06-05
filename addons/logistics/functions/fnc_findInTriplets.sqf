#include "script_component.hpp"
params ["_array","_key"];

private _index = -1;

{
    if (_key in _x) exitWith {
        _index = _forEachIndex;
    };
} forEach _array;
hint str _index;
_index
