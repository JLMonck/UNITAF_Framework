[] spawn {
  	waitUntil {!isNull findDisplay 420000};

	_display = uiNamespace getVariable ["RscDisplayMain", displayNull];

	waitUntil { !( isNull (_display displayctrl 420001)) };
	_control = (_display displayctrl 420001);

	0 = [_control] spawn {
		params ["_control"];

		_images = [
			"background1.paa",
			"background2.paa",
			"background3.paa",
			"background4.paa",
			"background5.paa",
			"background6.paa",
			"background7.paa",
			"background8.paa",
			"background9.paa",
			"background10.paa"
		];
		_curImage = -1;

		// while { (ctrlVisible 420001) } do {
		while {true} do {
			_curImage = _curImage + 1;
			if (count _images <= _curImage) then {
				_curImage = 0;
			};
			_control ctrlSetText format ["\u\unitaf\addons\mainmenu\data\background\%1", (_images select _curImage)];
			uiSleep 10;
		};
	};
};