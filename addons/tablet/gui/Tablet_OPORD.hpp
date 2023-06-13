class GVAR(GUI_Control_OPORD): GVAR(GUI_Control_Base) {
	idc 				= IDC_Tablet_OPORD;
	GRID_FRAME

	class Controls {
		class GVAR(GUI_OPORD_HTML) {
			type 					= CT_HTML;
			idc 					= IDC_Tablet_OPORD_HTML;
			x 						= GRID_FRAME_X;
			y 						= GRID_FRAME_Y;
			w 						= GRID_FRAME_W;
			h 						= 10;
			style 					= 0;
			filename 				= "";
			text 					= "";
			colorBackground[] 		= COLOR_BACKGROUND;
			colorText[]				= COLOR_TEXT;
			colorBold[] 			= COLOR_TEXT;
			colorLink[] 			= COLOR_SUBTEXT;
			colorLinkActive[] 		= COLOR_SUBTEXT;
			colorPicture[] 			= COLOR_TEXT;
			colorPictureLink[] 		= COLOR_TEXT;
			colorPictureSelected[] 	= COLOR_TEXT;
			colorPictureBorder[] 	= {0,0,0,0};
			tooltipColorText[] 		= COLOR_TEXT;
			tooltipColorBox[] 		= COLOR_TEXT;
			tooltipColorShade[] 	= {0,0,0,0};
			font 					= "PuristaMedium";
			sizeEx 					= GUI_TEXT_SIZE_SMALL;
			access 					= 0;
			
			prevPage 				= "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
			nextPage 				= "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";

			// confidental line
			class H1 {
				font 		= "EtelkaMonospacePro";
				fontBold 	= "EtelkaMonospaceProBold";
				sizeEx 		= GUI_TEXT_SIZE_SMALL;
				align 		= "center";
			};
			// OPORD
			class H2 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (GUI_GRID_H * 2);
				align 		= "center";
			};
			// OP Name
			class H3 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (GUI_GRID_H * 1.5);
				align 		= "center";
			};
			// Subtitles
			class H4 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= GUI_TEXT_SIZE_MEDIUM;
				align 		= "left";
			};
			// Unknown
			class H5 {
				font 		= "LucidaConsoleB";
				fontBold 	= "LucidaConsoleB";
				sizeEx 		= GUI_TEXT_SIZE_MEDIUM;
				align 		= "left";
			};
			// Unknown
			class H6 {
				font 		= "LucidaConsoleB";
				fontBold 	= "LucidaConsoleB";
				sizeEx 		= GUI_TEXT_SIZE_MEDIUM;
				align 		= "left";
			};
			// Paragraph
			class P {
				font 		= "PuristaLight";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= GUI_TEXT_SIZE_SMALL;
				align 		= "left";
			};
		};
	};
};