#include "script_component.hpp"
disableSerialization;

params ["_box", "_player"];

//make sure is executed local on caller
if !(local _player) exitWith {
    _this remoteExec [QFUNC(action),_player];
};

//open dialog
createDialog "unitaf_logisticsMenu_main";
//createDialog "uni_log_dialog";

unitaf_logisticsMenu_bigBox = _box;
unitaf_logisticsMenu_bigBoxCargo = [];
unitaf_logisticsMenu_smallBoxCargo = [];
unitaf_logisticsMenu_smallBoxFreeSpace = [(configFile >> "CfgVehicles" >> SMALLBOX_CLASS),"maximumLoad"] call BIS_fnc_returnConfigEntry;

//change items/weapon/magazines/backpacks from format ["ITEM1","ITEM1","ITEM2"] to [["ITEM1",[2,"CfgWeapons"]],["ITEM2",[1,"Cfg.."]]]
{
    private _itemClass = _x;
    if ({_x select 0 isEqualTo _itemClass} count unitaf_logisticsMenu_bigBoxCargo isEqualTo 0) then {
        private _amount = {_x isEqualTo _itemClass}  count (weaponCargo _box);
        unitaf_logisticsMenu_bigBoxCargo pushBack [_itemClass, _amount, "CfgWeapons"];
    };
} forEach (weaponCargo _box);

{
    private _itemClass = _x;
    if ({_x select 0 isEqualTo _itemClass} count unitaf_logisticsMenu_bigBoxCargo isEqualTo 0) then {
        private _amount = {_x isEqualTo _itemClass}  count (magazineCargo _box);
        unitaf_logisticsMenu_bigBoxCargo pushBack [_itemClass, _amount,"CfgMagazines"];
    };
} forEach (magazineCargo _box);

{
    private _itemClass = _x;
    if ({_x select 0 isEqualTo _itemClass} count unitaf_logisticsMenu_bigBoxCargo isEqualTo 0) then {
        private _amount = {_x isEqualTo _itemClass}  count (itemCargo _box);
        unitaf_logisticsMenu_bigBoxCargo pushBack [_itemClass, _amount, "CfgWeapons"];
    };
} forEach (itemCargo _box);

{
    private _itemClass = _x;
    if ({_x select 0 isEqualTo _itemClass} count unitaf_logisticsMenu_bigBoxCargo isEqualTo 0) then {
        private _amount = {_x isEqualTo _itemClass}  count (backpackCargo _box);
        unitaf_logisticsMenu_bigBoxCargo pushBack [_itemClass, _amount, "CfgVehicles"];
    };
} forEach (backpackCargo _box);

waitUntil {! isNull(uiNamespace getVariable ["unitaf_logisticsMenu_main", displayNull])};
private _dialog = (uiNamespace getVariable ["unitaf_logisticsMenu_main", displayNull]);


//private _dialog = (uiNamespace getVariable ["uni_log_dialog", displayNull]);
uiNamespace setVariable ["unilog_log_dialog_state","items"];
[_dialog,"items"] call FUNC(loadUI);
