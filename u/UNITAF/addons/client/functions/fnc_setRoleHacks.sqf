params ["_role"];

// to lower, for better comparison
_role = toLowerANSI _role;

// set ACE_GForceCoef for pilots
if ("pilot" in _role || "jet" in _role || "rotary" in _role || "fixed wing" in _role) then {
	player setVariable ["ACE_GForceCoef", 0.55];
};
// set ACE_GForceCoef for MERT
if ("mert" in _role) then {
	player setVariable ["ACE_GForceCoef", 0.8];
};

// set camouflageCoef for marksmen
if ("marksman" in _role) then {
	player setUnitTrait ["camouflageCoef", 0.6];
};
// set camouflageCoef for sniper/spotter
if ("sniper" in _role || "spotter" in _role) then {
	player setUnitTrait ["camouflageCoef", 0.3];
};