#include "script_component.hpp"
/**
 * Author: Grezvany13
 * Opens the Admin Page on the tablet
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */

private _display = GET_TABLET;

if (_display isEqualTo displayNull) exitWith {};

[GET_ADMIN] call FUNC(hideAll);
GET_ADMIN ctrlShow true;

//GET_IN_ADMIN(IDC_Tablet_Admin_FPS_local) ctrlSetStructuredText parseText format ["Local FPS: %1 fps", ];