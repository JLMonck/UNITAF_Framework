params ["_amount", ["_type", nil]];

_array = [];
_array resize _count;

// return array with nil
// if (_type isEqualTo nil) then {
	// already done :D
// };

// return array starting at 0, as integer
if (_type isEqualTo 0) then {
	{
		_array set [_forEachIndex, _forEachIndex];
	} forEach _array;
};

// return array starting at 1 as integer
if (_type isEqualTo 1) then {
	{
		_array set [_forEachIndex, (_forEachIndex + 1)];
	} forEach _array;
};

// return array starting at 0, as string
if (_type isEqualTo "0") then {
	{
		_array set [_forEachIndex, format ["%1", _forEachIndex]];
	} forEach _array;
};

// return array starting at 1, as string
if (_type isEqualTo "1") then {
	{
		_array set [_forEachIndex, format ["%1", (_forEachIndex + 1)]];
	} forEach _array;
};

// return array starting at a, all lowercase letters, a-zzzzz
if (_type isEqualTo "a") then {
	// not yet implemented
};

// return array starting at A, all uppercase letters, A-ZZZZZ
if (_type isEqualTo "A") then {
	// not yet implemented
};

// return array with "some_string_%1", and replace %1 with nummber starting at 1
if (_type find "%1") then {
	{
		_array set [_forEachIndex, format [_type, (_forEachIndex + 1)]];
	} forEach _array;
};

_array