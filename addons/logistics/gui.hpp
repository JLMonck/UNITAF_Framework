class unitaf_logisticsMenu_RscButton
{
	access = 0;
	idc = -1;
	default = 0;

	type = 1; // Type
	style = 0x02 + 0xC0;

	soundClick[] =	{"\A3\ui_f\data\sound\RscButton\soundClick",0.090000004,1};
	soundEnter[] =	{"\A3\ui_f\data\sound\RscButton\soundEnter",0.090000004,1};
	soundPush[] =	{"\A3\ui_f\data\sound\RscButton\soundPush",0.090000004,1};
	soundEscape[] ={"\A3\ui_f\data\sound\RscButton\soundEscape",0.090000004,1};


	colorBackground[] = {0,0,0,1}; // Fill color
	colorBackgroundDisabled[] = {0,0,0,0}; // Disabled fill color
	colorBackgroundActive[] = ACTIVECOLOR; // Mouse hover fill color
	colorFocused[] = ACTIVECOLOR; // Selected fill color (oscillates between this and colorBackground)

	font = "RobotoCondensedLight";
	sizeEx = 5 * GRID_H;
	shadow = 1;
	text = ""; // Displayed text
	colorText[] = {1,1,1,1}; // Text color
	colorDisabled[] = {1,1,1,0.25}; // Disabled text color

	borderSize = 0; // Left color width (border is a stripe of the control height on the left side)
	colorBorder[] = {0,0,0,0}; // Left border color

	colorShadow[] = {0,0,0,0}; // Background frame color
	offsetX = 0; // Horizontal background frame offset
	offsetY = 0; // Vertical background frame offset
	offsetPressedX = pixelW; // Horizontal background offset when pressed
	offsetPressedY = pixelH; // Horizontal background offset when pressed

	period = 0; // Oscillation time between colorBackground and colorFocused when selected
	periodFocus = 2; // Unknown?
	periodOver = 0.5; // Unknown?

	// Xbox hints (behavior unknown)
	class KeyHints
	{
		class A
		{
			key = KEY_XBOX_A;
			hint = "KEY_XBOX_A";
		};
	};
};

class unitaf_logisticsMenu_RscCombo
{
	access=0;
	idc=-1;
     type=4;
     style="0x00 + 0x10 + 0x200";
     colorBackground[]={0.050000001,0.050000001,0.050000001,1};
	default=0;
	show=1;
	fade=0;
	blinkingPeriod=0;
	deletable=0;
	x=0;
	y=0;
	w=0;
	h=0;
	tooltip="";
	sizeEx="4.32 * (1 / (getResolution select 3)) * pixelGrid * 0.5";
	font="RobotoCondensedLight";
	shadow=1;
	tooltipMaxWidth=0.5;
	tooltipColorShade[]={0,0,0,1};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={0,0,0,0};
	class ScrollBar
	{
		width=0;
		height=0;
		scrollSpeed=0.059999999;
		arrowEmpty="\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull="\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border="\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb="\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[]={1,1,1,1};
	};
     colorSelectBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",
		1
	};
	colorText[]={1,1,1,1};
	colorDisabled[]={1,1,1,0.25};
	colorSelect[]={0,0,0,1};
	colorTextRight[]={1,1,1,1};
	colorSelectRight[]={1,1,1,0.25};
	colorSelect2Right[]={1,1,1,1};
	colorPicture[]={1,1,1,1};
	colorPictureSelected[]={1,1,1,1};
	colorPictureDisabled[]={1,1,1,0.25};
	colorPictureRight[]={1,1,1,1};
	colorPictureRightSelected[]={1,1,1,1};
	colorPictureRightDisabled[]={1,1,1,0.25};
	arrowEmpty="\a3\3DEN\Data\Controls\ctrlCombo\arrowEmpty_ca.paa";
	arrowFull="\a3\3DEN\Data\Controls\ctrlCombo\arrowFull_ca.paa";
	wholeHeight="12 * 	5 * (pixelH * pixelGrid * 	0.50)";
	maxHistoryDelay=1;
	soundExpand[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundExpand",
		0.1,
		1
	};
	soundCollapse[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundCollapse",
		0.1,
		1
	};
	soundSelect[]=
	{
		"\A3\ui_f\data\sound\RscCombo\soundSelect",
		0.1,
		1
	};
	class ComboScrollBar
	{
		width=0;
		height=0;
		scrollSpeed=0.0099999998;
		arrowEmpty="\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull="\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border="\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb="\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[]={1,1,1,1};
	};
};


