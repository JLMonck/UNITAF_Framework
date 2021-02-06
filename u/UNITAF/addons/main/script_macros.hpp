#include "\x\cba\addons\main\script_macros.hpp"

#ifdef DISABLE_COMPILE_CACHE
    #undef PREP
    #define PREP(fncName) DFUNC(fncName) = compile preprocessFileLineNumbers QPATHTOF(functions\DOUBLES(fnc,fncName).sqf)
#else
    #undef PREP
    #define PREP(fncName) [QPATHTOF(functions\DOUBLES(fnc,fncName).sqf), QFUNC(fncName)] call CBA_fnc_compileFunction
#endif

#define MACRO_ADDWEAPON(WEAPON,COUNT) class _xx_##WEAPON { \
    weapon = #WEAPON; \
    count = COUNT; \
}

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
    name = #ITEM; \
    count = COUNT; \
}

#define MACRO_ADDMAGAZINE(MAGAZINE,COUNT) class _xx_##MAGAZINE { \
    magazine = #MAGAZINE; \
    count = COUNT; \
}

#define MACRO_ADDBACKPACK(BACKPACK,COUNT) class _xx_##BACKPACK { \
    backpack = #BACKPACK; \
    count = COUNT; \
}

#define SQUOTE(var1) 'var1'

#define QMAIN_ADDON QUOTE(MAIN_ADDON)

#define ACEFUNC(var1,var2) TRIPLES(DOUBLES(ace,var1),fnc,var2)

#define GETVAR_SYS(var1,var2) getVariable [ARR_2(QUOTE(var1),var2)]
#define GETMVAR(var1,var2) (missionNamespace GETVAR_SYS(var1,var2))

#define SETVAR_SYS(var1,var2) setVariable [ARR_2(QUOTE(var1),var2)]
#define SETMVAR(var1,var2) (missionNamespace SETVAR_SYS(var1,var2))
