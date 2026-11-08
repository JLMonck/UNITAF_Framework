params [["_traits", ""]];

// the role's capabilities on the website, as a comma separated list of slugs
_traits = _traits splitString ",";

// set ACE_GForceCoef for pilots
if ("aircrew" in _traits) then {
	player setVariable ["ACE_GForceCoef", 0.55];
};
// set ACE_GForceCoef for MERT
if ("mert" in _traits) then {
	player setVariable ["ACE_GForceCoef", 0.8];
};

// set camouflageCoef for marksmen
if ("marksman" in _traits) then {
	player setUnitTrait ["camouflageCoef", 0.6];
};
// set camouflageCoef for sniper/spotter
if ("sniper" in _traits) then {
	player setUnitTrait ["camouflageCoef", 0.3];
};

// set UAV Hacker for UAV operators
if ("uav-operator" in _traits) then {
	player setUnitTrait ["UAVHacker", true];
};
