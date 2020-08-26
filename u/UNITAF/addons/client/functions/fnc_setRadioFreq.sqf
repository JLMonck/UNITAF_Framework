params ["_player", "_groupFrequency", "_parentGroupFrequency"];

// ensure TFAR is fully loaded for this client
TFAR_currentUnit = _player;
[
	{call TFAR_fnc_haveSWRadio},
	{
		params ["_player", "_groupFrequency", "_parentGroupFrequency"];

		// set radio(s)
		TFAR_currentUnit = _player;
		_hasSR = call TFAR_fnc_haveSWRadio;
		
		if (_hasSR) then {
			_sw_settings = (call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings;
			_groupFreq = [];

			// set frequencies CH:1 and CH:2
			_groupFreq set [0, str _groupFrequency];
			_groupFreq set [1, str _parentGroupFrequency];

			// set Channel 1 as default
			_sw_settings set [0, 0];
			// set Frequencies for CH1 and CH2
			_sw_settings set [2, _groupFreq];
			// set Channel 2 as alternative
			_sw_settings set [5, 1];

			diag_log str _sw_settings;

			// set settings on (active) SR radio of player
			[call TFAR_fnc_activeSwRadio, _sw_settings] call TFAR_fnc_setSwSettings;
		};
	},
	[_player, _groupFrequency, _parentGroupFrequency]
] call CBA_fnc_waitUntilAndExecute;