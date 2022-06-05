#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
GVAR(items) = [];
GVAR(vehicles) = [];
GVAR(crates) = [];

PREP_RECOMPILE_END;
#include "cba_settings.sqf"
ADDON = true;