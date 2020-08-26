params ["_config"];

_containers = [
	["47/190", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/200", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/201", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/202", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/203", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/204", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/205", [["ACE_Splint", 10], ["ACE_Morphine", 10]]],
	["47/206", [["ACE_Splint", 10], ["ACE_Morphine", 10]]]
];

_containers select { (_x select 0) isEqualTo _config } select 0 select 1;
