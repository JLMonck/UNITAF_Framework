#include "script_component.hpp"

/*
 * Author: Grezvany13
 * Prevent death by bleeding out
 *
 * Arguments:
 * 0: player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call unitaf_client_fnc_godMode;
 *
 * Public: Yes
 */

#define DEFAULT_BLOOD_VOLUME				6.0
#define BLOOD_VOLUME_CLASS_1_HEMORRHAGE 	6.000 // lost less than 15% blood, Class I Hemorrhage
#define BLOOD_VOLUME_CLASS_2_HEMORRHAGE 	5.100 // lost more than 15% blood, Class II Hemorrhage
#define BLOOD_VOLUME_CLASS_3_HEMORRHAGE 	4.200 // lost more than 30% blood, Class III Hemorrhage
#define BLOOD_VOLUME_CLASS_4_HEMORRHAGE 	3.600 // lost more than 40% blood, Class IV Hemorrhage
#define BLOOD_VOLUME_FATAL 					3.0 // Lost more than 50% blood, Unrecoverable

#define BLOOD_VOLUME_CUSTOM_HEMORRHAGE		4.000

#define VAR_BLOOD_VOL						"ace_medical_bloodVolume"
#define GET_BLOOD_VOLUME(unit)				(unit getVariable [VAR_BLOOD_VOL, DEFAULT_BLOOD_VOLUME])

params ["_player"];

if (QGVAR(BleedOut) call CBA_settings_fnc_get) then {
	[_player] spawn {
		params ["_player"];

		while {true} do {
			if ((GET_BLOOD_VOLUME(_player) < BLOOD_VOLUME_CUSTOM_HEMORRHAGE) && GET_BLOOD_VOLUME(_player) > BLOOD_VOLUME_FATAL) then {
				_player setVariable [VAR_BLOOD_VOL, BLOOD_VOLUME_CUSTOM_HEMORRHAGE, true];
			};
			sleep 2;
		};
	};
};