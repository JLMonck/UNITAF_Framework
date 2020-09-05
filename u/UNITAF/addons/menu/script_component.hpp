#define COMPONENT menu
#define COMPONENT_BEAUTIFIED Menu

#include "\u\unitaf\addons\main\script_mod.hpp"

#include "\u\unitaf\addons\main\script_macros.hpp"

#include "defines.inc"

#define GET_CLOSE(DISPLAY)	(DISPLAY displayCtrl IDC_CLOSE)
#define GET_BACK(DISPLAY)	(DISPLAY displayCtrl IDC_BACK)

#define GET_MAIN(DISPLAY)	(DISPLAY displayCtrl IDC_CONTROL_MAIN)
#define GET_OPORD(DISPLAY)	(DISPLAY displayCtrl IDC_CONTROL_OPORD)
#define GET_ORBAT(DISPLAY)	(DISPLAY displayCtrl IDC_CONTROL_ORBAT)
#define GET_ADMIN(DISPLAY)	(DISPLAY displayCtrl IDC_CONTROL_ADMIN)

#define GET_IN_MAIN(DISPLAY,IDC)	(GET_MAIN(DISPLAY) controlsGroupCtrl IDC)
#define GET_IN_OPORD(DISPLAY,IDC)	(GET_OPORD(DISPLAY) controlsGroupCtrl IDC)
#define GET_IN_ORBAT(DISPLAY,IDC)	(GET_ORBAT(DISPLAY) controlsGroupCtrl IDC)
#define GET_IN_ADMIN(DISPLAY,IDC)	(GET_ADMIN(DISPLAY) controlsGroupCtrl IDC)