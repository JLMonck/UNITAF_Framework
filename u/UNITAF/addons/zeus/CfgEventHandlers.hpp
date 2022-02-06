class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
       clientInit = QUOTE(call COMPILE_FILE(XEH_postInitClient));
    };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayCurator {
        GVAR(CuratorInterfaceOpened) = QUOTE([ARR_2(_this select 0,'Open')] call FUNC(onCuratorInterface));
    };
};
class Extended_DisplayUnload_EventHandlers {
    class RscDisplayCurator {
        GVAR(CuratorInterfaceOpened) = QUOTE([ARR_2(_this select 0,'Close')] call FUNC(onCuratorInterface));
    };
};