class unitaf_logisticsMenu_RscListNBox
{
	type = 102; // Type
	style = 0x00 + 0x10; // Style

    access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
    idc = -1; // Control identification (without it, the control won't be displayed)
    default = 0; // Control selected by default (only one within a display can be used)
    show = 1; // 1 (true) to show the control. Will be also shown when the attribute is missing.
    fade = 0; // Fade in range from 0 (fully visible) to 1 (hidden)
    blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.
    deletable = 0; // 1 if control can be deleted using ctrlDelete scripting command

    x = 0; // Horizontal coordinates
    y = 0; // Vertical coordinates
    w = 0; // Width
    h = 0; // Height

    tooltip = ""; // Tooltip text
    tooltipMaxWidth = 0.5; // Max width of a tooltip. When text is longer, it's broken into multiple lines
    tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
    tooltipColorText[] = {1,1,1,1}; // Tooltip text color
    tooltipColorBox[] = {0,0,0,0}; // Tooltip frame color

	font = "RobotoCondensedLight";
	SizeEx = 5 * GRID_H;
    shadow = 1;

	autoScrollSpeed = -1;
    autoScrollDelay = 5;
    autoScrollRewind = 0;
    arrowEmpty = "#(argb,8,8,3)color(1,1,1,1)";
    arrowFull = "#(argb,8,8,3)color(1,1,1,1)";

	color[] = {1,1,1,1};
	colorText[] = {1,1,1,1}; // Text and frame color
	colorDisabled[] = {1,1,1,0.25}; // Disabled text color
	colorSelect[] = {0,0,0,1}; // Text selection color
	colorSelect2[] = {0,0,0,1}; // Text selection color (oscillates between this and colorSelect)
	colorShadow[] = {0,0,0,0.5}; // Text shadow color (used only when shadow is 1)

	colorPicture[] = {1,1,1,1}; // Picture color
	colorPictureSelected[] = {1,1,1,1}; // Selected picture color
	colorPictureDisabled[] = {1,1,1,0.25}; // Disabled picture color

	colorSelectBackground[] = {ACTIVECOLOR}; // Selected item fill color
	colorSelectBackground2[] = {ACTIVECOLOR}; // Selected item fill color (oscillates between this and colorSelectBackground)

	columns[] = {0}; // Horizontal coordinates of columns (relative to list width, in range from 0 to 1)

	drawSideArrows = 0; // 1 to draw buttons linked by idcLeft and idcRight on both sides of selected line. They are resized to line height
	idcLeft = -1; // Left button IDC
	idcRight = -1; // Right button IDC

	period = 1; // Oscillation time between colorSelect/colorSelectBackground2 and colorSelect2/colorSelectBackground when selected
	disableOverflow = 0; // 0 to keep overflow as it was before, 1 to crop too long text

	rowHeight = 5.5 * GRID_H; // Row height
	maxHistoryDelay = 1; // Time since last keyboard type search to reset it

	soundSelect[] = {"\A3\ui_f\data\sound\RscListbox\soundSelect",0.09,1}; // Sound played when an item is selected

	// Scrollbar configuration (applied only when LB_TEXTURES style is used)
    class ScrollBar
    {
        width = 0; // Width
        height = 0; // Height
        scrollSpeed = 0.06; // Scroll speed

        arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa"; // Arrow
        arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa"; // Arrow when clicked on
        border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa"; // Slider background (stretched vertically)
        thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa"; // Dragging element (stretched vertically)

