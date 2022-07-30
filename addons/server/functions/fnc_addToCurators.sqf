params ["_object"];

{
	_x addCuratorEditableObjects [[_object], true];
} forEach allCurators;