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

// The server sends a player their ORBAT data, kit and arsenal, and ENDEX, with remoteExecCall
// (UNITAF tracker #202). Each function takes it only from the server, so no client can send
// another one kit or ENDEX; listed here so it still works where remote execution is whitelisted.
// Any machine (0), so a host's own player gets them too.
class CfgRemoteExec {
    class Functions {
        class FUNC(setPlayerData) {
            allowedTargets = 0;
        };
        class FUNC(setInventory) {
            allowedTargets = 0;
        };
        class FUNC(setArsenal) {
            allowedTargets = 0;
        };
        class FUNC(callENDEX) {
            allowedTargets = 0;
        };
    };
};
