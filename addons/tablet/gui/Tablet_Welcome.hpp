class GVAR(GUI_Control_Welcome): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_Welcome;
	GRID_FRAME

	class Controls {
		class GVAR(Tablet_Background) {
			type				= CT_STATIC;
			idc 				= IDC_Tablet_Welcome_Background;

			x 					= 0;
			y 					= 0;
			w 					= GRID_FRAME_W;
			h 					= GRID_FRAME_H;

			style 				= ST_PICTURE + ST_KEEP_ASPECT_RATIO;
			text 				= "\u\UNITAF\addons\assets\images\signage\utfn-logo.jpg";
			colorBackground[] 	= {0,0,0,1};
			colorText[] 		= {1,1,1,1};
			font 				= "PuristaLight";
			sizeEx 				= GUI_TEXT_SIZE_MEDIUM;
		};
	};
};