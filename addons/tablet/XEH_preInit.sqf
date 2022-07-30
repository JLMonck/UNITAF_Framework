#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#include "cba_keybinds.sqf"
#include "cba_settings.sqf"

// Disable CBA inventory attribute preload
uiNamespace setVariable ["cba_ui_curatorItemCache", []];

call FUNC(logisticsPreload);

ADDON = true;
