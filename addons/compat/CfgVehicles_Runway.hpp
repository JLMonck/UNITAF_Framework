class House;
class Land_NavigLight: House {
	scope = 2;
	scopeCurator = 1;
	displayName = "REIL (Single, Yellow)";
};
class Land_NavigLight_3_F: Land_NavigLight {
	displayName = "REIL (Tripple, Red)";
};
class Land_NavigLight_3_short_F: Land_NavigLight_3_F {
	displayName = "REIL Low (Tripple, Red)";
};

class Land_Flush_Light_green_F: Land_NavigLight {
	displayName = "Runway Flush Light (Green)";
};
class Land_Flush_Light_red_F: Land_Flush_Light_green_F {
displayName = "Runway Flush Light (Red)";
};
class Land_Flush_Light_yellow_F: Land_Flush_Light_green_F {
	displayName = "Runway Flush Light (Yellow)";
};

class Land_Flush_Light_white_F: Land_Flush_Light_yellow_F {
	displayName = "Runway Flush Light (White)";
	class MarkerLights {
		class Light_1 {
			color[]={0.94999999,0.94999999,0.94999999};
			ambient[]={0,0,0};
			intensity=30;
			name="Light_1_pos";
			drawLight=1;
			drawLightSize=1;
			drawLightCenterSize=0.1;
			activeLight=0;
			blinking=0;
			dayLight=0;
			useFlare=0;
		};
	};
};

class Land_runway_edgelight: Land_NavigLight {
	displayName = "Runway Edgelight (White)";
};
class Land_runway_edgelight_blue_F: Land_runway_edgelight {
	displayName = "Runway Edgelight (Blue)";
};
class Land_runway_edgelight_red_F: Land_runway_edgelight {
	displayName = "Runway Edgelight (Red)";
	class MarkerLights {
		class Light_1 {
			color[]={0.94999999,0.15000001,0.15000001};
			ambient[]={0,0,0};
			intensity=30;
			name="Light_1_pos";
			drawLight=1;
			drawLightSize=1;
			drawLightCenterSize=0.1;
			activeLight=0;
			blinking=0;
			dayLight=0;
			useFlare=0;
		};
	};
};

class Land_VASICore;
class Land_Runway_PAPI: Land_VASICore {
	scope = 2;
	scopeCurator = 1;
	displayName = "PAPI Light 1";
};
class Land_Runway_PAPI_2: Land_Runway_PAPI {
	displayName = "PAPI Light 2";
};
class Land_Runway_PAPI_3: Land_Runway_PAPI {
	displayName = "PAPI Light 3";
};
class Land_Runway_PAPI_4: Land_Runway_PAPI {
	displayName = "PAPI Light 4";
};