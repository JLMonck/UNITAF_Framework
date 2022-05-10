//#include "\a3\ui_f\hpp\defineDIKCodes.inc"
//#include "\a3\ui_f\hpp\defineCommonGrids.inc"

class RscText;
class RscEdit;
class RscButton;
class RscCheckBox;
class RscActivePicture;
class RscStructuredText;
class RscButtonMenu;
class RscButtonMenuOK;
class RscButtonMenuCancel;
class RscControlsGroupNoScrollbars;

class ctrlToolbox;
class ctrlButtonPicture;
class ctrlControlsGroup;
class ctrlStaticPictureKeepAspect;

class ctrlButton;
class ctrlListNBox;
class ctrlProgress;
//class ctrlButtonPicture;
class ctrlToolboxPictureKeepAspect;

//class EGVAR(common,RscLabel);
class GVAR(RscLabel): RscText {
    idc = -1;
    x = 0;
    y = 0;
    w = POS_W(10);
    h = POS_H(1);
    colorBackground[] = {0, 0, 0, 0.5};
};
//class EGVAR(common,RscBackground);
class GVAR(RscBackground): RscText {
    idc = -1;
    style = ST_CENTER;
    x = POS_W(10);
    y = 0;
    w = POS_W(16);
    h = POS_H(2.5);
    colorText[] = {1, 1, 1, 0.5};
    //colorBackground[] = COLOR_BACKGROUND_SETTING;
	colorBackground[] = COLOR_BACKGROUND;
};
//class EGVAR(common,RscEdit);
class GVAR(RscEdit): RscEdit {
    idc = -1;
    x = POS_W(10.1);
    y = pixelH;
    w = POS_W(15.9);
    h = POS_H(1) - pixelH;
    colorText[] = {1, 1, 1, 1};
    colorBackground[] = {0, 0, 0, 0.2};
};

/*
class EGVAR(common,RscDisplay) {
    class controls {
        class Title;
        class Background;
        class Content;
        class ButtonOK;
        class ButtonCancel;
    };
};
*/

class GVAR(GUI_Control_Logistics_Inventory) {
	idd = -1;
    movingEnable = 1;
    //onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(display),_this select 0)]);
	onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(inventoryDisplay),_this select 0)]);

    class Controls {
        class Title: RscText {
            idc = IDC_TITLE;
            // Store the display's config, onLoad event for displays is not passed the config
            onLoad = QUOTE( \
                params [ARR_2('_control','_config')]; \
                private _display = ctrlParent _control; \
                _config = configHierarchy _config select 1; \
                _display setVariable [ARR_2(QQGVAR(config),_config)]; \
            );
            x = POS_X(6.5);
            w = POS_W(27);
            h = POS_H(1);
            //colorBackground[] = GUI_THEME_COLOR;
			colorBackground[] = COLOR_BACKGROUND;
            moving = 1;
        };
        class Background: RscText {
            idc = IDC_BACKGROUND;
            x = POS_X(6.5);
            w = POS_W(27);
            colorBackground[] = {0, 0, 0, 0.7};
        };
        class Content: RscControlsGroupNoScrollbars {
			idc = IDC_CONTENT;
            x = POS_X(7);
            w = POS_W(26);
            h = POS_H(13/3 + 14.3);
            class controls {
                class Category: ctrlToolboxPictureKeepAspect {
                    idc = IDC_CATEGORY;
                    x = 0;
                    y = 0;
                    w = POS_W(26);
                    h = POS_H(13/3);
                    rows = 2;
                    columns = 12;
                    strings[] = {
                        "\a3\Ui_F_Curator\Data\RscCommon\RscAttributeInventory\filter_0_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\PrimaryWeapon_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\SecondaryWeapon_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Handgun_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemOptic_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemAcc_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemMuzzle_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\ItemBipod_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoMagAll_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Headgear_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Uniform_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Vest_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Backpack_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Goggles_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\NVGs_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Binoculars_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Map_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Compass_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Radio_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\Watch_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\GPS_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoThrow_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoPut_ca.paa",
                        "\A3\Ui_f\data\GUI\Rsc\RscDisplayArsenal\CargoMisc_ca.paa"
                    };
                };
                class ListBackground: GVAR(RscBackground) {
                    x = 0;
                    y = POS_H(13/3);
                    w = POS_W(26);
                    h = POS_H(13);
                };
                class List: ctrlListNBox {
                    idc = IDC_LIST;
                    idcLeft = IDC_BTN_REMOVE;
                    idcRight = IDC_BTN_ADD;
                    x = 0;
                    y = POS_H(13/3);
                    w = POS_W(26);
                    h = POS_H(13);
                    drawSideArrows = 1;
                    disableOverflow = 1;
                    columns[] = {0.05, 0.15, 0.85};
                };
                class ButtonRemove: ctrlButton {
                    idc = IDC_BTN_REMOVE;
                    text = "−";
                    font = "RobotoCondensedBold";
                    x = -1;
                    y = -1;
                    w = POS_W(1);
                    h = POS_H(1);
                    sizeEx = POS_H(1.2);
                };
                class ButtonAdd: ButtonRemove {
                    idc = IDC_BTN_ADD;
                    text = "+";
                };
                class ButtonSearch: ctrlButtonPicture {
                    idc = IDC_BTN_SEARCH;
                    text = "\a3\Ui_f\data\GUI\RscCommon\RscButtonSearch\search_start_ca.paa";
                    x = 0;
                    y = POS_H(13/3 + 13.3);
                    w = POS_W(1);
                    h = POS_H(1);
                    colorBackground[] = {0, 0, 0, 0.5};
                    offsetPressedX = 0;
                    offsetPressedY = 0;
                };
                class SearchBar: GVAR(RscEdit) {
                    idc = IDC_SEARCH_BAR;
                    x = POS_W(1.2);
                    y = POS_H(13/3 + 13.3);
                    w = POS_W(8);
                    h = POS_H(1);
                    sizeEx = POS_H(0.9);
                };
                class Load: ctrlProgress {
                    idc = IDC_LOAD;
                    x = POS_W(13.7);
                    y = POS_H(13/3 + 13.3);
                    w = POS_W(9.9);
                    h = POS_H(1);
                    colorFrame[] = {1, 1, 1, 1};
                };
                class ButtonReset: ButtonSearch {
                    idc = IDC_BTN_RESET;
                    text = QPATHTOF(ui\reset_ca.paa);
                    tooltip = CSTRING(Reset_Tooltip);
                    x = POS_W(23.8);
                };
                class ButtonClear: ButtonSearch {
                    idc = IDC_BTN_CLEAR;
                    text = "\a3\3den\data\cfg3den\history\deleteitems_ca.paa";
                    tooltip = "$STR_disp_arcmap_clear";
                    x = POS_W(25);
                };
            };
        };
        class ButtonOK: RscButtonMenuOK {
            x = POS_X(28.5);
            w = POS_W(5);
            h = POS_H(1);
        };
        class ButtonCancel: RscButtonMenuCancel {
            x = POS_X(6.5);
            w = POS_W(5);
            h = POS_H(1);
        };
    };
};