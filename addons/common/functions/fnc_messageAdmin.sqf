#include "script_component.hpp"
/*
 * Author: Katalam
 * Message the logged in admin.
 *
 * Arguments:
 * 0: Message <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * ["My Message"] call UNITAF_common_fnc_messageAdmin;
 *
 * Public: No
 */

params [
    ["_message", "", [""]]
];

if (_message == "") exitWith {};

{
    if ((admin owner _x) > 1) then {
        [_message, true, 5, 2] remoteExecCall [QACEFUNC(common,displayText), _x, true];
    }
} forEach allPlayers;
