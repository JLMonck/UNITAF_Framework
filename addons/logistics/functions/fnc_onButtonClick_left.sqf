#include "script_component.hpp"

params ["_ctrl"];

private _dialog = ctrlParent _ctrl;

if ((_dialog displayCtrl IDC_SMALLBOX) lnbText [lnbCurSelRow (_dialog displayCtrl IDC_SMALLBOX), 0] isEqualTo "") exitWith {};

private _itemClass = (_dialog displayCtrl IDC_SMALLBOX) lnbData [lnbCurSelRow (_dialog displayCtrl IDC_SMALLBOX),0];

private _bigIndex = [unitaf_logisticsMenu_bigBoxCargo,_itemClass] call FUNC(findInTriplets);
private _smallIndex = [unitaf_logisticsMenu_smallBoxCargo,_itemClass] call FUNC(findInTriplets);;

private _amount = parseNumber ((_dialog displayCtrl IDC_AMOUNT) lbText (lbCurSel (_dialog displayCtrl IDC_AMOUNT)));
private _maxamount = (unitaf_logisticsMenu_smallBoxCargo select _smallIndex) select 1;
private _amount = _maxamount min _amount;

//add to bigBoxCargo
if (_bigIndex isEqualTo -1) then {
    unitaf_logisticsMenu_bigBoxCargo pushBack [_itemClass,_amount, (unitaf_logisticsMenu_smallBoxCargo select _smallIndex) select 2];
} else {
    private _oldAmount = (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) select 1;
    (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) set [1,_oldAmount+_amount];
};

//remove from smallBoxCargo
if (_maxamount isEqualTo _amount) then {
    unitaf_logisticsMenu_smallBoxCargo deleteAt _smallIndex;
} else {
    (unitaf_logisticsMenu_smallBoxCargo select _smallIndex) set [1, ((unitaf_logisticsMenu_smallBoxCargo select _smallIndex) select 1) - _amount];
};
_state = uiNamespace getVariable "unilog_log_dialog_state";
[_dialog,_state] call FUNC(loadUI);
