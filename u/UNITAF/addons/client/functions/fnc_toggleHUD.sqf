#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Toggle the HUD for better screenshots
 *
 * Arguments:
 * NONE
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_client_fnc_toggleHUD;
 *
 * Public: Yes
 */

private _showHUD = uiNamespace getVariable [QGVAR(HUDshow), true];
private _shownHUD = uiNamespace getVariable [QGVAR(HUDshown), shownHUD];
private _shownChat = uiNamespace getVariable [QGVAR(ChatShown), shownChat];

if (_showHUD) then {
	// hide HUD
	uiNamespace setVariable [QGVAR(HUDshown), shownHUD];
	uiNamespace setVariable [QGVAR(HUDshow), false];
	// showHUD [hud, info, radar, compass, direction, menu, group, cursors, panels, kills]
	showHUD [false, false, false, false, false, false, false, false, false, false];

	uiNamespace getVariable [QGVAR(ChatShown), shownChat];
	showChat false;

	// FIX DUI - SQUAD RADAR
	diwako_dui_main_toggled_off = true;
	// FIX STHUD
	STUI_Canvas_ShownHUD = { false; };
} else {
	// show HUD
	uiNamespace setVariable [QGVAR(HUDshow), true];
	showHUD _shownHUD;
	showChat _shownChat;

	// FIX DUI - SQUAD RADAR
	diwako_dui_main_toggled_off = false;
	// FIX STHUD
	STUI_Canvas_ShownHUD = {
    	if (!alive(player)) exitWith {false};
    	if (!isNull(missionNamespace getVariable ["BIS_DEBUG_CAM", objNull])) exitWith {false};
    	if (!isNull(missionNamespace getVariable ["BIS_fnc_camera_cam", objNull])) exitWith {false};
    	true;
	};
};