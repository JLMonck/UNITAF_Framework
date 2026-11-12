// Eden editor menu (D-473): UNITAF > Copy equipment for the website.
class ctrlMenuStrip;
class display3DEN {
    class Controls {
        class MenuStrip: ctrlMenuStrip {
            class Items {
                items[] += {QGVAR(menu)};
                class GVAR(menu) {
                    text = "UNITAF";
                    items[] = {QGVAR(equipmentForWebsite)};
                };
                class GVAR(equipmentForWebsite) {
                    text = "Copy equipment for the website";
                    action = QUOTE(call COMPILE_FILE(functions\fnc_equipmentForWebsite));
                };
            };
        };
    };
};
