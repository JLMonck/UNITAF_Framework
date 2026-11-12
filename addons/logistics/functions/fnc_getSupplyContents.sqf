#include "script_component.hpp"
/*
 * Author: JLMonck
 * A supply preset the mod carries itself (CfgSupplies), for when the website has no crate for it
 * or the mission runs without the database. The website's crates are read by
 * unitaf_server_fnc_queryCrateContents instead.
 *
 * Arguments:
 * 0: CfgSupplies class name <STRING>
 *
 * Return Value:
 * Contents, [[class name, count], ...] <ARRAY>
 *
 * Example:
 * ["unitaf_logistics_MedicalSupplies"] call unitaf_logistics_fnc_getSupplyContents;
 *
 * Public: No
 */

params [["_preset", "", [""]]];

getArray (configFile >> "CfgSupplies" >> _preset >> "items")
