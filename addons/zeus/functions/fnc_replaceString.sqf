params ["_text", "_filter", "_new"];

private ["_textArray","_filterArray","_match","_replace","_break","_i","_x","_currentCharacter"];

_textArray 		= toarray _text;
_filterArray 	= toarray _filter;
_replace 		= toArray _new;
_break			= false;

for [{_x=0},{_x< (count _textArray)},{_x=_x+1}] do {
	_currentCharacter = _textArray select _x;
	if (_currentCharacter == _filterArray select 0) then {
		_match = true; 
		for [{_i=0},{_i< count _filterArray},{_i=_i+1}] do {
			if (_textArray select (_x+_i) != _filterArray select _i) then {_match = false}; 
		};
		
		if (_match) then {
			for [{_i=0},{_i< count _filterArray},{_i=_i+1}] do {
				_textArray set [(_x+_i),-1]; 
			};
			_textArray = [_textArray, _replace, _x] call BIS_fnc_arrayInsert;
		};
	};
};

_textArray = _textArray - [-1];

tostring _textArray; //return replaced string