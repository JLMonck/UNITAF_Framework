#include "script_component.hpp"

params ["_ctrl"];

private _dialog = ctrlParent _ctrl;

if ((_dialog displayCtrl IDC_BIGBOX) lnbText [lnbCurSelRow (_dialog displayCtrl IDC_BIGBOX), 0] isEqualTo "") exitWith {};

private _itemClass = (_dialog displayCtrl IDC_BIGBOX) lnbData [lnbCurSelRow (_dialog displayCtrl IDC_BIGBOX),0];
private _configClass = (_dialog displayCtrl IDC_BIGBOX) lnbData [lnbCurSelRow (_dialog displayCtrl IDC_BIGBOX),0];

private _bigIndex = [unitaf_logisticsMenu_bigBoxCargo,_itemClass] call FUNC(findInTriplets);
private _smallIndex = [unitaf_logisticsMenu_smallBoxCargo,_itemClass] call FUNC(findInTriplets);

private _amount = parseNumber ((_dialog displayCtrl IDC_AMOUNT) lbText (lbCurSel (_dialog displayCtrl IDC_AMOUNT)));
private _maxamount = (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) select 1;
private _amount = _maxamount min _amount;

//check wether there is enough space for the items
private _canAmount = floor (unitaf_logisticsMenu_smallBoxFreeSpace / ([_itemClass, (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) select 2] call FUNC(itemMass)));

if (_canAmount isEqualTo 0) exitWith {
    systemChat format ["WARNING: Due to overflow %1 couldn't been added.", (_dialog displayCtrl IDC_BIGBOX) lnbText [lnbCurSelRow (_dialog displayCtrl IDC_BIGBOX),2]];
};
if (_amount > _canAmount) then {
    _amount = _canAmount;
    systemChat format ["WARNING: Due to overflow only %1 %2 have been added.", _canAmount, (_dialog displayCtrl IDC_BIGBOX) lnbText [lnbCurSelRow (_dialog displayCtrl IDC_BIGBOX),2]];
};

//add to smallBoxCargo
if (_smallIndex isEqualTo -1) then {
    unitaf_logisticsMenu_smallBoxCargo pushBack [_itemClass,_amount, (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) select 2];
} else {
    private _oldAmount = (unitaf_logisticsMenu_smallBoxCargo select _smallIndex) select 1;
    (unitaf_logisticsMenu_smallBoxCargo select _smallIndex) set [1,_oldAmount+_amount];
};

//remove from bigBoxCargo
if (_maxamount isEqualTo _amount) then {
    unitaf_logisticsMenu_bigBoxCargo deleteAt _bigIndex;
} else {
    (unitaf_logisticsMenu_bigBoxCargo select _bigIndex) set [1, ((unitaf_logisticsMenu_bigBoxCargo select _bigIndex) select 1) - _amount];
};
_state = uiNamespace getVariable "unilog_log_dialog_state";
[_dialog,_state] call FUNC(loadUI);
