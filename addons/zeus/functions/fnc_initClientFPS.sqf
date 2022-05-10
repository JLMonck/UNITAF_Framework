#include "script_component.hpp"
/**
 * Author: Katalam
 *         modified by Grezvany13
 * Client FPS counter in Zeus
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Public: No
 */

// for curators and admins show FPS counter underneath players
addMissionEventHandler ["Draw3D", {
    {
        // only continue with admins and curators
        private _isCurator = (!isNull (getAssignedCuratorLogic player));
        if !(_isCurator) exitWith {};

		private _update = QEGVAR(client,FPSUpdate) call CBA_settings_fnc_get;
		if (_update) then {
			private _distance = (ATLToASL (positionCameraToWorld [0,0,0])) distance _x;
        	// if camera is farther than 500 meters away from the targets the text will not display
			if (_distance < 500) then {
            	private _playerFPS = _x getVariable [QEGVAR(client,PlayerFPS), 50];

				// if the FPS is below 20 it turns red and becomes more visible for zeus/admin to see so they are aware
                drawIcon3D [
                    "", // path to image displayed near text
                    [[1,1,1,0.5], [1,0,0,0.7]] select (_playerFPS < 20), // color of the text using RGBA
                    ASLToAGL getPosASL _x, // position of the text _x referring to the player in 'allPlayers'
                    1, // width
                    2, // height from position, below
                    0, // angle
                    format ["%1 FPS: %2", name _x, str _playerFPS], // text to be displayed
                    0, // shadow on text, 0=none,1=shadow,2=outline
                    [0.03, 0.04] select (_playerFPS < 20), // text size
                    "PuristaMedium", // text font
                    "center" // align text left, right, or center
                ];

                if (_x getVariable [QEGVAR(client,hasUserData), false]) then {
                    private _playerData = _x getVariable [QEGVAR(client,userData), []];
                    if !(_playerData isEqualTo []) then {
                        drawIcon3D [
                            "", // path to image displayed near text
                            [1,1,1,0.5], // color of the text using RGBA
                            ASLToAGL getPosASL _x, // position of the text _x referring to the player in 'allPlayers'
                            1, // width
                            3, // height from position, below
                            0, // angle
                            format ["Role: %1 - Callsign: %2", (_playerData#14), (_playerData#9)], // text to be displayed
                            0, // shadow on text, 0=none,1=shadow,2=outline
                            0.03, // text size
                            "PuristaMedium", // text font
                            "center" // align text left, right, or center
                        ];
                    };
                };

            };
        };
    } forEach allPlayers;
}];