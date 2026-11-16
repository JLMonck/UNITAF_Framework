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

// The server stops each headless client's AI at ENDEX with remoteExecCall (UNITAF tracker #202);
// the function takes it only from the server. Listed so it works where remote execution is whitelisted.
class CfgRemoteExec {
    class Functions {
        class FUNC(callENDEX) {
            allowedTargets = 0;
        };
    };
};
