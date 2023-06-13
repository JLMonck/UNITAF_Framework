/**
 * simulation
 * inherited from SmokeShell is shotSmokeX which ignores "deflecting" and "deflectionSlowDown" parameters
 *
 * multiplier
 * small bounce, on 400m flat ground shot ~10m bounce
 */
#define FIX40MM \
    simulation = "shotSmoke"; \
    deflectionSlowDown = 0.3;

class CfgAmmo {
	// Fix 40mm bounce issue
    class SmokeShell;
    class G_40mm_Smoke : SmokeShell {
        FIX40MM
    };

    // Smoke
	class SmokeShellYellow;
	class SmokeShellGreen;
	class SmokeShellRed;
	class rhs_40mm_smoke_white: SmokeShell {
		FIX40MM
	};
	class rhs_40mm_smoke_red: SmokeShellRed {
		FIX40MM
	};
	class rhs_40mm_smoke_green: SmokeShellGreen {
		FIX40MM
	};
	class rhs_40mm_smoke_yellow: SmokeShellYellow {
		FIX40MM
	};

    // Needed?
	class rhs_40mm_m714_white: SmokeShell {
		FIX40MM
	};
	class rhs_40mm_m713_red: SmokeShellRed {
		FIX40MM
	};
	class rhs_40mm_m715_green: SmokeShellGreen {
		FIX40MM
	};
	class rhs_40mm_m716_yellow: SmokeShellYellow {
		FIX40MM
	};
};