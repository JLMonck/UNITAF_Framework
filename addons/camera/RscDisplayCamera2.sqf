#include "script_component.hpp"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		//['Init',_params] spawn (uinamespace getvariable QFUNC(camera));
		["Init", _params] spawn FUNC(camera);
	};
	case "onUnload": {
		//['Exit',_params] spawn (uinamespace getvariable  QFUNC(camera));
		["Exit", _params] spawn FUNC(camera);
	};
};