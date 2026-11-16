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

// Clients ask the server for crates, Zeus and ENDEX through this one function, to the server only
// (UNITAF tracker #199, #202), so it still works where remote execution is whitelisted. Their own
// ORBAT data, kit and arsenal they ask for by name, also to the server only; the server checks
// the unit is the sender's own (#202).
class CfgRemoteExec {
    class Functions {
        class FUNC(clientRequest) {
            allowedTargets = 2;
        };
        class FUNC(queryPlayerData) {
            allowedTargets = 2;
        };
        class FUNC(queryPlayerInventory) {
            allowedTargets = 2;
        };
        class FUNC(queryPlayerArsenal) {
            allowedTargets = 2;
        };
    };
};
