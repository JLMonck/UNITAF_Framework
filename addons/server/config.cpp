#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            QMAIN_ADDON
        };
        author = ECSTRING(main,author);
        url = ECSTRING(main,url);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

// Clients ask the server for crates and Zeus through this one function, to the server only
// (UNITAF tracker #199), so it still works where remote execution is whitelisted
class CfgRemoteExec {
    class Functions {
        class FUNC(clientRequest) {
            allowedTargets = 2;
        };
    };
};
