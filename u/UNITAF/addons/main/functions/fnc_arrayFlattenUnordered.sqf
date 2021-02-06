for [{private _i = 0}, {_i < count _this}, {_i = _i + 1}] do { 
	if (_this select _i isEqualType []) then { 
		_this append (_this deleteAt _i); 
		_i = _i - 1; 
	}; 
}; 
_this
