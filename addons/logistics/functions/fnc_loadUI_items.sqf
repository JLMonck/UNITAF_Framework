#include "script_component.hpp"
disableSerialization;

params ["_ctrl"];
_dialog = ctrlParent _ctrl;
_state = "items";
uiNamespace setVariable ["unilog_log_dialog_state",_state];
lbClear (_dialog displayCtrl IDC_spawned_crate);
lnbClear (_dialog displayCtrl IDC_BIGBOX);
lnbClear (_dialog displayCtrl IDC_SMALLBOX);
[_dialog,_state] call FUNC(loadUI);