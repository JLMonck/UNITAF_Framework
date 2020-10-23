#include "script_component.hpp"

params ["_player"];

// Create new UNITAF group
_player createDiarySubject [
	QGVAR(briefing),
	"UNITAF",
	""
];

// Add Tablet
_tabletText = [];
_tabletText pushBack "The UNTIAF Tablet, or UNITAB, is the core of each operation.<br/>";
_tabletText pushBack format ["To access the tablet, simply press <font color='#c48214'>%1</font><br/><br/>", (["open_unitaf_tablet"] call FUNC(keybindToString))];
//_tabletText pushBack "<img image='\A3\Ui_F_Curator\Data\Logos\arma3_curator_artwork.jpg' width='500' height='300'/><br/><br/>";
_tabletText pushBack "<font size='18'>Load ORBAT</font><br/>";
_tabletText pushBack "At the start of any operation or training, make sure you press the 'Load ORBAT' button to get access to your default loadout, set radio channels and get access to your personal Arsenal.<br/><br/>";
//_tabletText pushBack "<font size='18'>ORBAT</font><br/>";
//_tabletText pushBack "In case you need to see who is playing in which squad/fireteam, simply check the in-game ORBAT. It will also allow you to quickly set Ch.3 on your radio to the frequency of that team in case of emergencies.<br/><br/>";
//_tabletText pushBack "<font size='18'>OPORD</font><br/>";
//_tabletText pushBack "All operations have an OPeration ORDer, explaining what the mission is about and what your tasks are. Here you can access it and read it in-game.<br/><br/>";
_tabletText pushBack "<font size='18'>The 'OOPS' buttons</font><br/>";
_tabletText pushBack "If, for whatever reason, you lost your radio, forgot your earplugs or are in need of some NVG's, simply press the button to get it without the need of respawing or requesting a resupply.<br/><br/>";
_tabletText pushBack "For more information, check out the full documentation on <a href='http://docs.unitedtaskforce.net/w/unitaf_framework/'>Phabricator</a>";

_player createDiaryRecord [
	QGVAR(briefing),
	[
		"UNITAF Tablet",
		(_tabletText joinString "")
	],
	taskNull,
	"",
	true
];