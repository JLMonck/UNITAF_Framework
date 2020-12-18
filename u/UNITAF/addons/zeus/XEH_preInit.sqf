#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

ADDON = true;


// Add Custom modules is ZEN is available
if (isClass(configFile >> "CfgPatches" >> "zen_custom_modules")) then {
	//call FUNC(moduleRequestLogistics);
	//call FUNC(moduleHackTerminal);

	//call FUNC(moduleExportToSQM);
};