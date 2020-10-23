class GVAR(GUI_Control_Map): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Map;
	GRID_FRAME

	class Controls {
		/*
		class GVAR(Map): RscMapControl {
			idc 				= IDC_Tablet_Map_Control;
			type 				= CT_MAP_MAIN;
			style 				= ST_PICTURE;
			
			GRID_FRAME
		};
		*/
		class GVAR(MapFlat): RscMapControl {
			idc 				= IDC_Tablet_MapFlat_Control;
			type 				= CT_MAP_MAIN;
			style 				= ST_PICTURE;

			x 					= CALC_X(10.1);
			y 					= CALC_Y(3.8);
			w 					= CALC_W(24);
			h 					= CALC_H(17.6);

			maxSatelliteAlpha	= 0;
			alphaFadeStartScale	= 0;
			alphaFadeEndScale	= 0;

/*
			onMouseButtonDown = "";
			onMouseButtonUp = "";
			onMouseButtonClick = "";
			onMouseButtonDblClick = "";
			onMouseMoving = "";
			onMouseHolding = "";

			onSetFocus = "";
			onKillFocus = "";
			onMouseEnter = "";
			onMouseExit = "";
*/
			//onMouseMoving = "cTabCursorOnMap = _this select 3; cTabMapCursorPos = _this select 0 ctrlMapScreenToWorld [_this select 1, _this select 2];";
			//onMouseMoving = QUOTE(this call FUNC(tabletMap_onMouseMoving));
		};

		class GVAR(MapInfo_Background) {
			idc 				= -1;
			type				= CT_STATIC;
			style 				= ST_BACKGROUND;
			colorBackground[] 	= {0,0,0,1};
			colorText[] 		= {1,1,1,1};
			font 				= "TahomaB";
			sizeEx 				= GUI_TEXT_SIZE_MEDIUM;
  			text 				= "";

			x 					= 0;
			y 					= 0;
			w 					= CALC_W(4);
			h 					= GRID_FRAME_H;
		};

		class GVAR(MapInfo_Current): GVAR(GUI_Text_Base) {
			idc 				= -1;
			
			x 					= 0;
			y 					= 0;
			w 					= CALC_W(4);
			h 					= CALC_H(1);

			sizeEx				= GUI_TEXT_SIZE_SMALL;
			text 				= "Current Pos:";
			colorBackground[]	= {0,0,0,0};
			colorText[]			= {1,1,1,1};
		};
		class GVAR(MapInfo_time): GVAR(MapInfo_Current) {
			idc 	= IDC_Tablet_MapInfo_Time;
			y 					= (0 + CALC_Y(1));
		};
		class GVAR(MapInfo_dirDegree): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Degree;
			y 					= (0 + CALC_Y(2));
		};
		class GVAR(MapInfo_grid): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Grid;
			y 					= (0 + CALC_Y(3));
		};
		class GVAR(MapInfo_dirOctant): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Octant;
			y 					= (0 + CALC_Y(4));
		};
		class GVAR(MapInfo_elevation): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Elevation;
			y 					= (0 + CALC_Y(5));
		};

		class GVAR(MapInfo_Pointer): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_Elevation;
			y 					= (0 + CALC_Y(7));
			text 				= "Pointer Pos:";
		};
		class GVAR(MapInfo_hookGrid): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookGrid;
			y 					= (0 + CALC_Y(8));
		};
		class GVAR(MapInfo_hookElevation): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_hookElevation;
			y 					= (0 + CALC_Y(9));
		};
		class GVAR(MapInfo_hookDst): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookDst;
			y 					= (0 + CALC_Y(10));
		};
		class GVAR(MapInfo_hookDir): GVAR(MapInfo_Current) {
			idc 				= IDC_Tablet_MapInfo_HookDir;
			y 					= (0 + CALC_Y(11));
		};
	};
};