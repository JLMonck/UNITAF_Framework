class GVAR(GUI_Control_OPORD): GVAR(GUI_Control_Base) {
	idc 				= IDC_CONTROL_OPORD;
	x 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
	y 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 7);
	w 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 23);
	h 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 14);

	class Controls {
		class GVAR(GUI_OPORD_HTML) {
			type 					= CT_HTML;
			idc 					= IDC_OPORD_HTML;
			x 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.1);
			y 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.1);
			w 						= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 22.7);
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
			sizeEx 					= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			access 					= 0;
			
			prevPage 				= "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_left_ca.paa";
			nextPage 				= "\A3\ui_f\data\gui\rsccommon\rschtml\arrow_right_ca.paa";

			// confidental line
			class H1 {
				font 		= "EtelkaMonospacePro";
				fontBold 	= "EtelkaMonospaceProBold";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
				align 		= "center";
			};
			// OPORD
			class H2 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 2);
				align 		= "center";
			};
			// OP Name
			class H3 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1.5);
				align 		= "center";
			};
			// Subtitles
			class H4 {
				font 		= "PuristaSemiBold";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				align 		= "left";
			};
			// Unknown
			class H5 {
				font 		= "LucidaConsoleB";
				fontBold 	= "LucidaConsoleB";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				align 		= "left";
			};
			// Unknown
			class H6 {
				font 		= "LucidaConsoleB";
				fontBold 	= "LucidaConsoleB";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
				align 		= "left";
			};
			// Paragraph
			class P {
				font 		= "PuristaLight";
				fontBold 	= "PuristaSemiBold";
				sizeEx 		= (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8);
				align 		= "left";
			};
		};
	};
};