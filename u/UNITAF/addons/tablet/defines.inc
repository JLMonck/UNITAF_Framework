#include "\a3\ui_f\hpp\definecommongrids.inc"
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

#define COLOR_BUTTON_REPORTER   { 0.157, 0, 0.843, 1 };


#define CALC_X(COL) (GUI_GRID_CENTER_X + COL * GUI_GRID_CENTER_W)		// max 40
#define CALC_Y(COL) (GUI_GRID_CENTER_Y + COL * GUI_GRID_CENTER_H)		// max 25
#define CALC_W(COL) (COL * GUI_GRID_CENTER_W)							// max 40
#define CALC_H(COL) (COL * GUI_GRID_CENTER_H)							// max 25

/**
 *	X 	9 - 2.9
 *	Y 	4 - .2
 *	W 	22 + 6
 *	H 	17 + .6
 */
#define GRID_FRAME_X 	CALC_X(6.1)
#define GRID_FRAME_Y 	CALC_Y(3.8)
#define GRID_FRAME_W 	CALC_W(28)
#define GRID_FRAME_H 	CALC_H(17.6)

#define GRID_FRAME \
	x 					= GRID_FRAME_X;	\
	y 					= GRID_FRAME_Y;	\
	w 					= GRID_FRAME_W;	\
	h 					= GRID_FRAME_H;

#define GRID_BUTTON_W   CALC_W(5.75)           // (28 - 1) / (columns + (columns + 1)
#define GRID_BUTTON_H   CALC_H(1.5)

#define GRID_OFFSET_COL1    (GRID_FRAME_X + CALC_X(1))
#define GRID_OFFSET_COL2    (GRID_FRAME_X + CALC_X(2) + CALC_W(5.75))
#define GRID_OFFSET_COL3    (GRID_FRAME_X + CALC_X(3) + (CALC_W(5.75) * 2))
#define GRID_OFFSET_COL4    (GRID_FRAME_X + CALC_X(4) + (CALC_W(5.75) * 3))

#define GUI_TEXT_SIZE_SMALL     (GUI_GRID_H * 0.8)
#define GUI_TEXT_SIZE_MEDIUM    (GUI_GRID_H * 1)
#define GUI_TEXT_SIZE_LARGE     (GUI_GRID_H * 1.2)


// IDC's
// UNITAF = 85 + 78 + 73 + 84 + 65 + 70 = 455 =  455000

// Base 4550xx
#define IDC_Tablet 						455000
#define IDC_Tablet_Button_P1 			455001
#define IDC_Tablet_Button_P2 			455002
#define IDC_Tablet_Button_Windows 		455003
#define IDC_Tablet_Button_Plus 			455004
#define IDC_Tablet_Button_Minus 		455005
#define IDC_Tablet_Button_Power 		455006

// Welcome 4551xx
#define IDC_Tablet_Welcome 				455100
#define IDC_Tablet_Welcome_Background 	455101

// Map 4552xx
#define IDC_Tablet_Map 					455200
#define IDC_Tablet_Map_Control 			455201
#define IDC_Tablet_MapFlat_Control      455202
#define IDC_Tablet_MapInfo_Control      455203
#define IDC_Tablet_MapInfo_Time         455204
#define IDC_Tablet_MapInfo_Degree       455205
#define IDC_Tablet_MapInfo_Grid         455206
#define IDC_Tablet_MapInfo_Octant       455207
#define IDC_Tablet_MapInfo_Elevation    455208
#define IDC_Tablet_MapInfo_HookGrid     455209
#define IDC_Tablet_MapInfo_hookElevation     455210
#define IDC_Tablet_MapInfo_HookDst      455211
#define IDC_Tablet_MapInfo_HookDir      455212

// Main 4553xx
#define IDC_Tablet_Main                         455300
#define IDC_Tablet_Main_Callsign                455301
#define IDC_Tablet_Main_Report                  455302
#define IDC_Tablet_Main_Role                    455303
#define IDC_Tablet_Main_Color                   455304
#define IDC_Tablet_Main_Team                    455305
#define IDC_Tablet_Main_Button_ORBAT            455306
#define IDC_Tablet_Main_Button_OPORD            455307
#define IDC_Tablet_Main_Button_LoadORBAT        455308
#define IDC_Tablet_Main_Button_Admin            455309
#define IDC_Tablet_Main_Button_Logistics        455310
#define IDC_Tablet_Main_Button_Reporter         455311

// Admin 4554xx
#define IDC_Tablet_Admin                        455400
#define IDC_Tablet_Admin_Button_releadORBAT     455401
#define IDC_Tablet_Admin_Button_ENDEX           455402
#define IDC_Tablet_Admin_Button_Zeus            455403
#define IDC_Tablet_Admin_Button_Arsenal         455404

// OPORD 4555xx
#define IDC_Tablet_OPORD                        455500
#define IDC_Tablet_OPORD_HTML                   455501

// ORBAT 4556xx
#define IDC_Tablet_ORBAT                        455600
#define IDC_Tablet_ORBAT_Table                  455601
#define IDC_Tablet_ORBAT_Table_First            455601000
#define IDC_Tablet_ORBAT_Table_Last             455601999