private ["_res", "_fnc"];
_res = [];
_fnc = {
	{
		if (typeName _x isEqualTo "ARRAY") then [
			{_x call _fnc; false},
			{_res pushBack _x; false}
		];
	} count _this;
};
_this call _fnc;
_res