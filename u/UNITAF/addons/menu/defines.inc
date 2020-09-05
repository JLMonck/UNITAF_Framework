// #include "\a3\ui_f\hpp\definecommongrids.inc"
// #include "\a3\ui_f\hpp\defineresincl.inc"

// Control Types
#define CT_STATIC				  0
#define CT_BUTTON				  1
#define CT_EDIT					  2
#define CT_SLIDER				  3
#define CT_COMBO				  4
#define CT_LISTBOX				  5
#define CT_TOOLBOX				  6
#define CT_CHECKBOXES			  7
#define CT_PROGRESS				  8
#define CT_HTML					  9
#define CT_STATIC_SKEW			 10
#define CT_ACTIVETEXT			 11
#define CT_TREE					 12
#define CT_STRUCTURED_TEXT		 13
#define CT_CONTEXT_MENU			 14
#define CT_CONTROLS_GROUP		 15
#define CT_SHORTCUTBUTTON		 16
#define CT_HITZONES				 17
#define CT_VEHICLETOGGLES		 18
#define CT_CONTROLS_TABLE		 19
#define CT_XKEYDESC				 40
#define CT_XBUTTON				 41
#define CT_XLISTBOX				 42
#define CT_XSLIDER				 43
#define CT_XCOMBO				 44
#define CT_ANIMATED_TEXTURE		 45
#define CT_MENU					 46
#define CT_MENU_STRIP			 47
#define CT_CHECKBOX				 77
#define CT_OBJECT				 80
#define CT_OBJECT_ZOOM			 81
#define CT_OBJECT_CONTAINER		 82
#define CT_OBJECT_CONT_ANIM		 83
#define CT_LINEBREAK			 98
#define CT_USER					 99
#define CT_MAP					100
#define CT_MAP_MAIN				101
#define CT_LISTNBOX				102
#define CT_ITEMSLOT				103
#define CT_LISTNBOX_CHECKABLE	104
#define CT_VEHICLE_DIRECTION	105

// Control Styles
#define ST_LEFT					0x00
#define ST_RIGHT				0x01
#define ST_CENTER				0x02
#define ST_DOWN					0x04
#define ST_UP					0x08
#define ST_VCENTER				0x0C
#define ST_SINGLE				0x00
#define ST_MULTI				0x10
#define ST_TITLE_BAR			0x20
#define ST_PICTURE				0x30
#define ST_FRAME				0x40
#define ST_BACKGROUND			0x50
#define ST_GROUP_BOX			0x60
#define ST_GROUP_BOX2			0x70
#define ST_HUD_BACKGROUND		0x80
#define ST_TILE_PICTURE			0x90
#define ST_WITH_RECT			0xA0
#define ST_LINE					0xB0
#define ST_UPPERCASE			0xC0
#define ST_LOWERCASE			0xD0
#define ST_ADDITIONAL_INFO		0x0F00
#define ST_SHADOW				0x0100
#define ST_NO_RECT				0x0200
#define ST_KEEP_ASPECT_RATIO	0x0800
#define ST_TITLE				ST_TITLE_BAR + ST_CENTER
#define SL_VERT					0
#define SL_HORZ					0x400
#define SL_TEXTURES				0x10
#define ST_VERTICAL				0x01
#define ST_HORIZONTAL			0
#define LB_TEXTURES				0x10
#define LB_MULTI				0x20
#define TR_SHOWROOT				1
#define TR_AUTOCOLLAPSE			2

// IDC
#define IDC_OK                  1       // for (contextually) OK or CONTINUE
#define IDC_CANCEL              2       // for (contextually) CANCEL, ESCAPE or ABORT

// Colors
#define COLOR_BACKGROUND        { 0.1451, 0.1451, 0.1608, 0.8 }
#define COLOR_TEXT              { 1, 1, 1, 1 }
#define COLOR_SUBTEXT           { 0.5216, 0.4392, 0.2275, 1 }
#define COLOR_TEXT_DISABLED     { 0.302, 0.302, 0.302, 1 }

#define COLOR_BUTTON            { 0.0745, 0.0824, 0.1059, 1 }
#define COLOR_BUTTON_DISABLED   { 0.302, 0.302, 0.302, 1 }

#define COLOR_BUTTON_CLOSE      { 0.702, 0.102, 0.102, 1 }
#define COLOR_BUTTON_LOAD       { 0.5216, 0.4392, 0.2275, 1 }
#define COLOR_BUTTON_ADMIN      { 0, 0.2, 0.2, 1 }

// IDC's
// UNITAF = 85 + 78 + 73 + 84 + 65 + 70 = 455 =  455000

// overal display
#define IDC_Menu                455000
#define IDC_CLOSE               455001
#define IDC_BACK                455002

// MAIN
#define IDC_CONTROL_MAIN        455100
#define IDC_BUTTON_LoadORBAT    455101
#define IDC_BUTTON_Admin        455102

#define IDC_Callsign            455103
#define IDC_Report              455104
#define IDC_Role                455105
#define IDC_Color               455106
#define IDC_Team                455107

#define IDC_BUTTON_ORBAT        455108
#define IDC_BUTTON_OPORD        455109

// OPORD
#define IDC_CONTROL_OPORD       455200
#define IDC_OPORD_HTML          455201

// ORBAT
#define IDC_CONTROL_ORBAT       455300
#define IDC_ORBAT_TABLE         455301
#define IDC_ORBAT_TABLE_FIRST   4553000
#define IDC_ORBAT_TABLE_LAST    4553999

// ADMIN
#define IDC_CONTROL_ADMIN               455400
#define IDC_ADMIN_BUTTON_releadORBAT    455401
#define IDC_ADMIN_BUTTON_ENDEX          455402
#define GUI_ADMIN_Button_ZEUS           455403