        color[] = {1,1,1,1}; // Scrollbar color
    };
	class ListScrollBar: ScrollBar{};
};

class unitaf_logisticsMenu_RscProgress
{
	access=0;
	idc=-1;
	style=0;
	type=8;
	default=0;
	show=1;
	fade=0;
	blinkingPeriod=0;
	deletable=0;
	x=0;
	y=0;
	w=0;
	h=0;
	texture="#(argb,8,8,3)color(1,1,1,1)";
	colorBar[]={1,1,1,1};
	colorFrame[]={0,0,0,1};
	onCanDestroy="";
	onDestroy="";
	tooltip="";
	tooltipMaxWidth=0.5;
	tooltipColorShade[]={0,0,0,1};
	tooltipColorText[]={1,1,1,1};
	tooltipColorBox[]={0,0,0,0};
	class ScrollBar
	{
		width=0;
		height=0;
		scrollSpeed=0.059999999;
		arrowEmpty="\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
		arrowFull="\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
		border="\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
		thumb="\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
		color[]={1,1,1,1};
	};
};


class unitaf_logisticsMenu_RscText
{
	type = 0;
	idc = -1;
	colorBackground[] = {0,0,0,0};
	colorText[] = {1,1,1,1};
	text = "";
	fixedWidth = 0;
	x = 0;
	y = 0;
	h = 0.037;
	w = 0.3;
	style = 0;
	shadow = 0;
	colorShadow[] = {0,0,0,0.5};
	font = "RobotoCondensed";
	SizeEx = 5 * GRID_H;
	linespacing = 1;
};


