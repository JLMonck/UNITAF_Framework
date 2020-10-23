#define COMPONENT tablet
#define COMPONENT_BEAUTIFIED Tablet

#include "\u\unitaf\addons\main\script_mod.hpp"

#include "\u\unitaf\addons\main\script_macros.hpp"

#include "defines.inc"


#define HIDE_NOT_CURRENT(DISPLAY,CURRENT) if !(DISPLAY isEqualTo CURRENT) then { DISPLAY ctrlShow false; };

#define GET_TABLET				(uiNamespace getVariable [QGVAR(tabletDisplay), displayNull])

#define GET_WELCOME				(GET_TABLET displayCtrl IDC_Tablet_Welcome)
#define GET_IN_WELCOME(IDC)		(GET_WELCOME controlsGroupCtrl IDC)

#define GET_MAP					(GET_TABLET displayCtrl IDC_Tablet_Map)
#define GET_IN_MAP(IDC)			(GET_MAP controlsGroupCtrl IDC)

#define GET_MAIN				(GET_TABLET displayCtrl IDC_Tablet_Main)
#define GET_IN_MAIN(IDC)		(GET_MAIN controlsGroupCtrl IDC)

#define GET_ADMIN				(GET_TABLET displayCtrl IDC_Tablet_Admin)
#define GET_IN_ADMIN(IDC)		(GET_ADMIN controlsGroupCtrl IDC)

#define GET_OPORD				(GET_TABLET displayCtrl IDC_Tablet_OPORD)
#define GET_IN_OPORD(IDC)		(GET_ADMIN controlsGroupCtrl IDC)

#define GET_ORBAT				(GET_TABLET displayCtrl IDC_Tablet_ORBAT)
#define GET_IN_ORBAT(IDC)		(GET_ORBAT controlsGroupCtrl IDC)