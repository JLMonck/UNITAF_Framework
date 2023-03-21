#include "script_component.hpp"
/*
 * Author: Grezvany13
 * Ensure working database connection
 *
 * Arguments:
 * None
 *
 * Return Value:
 * None
 *
 * Example:
 * call unitaf_server_fnc_initDatabase;
 *
 * Public: No
 */

if ((getMissionConfigValue ['UNITAF_noDBTest', 0]) isEqualTo 1) exitWith { true };

//Get Server Database
private _resultDB = "extDB3" callExtension "9:ADD_DATABASE:UTFN";
if (!(parseSimpleArray (_resultDB) select 0 isEqualTo 1)) exitWith { diag_log "extDB3: Error with Database Connection"; diag_log format ["%1", _resultDB]; false };

//Get Protocol
private _resultPROT = "extDB3" callExtension "9:ADD_DATABASE_PROTOCOL:UTFN:SQL:FETCHDATA:TEXT";
if (!(parseSimpleArray (_resultPROT) select 0 isEqualTo 1)) exitWith { diag_log "extDB3: Error with Protocol Connection"; diag_log format ["%1", _resultPROT]; false };

// Set Protocol
private _resultSPROT = "extDB3" callExtension "9:ADD_DATABASE_PROTOCOL:UTFN:SQL:SETDATA:TEXT";
if (!(parseSimpleArray (_resultSPROT) select 0 isEqualTo 1)) exitWith { diag_log "extDB3: Error with Protocol Connection"; diag_log format ["%1", _resultSPROT]; false };

true