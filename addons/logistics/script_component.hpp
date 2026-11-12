#define COMPONENT logistics
#define COMPONENT_BEAUTIFIED Logistics

#include "\u\unitaf\addons\main\script_mod.hpp"

#include "\u\unitaf\addons\main\script_macros.hpp"

#define ADDITEMS(ITEM,COUNT) {ARR_2(#ITEM,COUNT)}

// Automatic packing uses carryable boxes only, up to the Weapons Box; the supply and Huron
// containers (10000 and up) are used only when someone picks one
#define AUTO_MAX_LOAD 1500
