#include "script_component.hpp"
/*
 * Author: JLMonck
 * The boxes a crate may spawn in (2.6.0, UNITAF tracker #119): the website's allowed boxes for
 * this deployment (unitaf_server_fnc_queryCrateBoxes), keeping only those whose class is in this
 * game, so a box whose mod the server does not load is never offered. UNICRATES come in the
 * deployment's camo only; the website has already picked it.
 *
 * - Automatic: the website's tick (boxes a soldier can carry). The 1500 cap is gone for the
 *   website's boxes; it stays only for the mod's own boxes below, which have no tick.
 * - Space: the website's figure, else the box's own maximumLoad. A box with no space at all, or
 *   ticked Empty box only, is offered only as an empty box.
 * - Medical: the website's kind.
 *
 * When the website sent nothing (no database, or nothing allowed), or none of its boxes is in
 * this game, or none of them packs a crate by itself, the mod's own boxes are used as before
 * 2.6.0, and that is logged once on each machine.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * [boxes, from the website] <ARRAY>
 *   boxes: [[space, class name, medical, automatic, empty box only, name], ...], smallest first
 *
 * Example:
 * (call unitaf_logistics_fnc_getBoxes) params ["_boxes", "_fromSite"];
 *
 * Public: No
 */

private _site = missionNamespace getVariable [QGVAR(siteBoxes), []];
private _boxes = [];

{
	_x params [["_class", ""], ["_name", ""], ["_space", 0], ["_kind", ""], ["_automatic", 0], ["_emptyOnly", 0]];
	if (_space isEqualType "") then { _space = parseNumber _space; };
	if (_automatic isEqualType "") then { _automatic = parseNumber _automatic; };
	if (_emptyOnly isEqualType "") then { _emptyOnly = parseNumber _emptyOnly; };

	private _config = configFile >> "CfgVehicles" >> _class;
	if (_class isNotEqualTo "" && {isClass _config}) then {
		// The website's figure, else the box's own (Boxloader's pallet net and containers set none)
		if (_space <= 0) then { _space = getNumber (_config >> "maximumLoad"); };
		private _onlyEmpty = (_emptyOnly isEqualTo 1) || {_space <= 0};
		private _label = [_name, getText (_config >> "displayName")] select (_name isEqualTo "");
		_boxes pushBack [_space, _class, _kind isEqualTo "medical", (_automatic isEqualTo 1) && {!_onlyEmpty}, _onlyEmpty, _label];
	};
} forEach _site;

if (_boxes findIf { _x select 3 } != -1) exitWith {
	_boxes sort true;
	[_boxes, true]
};

// The fallback: the mod's own boxes, read once and kept
if (isNil QGVAR(ownBoxes)) then {
	private _base = QGVAR(Container_Base);
	private _own = [];
	{
		private _class = configName _x;
		private _load = getNumber (_x >> "maximumLoad");
		if (_load > 0 && {getNumber (_x >> "scope") >= 2} && {_class isKindOf [_base, configFile >> "CfgVehicles"]}) then {
			// Our medical variants are the classes named *_Medical; automatic up to AUTO_MAX_LOAD
			_own pushBack [_load, _class, (_class select [count _class - 8]) == "_Medical", _load <= AUTO_MAX_LOAD, false, getText (_x >> "displayName")];
		};
	} forEach ("true" configClasses (configFile >> "CfgVehicles"));
	_own sort true;
	GVAR(ownBoxes) = _own;
};

if !(missionNamespace getVariable [QGVAR(fallbackLogged), false]) then {
	GVAR(fallbackLogged) = true;
	if (_site isEqualTo []) then {
		diag_log "UNITAF logistics: no crate boxes from the website (no database, or none allowed); using the mod's own boxes";
	} else {
		diag_log format ["UNITAF logistics: none of the website's %1 allowed crate boxes is in this game with an automatic tick (%2 found); using the mod's own boxes", count _site, count _boxes];
	};
};

[GVAR(ownBoxes), false]
