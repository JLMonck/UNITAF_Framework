class RscMapControl;
class RscText;
class RscFrame;
class RscXSliderH;

class ScrollBar;
class RscControlsGroup
{
	type=15;
	idc=-1;
	x=0;
	y=0;
	w=1;
	h=1;
	shadow=0;
	style=16;
	class VScrollbar: ScrollBar
	{
		width=0.021;
		autoScrollEnabled=1;
	};
	class HScrollbar: ScrollBar
	{
		height=0.028000001;
	};
	class Controls
	{
	};
};

class RscDisplayCamera2
{
	scriptName="RscDisplayCamera2";
	scriptPath="UNITAF_Camera";
	onLoad="[""onLoad"",_this,""RscDisplayCamera2"",'UNITAF_Camera'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	onUnload="[""onUnload"",_this,""RscDisplayCamera2"",'UNITAF_Camera'] call 	(uinamespace getvariable 'BIS_fnc_initDisplay')";
	idd=314;
	movingEnable=0;
	enableSimulation=1;
	iconCamera="\A3\ui_f\data\GUI\Rsc\RscDisplayMissionEditor\iconCamera_ca.paa";
	class ControlsBackground
	{
		class Map: RscMapControl
		{
			idc=3141;
			x=-10;
			y=-10;
			w="0.8 * safezoneW";
			h="0.8 * safezoneH";
		};
		class Overlay: RscControlsGroup
		{
			idc=3142;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			class Controls
			{
				class Header: RscText
				{
					colorText[]={1,1,1,1};
					colorBackground[]={0,0,0,0};
					x=0;
					y=0;
					w="safezoneW";
					h="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_Header";
					font="RobotoCondensedLight";
					sizeEx="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shadow=1;
				};
				class SubHeader: Header
				{
					x=0;
					y="1.5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w="safezoneW";
					h="14 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_SubHeader";
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					style=16;
				};
				class Debug: Header
				{
					idc=31420;
					x=0;
					y="safezoneH - 8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					h="8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="";
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shadow=1;
					style=16;
				};
				class Positions: Header
				{
					idc=31422;
					x="safezoneW - 0.2";
					y=0;
					h="10 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w=0.2;
					text="";
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					shadow=1;
					style=16;
				};
				class Unit: RscFrame
				{
					colorText[]={1,1,1,1};
					idc=31421;
					x=-10;
					y=-10;
					w=0;
					h=0;
				};
				class LineHorizontalTop: RscText
				{
					colorBackground[]={0.75,0.75,0.75,0.75};
					x=0;
					y="0.33 * safezoneH";
					w="safezoneW";
					h="0.001 * safezoneH";
				};
				class LineHorizontalBottom: LineHorizontalTop
				{
					x=0;
					y="0.66 * safezoneH";
					w="safezoneW";
					h="0.001 * safezoneH";
				};
				class LineVerticalLeft: LineHorizontalTop
				{
					x="0.66 * safezoneW";
					y=0;
					w="0.001 * safezoneH";
					h="safezoneH";
				};
				class LineVerticalRight: LineHorizontalTop
				{
					x="0.33 * safezoneW";
					y=0;
					w="0.001 * safezoneH";
					h="safezoneH";
				};
				class CrossHorizontal: LineHorizontalTop
				{
					x="(safezoneW / 2) - (0.1 / 2)";
					y="(safezoneH / 2)";
					w=0.1;
					h="0.001 * safezoneH";
				};
				class CrossVertical: LineHorizontalTop
				{
					x="(safezoneW / 2)";
					y="(safezoneH / 2) - (0.1 / 2)";
					w="0.001 * safezoneH";
					h=0.1;
				};
			};
		};
		class MouseArea: RscText
		{
			idc=3140;
			style=16;
			x="safezoneX";
			y="safezoneY";
			w="safezoneW";
			h="safezoneH";
		};
	};
	class Controls
	{
		class Overlay: RscControlsGroup
		{
			idc=3143;
			x="safezoneX + safezoneW - 14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			y="safezoneY + safezoneH - 8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			w="14 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
			h="8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			class Controls
			{
				class Text1: RscText
				{
					x=0;
					y=0;
					w="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_TextFocus";
					style=1;
					sizeEx="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					font="RobotoCondensedLight";
					shadow=1;
				};
				class Slider1: RscXSliderH
				{
					idc=31430;
					x="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					y=0;
					w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					h="0.8 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					color[]={1,1,1,0.40000001};
					colorActive[]={1,1,1,0.60000002};
					arrowEmpty="\A3\ui_f\data\gui\cfg\slider\arrowEmpty_ca.paa";
					arrowFull="\A3\ui_f\data\gui\cfg\slider\arrowFull_ca.paa";
					border="#(argb,8,8,3)color(0,0,0,0.1)";
					thumb="#(argb,8,8,3)color(1,1,1,1)";
				};
				class Value1: Text1
				{
					idc=31431;
					x="4 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					w="10 * 			(			((safezoneW / safezoneH) min 1.2) / 40)";
					text="0";
					style=2;
					colorText[]={1,1,1,1};
				};
				class Text2: Text1
				{
					y="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_TextAperture";
				};
				class Slider2: Slider1
				{
					idc=31432;
					y="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value2: Value1
				{
					idc=31433;
					y="1 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text6: Text1
				{
					y="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_disp_opt_bright";
				};
				class Slider6: Slider1
				{
					idc=31440;
					y="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value6: Value1
				{
					idc=31441;
					y="2 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text7: Text1
				{
					y="3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_a3_rscdisplayoptionsvideo_textcontrast";
				};
				class Slider7: Slider1
				{
					idc=31442;
					y="3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value7: Value1
				{
					idc=31443;
					y="3 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text8: Text1
				{
					y="4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_a3_rscdisplayoptionsvideo_textsaturation";
				};
				class Slider8: Slider1
				{
					idc=31444;
					y="4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value8: Value1
				{
					idc=31445;
					y="4 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text3: Text1
				{
					y="5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_TextDaytime";
				};
				class Slider3: Slider1
				{
					idc=31434;
					y="5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value3: Value1
				{
					idc=31435;
					y="5 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text4: Text1
				{
					y="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_TextOvercast";
				};
				class Slider4: Slider1
				{
					idc=31436;
					y="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value4: Value1
				{
					idc=31437;
					y="6 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Text5: Text1
				{
					y="7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					text="$STR_A3_RscDisplayCamera_TextAcctime";
				};
				class Slider5: Slider1
				{
					idc=31438;
					y="7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class Value5: Value1
				{
					idc=31439;
					y="7 * 			(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
			};
		};
	};
};