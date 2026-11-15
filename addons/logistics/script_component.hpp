#define COMPONENT logistics
#define COMPONENT_BEAUTIFIED Logistics

#include "\u\unitaf\addons\main\script_mod.hpp"

#include "\u\unitaf\addons\main\script_macros.hpp"

#define ADDITEMS(ITEM,COUNT) {ARR_2(#ITEM,COUNT)}

// The mod's own boxes, used when the website's allowed boxes are not (2.6.0): automatic packing
// uses carryable ones only, up to the Weapons Box; the supply and Huron containers (10000 and up)
// only when someone picks one. The website's boxes say for themselves (their Automatic tick).
#define AUTO_MAX_LOAD 1500
