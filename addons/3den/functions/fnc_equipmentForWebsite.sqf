#include "script_component.hpp"
/*
 * Author: UNITAF
 * Eden editor: UNITAF > Copy equipment for the website (D-473). Reads the list copied from the
 * website's Fill in equipment page, looks each class name up in this game's config, and
 * copies the answer back to the clipboard to paste on the website. The clipboard only works
 * outside multiplayer, so this lives in the editor.
 *
 * The body below is the website's resources/arma3/equipment-for-website.sqf, the same code the
 * website hands players as a Debug Console script; change both together.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_3den_fnc_equipmentForWebsite;
 *
 * Public: No
 */

private _request = copyFromClipboard;
private _lines = _request splitString (toString [9, 10, 13, 32]);

if (_lines isEqualTo [] || {(_lines select 0) != "UNITAF-EQUIPMENT-1"}) exitWith {
    hint "Copy the list on the website first (Equipment > Fill in equipment), then try again.";
};

private _quote = {
    params ["_text"];
    private _chars = [];
    {
        if (_x == 34 || {_x == 92}) then { _chars pushBack 92; };
        if (_x >= 32) then { _chars pushBack _x; };
    } forEach toArray _text;
    (toString [34]) + (toString _chars) + (toString [34])
};

// Each loaded mod's folder, and its Steam Workshop id where it was loaded from the Workshop.
private _workshop = createHashMap;
{
    private _info = _x;
    private _id = "";
    {
        if (_x isEqualType "") then {
            private _at = (toLower _x) find "107410\";
            if (_at >= 0) then { _id = ((_x select [_at + 7]) splitString "\/") param [0, ""]; };
        };
    } forEach _info;
    _workshop set [toLower (_info select 1), _id];
} forEach getLoadedModsInfo;

private _found = [];
private _missing = [];

{
    private _class = _x;
    private _kind = "";
    private _mass = 0;
    private _config = configFile >> "CfgMagazines" >> _class;

    if (isClass _config) then {
        _kind = "magazine";
        _mass = getNumber (_config >> "mass");
    } else {
        _config = configFile >> "CfgWeapons" >> _class;

        if (isClass _config) then {
            private _type = getNumber (_config >> "type");
            private _slot = getNumber (_config >> "ItemInfo" >> "type");
            _kind = switch (true) do {
                case (_slot == 616): { "NVGoggles" };
                case (_type == 1): { "PrimaryWeapon" };
                case (_type == 2): { "SecondaryWeapon" };
                case (_type == 4): { "Launcher" };
                case (_type == 4096): { "Binocular" };
                case (_slot == 101): { "MuzzleAttachment" };
                case (_slot == 201): { "OpticAttachment" };
                case (_slot == 301): { "SideAttachment" };
                case (_slot == 302): { "Bipod" };
                case (_slot == 605): { "HeadGear" };
                case (_slot == 701): { "Vest" };
                case (_slot == 801): { "Uniform" };
                default { "CommonItem" };
            };
            // Weapons and binoculars carry their mass in WeaponSlotsInfo; everything else in ItemInfo.
            _mass = if (_type in [1, 2, 4, 4096]) then {
                getNumber (_config >> "WeaponSlotsInfo" >> "mass")
            } else {
                getNumber (_config >> "ItemInfo" >> "mass")
            };
        } else {
            _config = configFile >> "CfgVehicles" >> _class;

            if (isClass _config) then {
                _kind = ["Vehicle", "bag"] select (getNumber (_config >> "isBackpack") == 1);
                _mass = getNumber (_config >> "mass");
            } else {
                _config = configFile >> "CfgGlasses" >> _class;

                if (isClass _config) then {
                    _kind = "glasses";
                    _mass = getNumber (_config >> "mass");
                };
            };
        };
    };

    if (_kind == "") then {
        _missing pushBack ([_class] call _quote);
    } else {
        private _dir = toLower (configSourceMod _config);
        private _id = _workshop getOrDefault [_dir, ""];
        if (_id == "" && {_dir != "" && {(_dir splitString "0123456789") isEqualTo []}}) then { _id = _dir; };
        _found pushBack ("[" + ([_class] call _quote) + "," + ([getText (_config >> "displayName")] call _quote) + "," + ([_kind] call _quote) + "," + (str _mass) + "," + ([_id] call _quote) + "]");
    };
} forEach (_lines select [1]);

private _game = format ["%1.%2", (productVersion select 2) / 100, productVersion select 3];
copyToClipboard ("{""format"":""unitaf-equipment"",""version"":1,""game"":" + ([_game] call _quote) + ",""items"":[" + (_found joinString ",") + "],""unknown"":[" + (_missing joinString ",") + "]}");

hint format ["Copied %1 items for the website, and %2 this game does not have. Paste the answer on Fill in equipment.", count _found, count _missing];
