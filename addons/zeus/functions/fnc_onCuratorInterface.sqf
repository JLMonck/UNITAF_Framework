#include "script_component.hpp"

params [["_display",displayNull],["_eventType","Close"]];

GVAR(inCuratorInterface) = false;

switch _eventType do {
	case "Open": {
		GVAR(inCuratorInterface) = true;
	};
	case "Close": {
		GVAR(inCuratorInterface) = false;
	};
};