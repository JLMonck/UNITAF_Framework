class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class ArgumentsBaseUnits;
        class ModuleDescription;

        class AttributesBase {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
            class Units;

            expression = "_this setVariable ['%s',_value];";
        };
    };
    class GVAR(moduleBase): Module_F {
        author = ECSTRING(main,author);
        category = QUOTE(PREFIX);
        function = QEFUNC(main,dummy);
        scope = 1;
        scopeCurator = 2;
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
    };
    class GVAR(moduleBase3den): Module_F {
        author = ECSTRING(main,author);
        category = QUOTE(PREFIX);
        function = QEFUNC(main,dummy);
        scope = 2;
        scopeCurator = 1;
        functionPriority = 2;
        isGlobal = 1;
        isTriggerActivated = 1;
        isDisposable = 0;
    };
    class GVAR(moduleMissionEndSuccess): GVAR(moduleBase) {
        displayName = "End Mission (Success)";
        category = QGVAR(COMPONENT);
        function = QFUNC(moduleMissionEndSuccess);
        icon = QPATHTOF(data\icon_success.paa);
    };
    class GVAR(moduleMissionEndFailure): GVAR(moduleBase) {
        displayName = "End Mission (Failure)";
        category = QGVAR(COMPONENT);
        function = QFUNC(moduleMissionEndFailure);
        icon = QPATHTOF(data\icon_failure.paa);
    };
};
