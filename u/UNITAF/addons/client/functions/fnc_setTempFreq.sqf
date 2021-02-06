/**
 * Author: Grezvany13
 * Set Channel 3 frequency (based on ORBAT) and put it on 'active'
 *
 * Arguments:
 * 0: freq <FLOAT|STRING>
 *
 * Return Value:
 * None
 *
 * Public:
 * No
 */
params ["_freq"];

// ensure TFAR is fully loaded for this client
//TFAR_currentUnit = player;
TFAR_currentUnit = call TFAR_fnc_currentUnit;
[
	{call TFAR_fnc_haveSWRadio},
	{
		params ["_freq"];

		if (typeName _freq == "SCALAR") then {
			_freq = str _freq;
		};

		// set radio(s)
		//TFAR_currentUnit = player;
		TFAR_currentUnit = call TFAR_fnc_currentUnit;
		private _hasSR = call TFAR_fnc_haveSWRadio;
		
		if (_hasSR) then {
			private _sw_settings = (call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings;
			
			private _curFreq = _sw_settings select 2;
			_curFreq set [2, _freq];

			// set Channel 3 as active
			_sw_settings set [0, 2];
			// set Frequencies
			_sw_settings set [2, _curFreq];

			// set settings on (active) SR radio of player
			[call TFAR_fnc_activeSwRadio, _sw_settings] call TFAR_fnc_setSwSettings;
		};
	},
	[_freq]
] call CBA_fnc_waitUntilAndExecute;