class unitaf_logisticsMenu_main
{
	idd = -1;
	movingEnable = false;
	onLoad = QUOTE(_this call FUNC(onLoad));
	onUnload = QUOTE(_this call FUNC(onUnload));
	class ControlsBackground
	{
		class title: unitaf_logisticsMenu_RscText
		{
			idc = -1;
			x = safezoneW / 2 - 75 * GRID_W + safezoneX;
			y = safezoneH / 2 - 56 * GRID_H + safezoneY;
			w = 150 * GRID_W;
			h = 5.5 * GRID_H;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])", 1};
		};
		class background: title
		{
			y = safezoneH / 2 - 50 * GRID_H + safezoneY;
			h = 100 * GRID_H;
			colorBackground[]={0,0,0,0.8};
		};
	};
	class Controls {
		class ItemsBigBox: unitaf_logisticsMenu_RscListNBox
		{
			idc = IDC_BIGBOX;
			x = safezoneW / 2 - 72.5 * GRID_W + safezoneX;
			y = safezoneH / 2 - 47.5 * GRID_H + safezoneY;
			w = 70 * GRID_W;
			h = 87.5 * GRID_H;
			columns[] = {0,0.1,0.25};
			colorBackground[]={0,0,0,0.5};
		};
		class ItemsSmallBox: ItemsBigBox
		{
			idc = IDC_SMALLBOX;
			x = safezoneW / 2 + 2.5 * GRID_W + safezoneX;
			y = safezoneH / 2 - 40 * GRID_H + safezoneY;
			h = 80 * GRID_H;
		};
		class Load: unitaf_logisticsMenu_RscProgress
		{
			idc = IDC_LOAD;
			x = safezoneW / 2 + 2.5 * GRID_W + safezoneX;
			y = safezoneH / 2 - 47.5 * GRID_H + safezoneY;
			w = 70 * GRID_W;
			h = 5.5 * GRID_H;
			colorBackground[]={0,0,0,0.5};
		};
		class Amount: unitaf_logisticsMenu_RscCombo
		{
			idc = IDC_AMOUNT;
			x = safezoneW / 2 - 7.5 * GRID_W + safezoneX;
			y = safezoneH / 2 + 42.5 * GRID_H + safezoneY;
			w = 15 * GRID_W;
			h = 5.5 * GRID_H;
		};
		class ButtonLeft: unitaf_logisticsMenu_RscButton
		{
			idc = IDC_BUTTON_LEFT;
			onButtonClick = QUOTE(_this call FUNC(onButtonClick_left));
			text = "<";
			x = safezoneW / 2 - 15 * GRID_W + safezoneX;
			y = safezoneH / 2 + 42.5 * GRID_H + safezoneY;
			w = 5.5 * GRID_W;
			h = 5.5 * GRID_H;
			colorBackground[]={0,0,0,0.5};
		};
		class ButtonRight: ButtonLeft
		{
			idc = IDC_BUTTON_RIGHT;
			onButtonClick = QUOTE(_this call FUNC(onButtonClick_right));
			text = ">";
			x = safezoneW / 2 + 10 * GRID_W + safezoneX;
		};
		class ButtonSpawn: ButtonLeft
		{
			w = 16.5 * GRID_W;
			x = safezoneW / 2 + 56.5 * GRID_W + safezoneX;
			text = "SPAWN";
			onButtonClick = QUOTE(_this call FUNC(onButtonClick_spawn));
		};
		
		class button_crates : unitaf_logisticsMenu_RscButton 
		{
			type = 1;
			idc = 40;
			x = safeZoneX + safeZoneW * 0.31;
			y = safeZoneY + safeZoneH * 0.265;
			w = safeZoneW * 0.0625;
			h = safeZoneH * 0.024;
			style = 0+2;
			text = "Crates";
			borderSize = 0;
			colorBackground[] = {0,0,0,1};
			colorBackgroundActive[] = {0.102,0.102,0.102,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			onButtonClick = QUOTE(_this call FUNC(loadUI_crates));
			
		};

		class button_vehicles : unitaf_logisticsMenu_RscButton 
		{
			type = 1;
			idc = 41;
			x = safeZoneX + safeZoneW * 0.38;
			y = safeZoneY + safeZoneH * 0.265;
			w = safeZoneW * 0.0625;
			h = safeZoneH * 0.024;
			style = 0+2;
			text = "Vehicles";
			borderSize = 0;
			colorBackground[] = {0,0,0,1};
			colorBackgroundActive[] = {0.102,0.102,0.102,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			onButtonClick = QUOTE(_this call FUNC(loadUI_vehicles));
			
		};

		class button_items : unitaf_logisticsMenu_RscButton 
		{
			type = 1;
			idc = 42;
			x = safeZoneX + safeZoneW * 0.46;
			y = safeZoneY + safeZoneH * 0.265;
			w = safeZoneW * 0.0625;
			h = safeZoneH * 0.024;
			style = 0+2;
			text = "items";
			borderSize = 0;
			colorBackground[] = {0,0,0,1};
			colorBackgroundActive[] = {0.102,0.102,0.102,1};
			colorBackgroundDisabled[] = {0.2,0.2,0.2,1};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0.2,0.2,0.2,1};
			colorFocused[] = {0.2,0.2,0.2,1};
			colorShadow[] = {0,0,0,0};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			onButtonClick = QUOTE(_this call FUNC(loadUI_items));
			
		};
		class spawned_crate : Amount 
		{
			idc = IDC_spawned_crate;
			x = safeZoneX + safeZoneW * 0.33;
			
			y = safeZoneY + safeZoneH * 0.675;

			w = safeZoneW * 0.10;
			h = safeZoneH * 0.02685186;
			tooltip = "Type of crate to spawn";
			class ComboScrollBar
			{
				color[] = {1,1,1,1};
				thumb = "\a3\3DEN\Data\Controls\ctrlDefault\thumb_ca.paa";
				arrowFull = "\a3\3DEN\Data\Controls\ctrlDefault\arrowFull_ca.paa";
				arrowEmpty = "\a3\3DEN\Data\Controls\ctrlDefault\arrowEmpty_ca.paa";
				border = "\a3\3DEN\Data\Controls\ctrlDefault\border_ca.paa";
				
			};
			onLBSelChanged = QUOTE(_this call FUNC(onButtonLB_changed));
		};
		
	};
};

