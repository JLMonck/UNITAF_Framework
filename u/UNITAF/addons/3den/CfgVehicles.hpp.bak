class CfgVehicles {
    class Logic;
    class Module_F: Logic {
		class AttributesBase {
			class Default;
			class Edit;					// Default edit box (i.e., text input field)
			//class Combo;				// Default combo box (i.e., drop-down menu)
			//class Checkbox;				// Default checkbox (returned value is Boolean)
			//class CheckboxNumber;		// Default checkbox (returned value is Number)
			class ModuleDescription;	// Module description
			//class Units;				// Selection of units on which the module is applied
		};
		// Description base classes, for more information see below
		class ModuleDescription {
            class Anything;
			class EmptyDetector;
		};
	};
	class GVAR(ExportToSQM): Module_F {
        // Standard object definitions
		displayName     = "Export composition"; // Name displayed in the menu
		//icon            = "\myTag_addonName\data\iconNuke_ca.paa"; // Map icon. Delete this entry to use the default icon
		category        = "Faction_UNITAF";

        mapSize = 1;
        side = 7;
        scope = 2;				// Editor visibility; 2 will show it in the menu, 1 will hide it.
		scopeCurator = 1;		// Curator visibility; 2 will show it in the menu, 1 will hide it.

        // Name of function triggered once conditions are met
		function = QFUNC(modeuleExportComposition);
		// Execution priority, modules with lower number are executed first. 0 is used when the attribute is undefined
		functionPriority = 1;
		// 0 for server only execution, 1 for global execution, 2 for persistent global execution
		isGlobal = 1;
		// 1 for module waiting until all synced triggers are activated
		isTriggerActivated = 0;
		// 1 if modules is to be disabled once it is activated (i.e., repeated trigger activation won't work)
		isDisposable = 1;
		// 1 to run init function in Eden Editor as well
		is3DEN = 1;

        class Arguments {};
        class Attributes: AttributesBase {
            class Name: Edit
			{
				displayName = "Name";
				tooltip = "Name of the composition";
				defaultValue = """Super Special Composition""";
			};
            class ModuleDescription: ModuleDescription {};
        };
		class ModuleDescription: ModuleDescription {
			description = "Export composition";
            sync[] = {};
		};
    };
};