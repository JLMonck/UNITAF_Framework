#include "script_component.hpp"
params ["_ctrl","_index"];
private _dialog = ctrlParent _ctrl;
_state = uiNamespace getVariable "unilog_log_dialog_state";
[_dialog,_state] call FUNC(loadUI);