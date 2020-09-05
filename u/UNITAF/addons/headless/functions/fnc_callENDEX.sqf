params ["_units"];

// disable all AI on server and HC's
{
	_x disableAI "ALL";
} forEach _units;