#define UNITAF_INSIGNIA(CLASSNAME,NAME,COLOR,FILE) \
    class GVAR(CLASSNAME) { \
        displayName = QUOTE([UNITAF] #NAME (#COLOR)); \
        author = "$STR_unitaf_main_Author"; \
        texture = QUOTE(\u\UNITAF\addons\insignias\ui\##FILE); \
        dlc = QUOTE(PREFIX); \
    };

class CfgUnitInsignia
{
    // Olive Drab
    UNITAF_INSIGNIA(Cadet_OD,QUOTE(QUOTE(E-0 Cadet)),OD,Cadet.OD.paa)
    UNITAF_INSIGNIA(Recruit_OD,QUOTE(QUOTE(E-0 Recruit)),OD,Recruit.OD.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_OD,QUOTE(QUOTE(E-2 Private)),OD,E-2.Private.OD.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_OD,QUOTE(QUOTE(E-3 Private First Class)),OD,E-3.PrivateFirstClass.OD.paa)
    UNITAF_INSIGNIA(Specialist_OD,QUOTE(QUOTE(E-4 Specialist)),OD,E-4.Specialist.OD.paa)
    UNITAF_INSIGNIA(Corporal_OD,QUOTE(QUOTE(E-4 Corporal)),OD,E-4.Corporal.OD.paa)
    UNITAF_INSIGNIA(Sergeant_OD,QUOTE(QUOTE(E-5 Sergeant)),OD,E-5.Sergeant.OD.paa)
    UNITAF_INSIGNIA(StaffSergeant_OD,QUOTE(QUOTE(E-6 Staff Sergeant)),OD,E-6.StaffSergeant.OD.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_OD,QUOTE(QUOTE(E-7 Sergeant First Class)),OD,E-7.SergeantFirstClass.OD.paa)
    UNITAF_INSIGNIA(MasterSergeant_OD,QUOTE(QUOTE(E-8 Master Sergeant)),OD,E-8.MasterSergeant.OD.paa)
    UNITAF_INSIGNIA(FirstSergeant_OD,QUOTE(QUOTE(E-8 First Sergeant)),OD,E-8.FirstSergeant.OD.paa)
    UNITAF_INSIGNIA(SergeantMajor_OD,QUOTE(QUOTE(E-9 Master Sergeant)),OD,E-9.SergeantMajor.OD.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_OD,QUOTE(QUOTE(E-9 Command Sergeant Major)),OD,E-9.CommandSergeantMajor.OD.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_OD,QUOTE(QUOTE(E-9 Sergeant Major of the Army)),OD,E-9.SergeantMajorOfTheArmy.OD.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_OD,QUOTE(QUOTE(E-9 Senior Enlisted Advisor to the Chairman)),OD,E-9.SeniorEnlistedAdvisorToTheChairman.OD.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_OD,QUOTE(QUOTE(WO-1 Warrant Officer 1)),OD,WO1.WarrantOfficer1.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_OD,QUOTE(QUOTE(CW-2 Chief Warrant Officer 2)),OD,CW2.ChiefWarrantOfficer2.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_OD,QUOTE(QUOTE(CW-3 Chief Warrant Officer 3)),OD,CW3.ChiefWarrantOfficer3.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_OD,QUOTE(QUOTE(CW-4 Chief Warrant Officer 4)),OD,CW4.ChiefWarrantOfficer4.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_OD,QUOTE(QUOTE(CW-5 Chief Warrant Officer 5)),OD,CW5.ChiefWarrantOfficer5.OD.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_OD,QUOTE(QUOTE(O-1 Second Lieutenant)),OD,O1.SecondLieutenant.OD.paa)
    UNITAF_INSIGNIA(FirstLieutenant_OD,QUOTE(QUOTE(O-2 First Lieutenant)),OD,O2.FirstLieutenant.OD.paa)
    UNITAF_INSIGNIA(Captain_OD,QUOTE(QUOTE(O-3 Captain)),OD,O3.Captain.OD.paa)
    UNITAF_INSIGNIA(Major_OD,QUOTE(QUOTE(O-4 Major)),OD,O4.Major.OD.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_OD,QUOTE(QUOTE(Medic)),OD,role.Medic.OD.paa)
    UNITAF_INSIGNIA(Medic2_OD,QUOTE(QUOTE(Medic (Cross))),OD,role.Medic2.OD.paa)
    UNITAF_INSIGNIA(EOD_OD,QUOTE(QUOTE(EOD)),OD,role.EOD.OD.paa)
    UNITAF_INSIGNIA(JTAC_OD,QUOTE(QUOTE(JTAC)),OD,role.JTAC.OD.paa)
    UNITAF_INSIGNIA(UAV_OD,QUOTE(QUOTE(UAV Operator)),OD,role.UAV.OD.paa)
    UNITAF_INSIGNIA(GM_OD,QUOTE(QUOTE(Game Master)),OD,role.GM.OD.paa)

    // Tan
    UNITAF_INSIGNIA(Cadet_Tan,QUOTE(QUOTE(E-0 Cadet)),Tan,Cadet.Tan.paa)
    UNITAF_INSIGNIA(Recruit_Tan,QUOTE(QUOTE(E-0 Recruit)),Tan,Recruit.Tan.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_Tan,QUOTE(QUOTE(E-2 Private)),Tan,E-2.Private.Tan.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_Tan,QUOTE(QUOTE(E-3 Private First Class)),Tan,E-3.PrivateFirstClass.Tan.paa)
    UNITAF_INSIGNIA(Specialist_Tan,QUOTE(QUOTE(E-4 Specialist)),Tan,E-4.Specialist.Tan.paa)
    UNITAF_INSIGNIA(Corporal_Tan,QUOTE(QUOTE(E-4 Corporal)),Tan,E-4.Corporal.Tan.paa)
    UNITAF_INSIGNIA(Sergeant_Tan,QUOTE(QUOTE(E-5 Sergeant)),Tan,E-5.Sergeant.Tan.paa)
    UNITAF_INSIGNIA(StaffSergeant_Tan,QUOTE(QUOTE(E-6 Staff Sergeant)),Tan,E-6.StaffSergeant.Tan.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_Tan,QUOTE(QUOTE(E-7 Sergeant First Class)),Tan,E-7.SergeantFirstClass.Tan.paa)
    UNITAF_INSIGNIA(MasterSergeant_Tan,QUOTE(QUOTE(E-8 Master Sergeant)),Tan,E-8.MasterSergeant.Tan.paa)
    UNITAF_INSIGNIA(FirstSergeant_Tan,QUOTE(QUOTE(E-8 First Sergeant)),Tan,E-8.FirstSergeant.Tan.paa)
    UNITAF_INSIGNIA(SergeantMajor_Tan,QUOTE(QUOTE(E-9 Master Sergeant)),Tan,E-9.SergeantMajor.Tan.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_Tan,QUOTE(QUOTE(E-9 Command Sergeant Major)),Tan,E-9.CommandSergeantMajor.Tan.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_Tan,QUOTE(QUOTE(E-9 Sergeant Major of the Army)),Tan,E-9.SergeantMajorOfTheArmy.Tan.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_Tan,QUOTE(QUOTE(E-9 Senior Enlisted Advisor to the Chairman)),Tan,E-9.SeniorEnlistedAdvisorToTheChairman.Tan.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_Tan,QUOTE(QUOTE(WO-1 Warrant Officer 1)),Tan,WO1.WarrantOfficer1.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_Tan,QUOTE(QUOTE(CW-2 Chief Warrant Officer 2)),Tan,CW2.ChiefWarrantOfficer2.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_Tan,QUOTE(QUOTE(CW-3 Chief Warrant Officer ))3,Tan,CW3.ChiefWarrantOfficer3.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_Tan,QUOTE(QUOTE(CW-4 Chief Warrant Officer 4)),Tan,CW4.ChiefWarrantOfficer4.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_Tan,QUOTE(QUOTE(CW-5 Chief Warrant Officer 5)),Tan,CW5.ChiefWarrantOfficer5.Tan.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_Tan,QUOTE(QUOTE(O-1 Second Lieutenant)),Tan,O1.SecondLieutenant.Tan.paa)
    UNITAF_INSIGNIA(FirstLieutenant_Tan,QUOTE(QUOTE(O-2 First Lieutenant)),Tan,O2.FirstLieutenant.Tan.paa)
    UNITAF_INSIGNIA(Captain_Tan,QUOTE(QUOTE(O-3 Captain)),Tan,O3.Captain.Tan.paa)
    UNITAF_INSIGNIA(Major_Tan,QUOTE(QUOTE(O-4 Major)),Tan,O4.Major.Tan.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_Tan,QUOTE(QUOTE(Medic)),Tan,role.Medic.Tan.paa)
    UNITAF_INSIGNIA(Medic2_Tan,QUOTE(QUOTE(Medic (Cross))),Tan,role.Medic2.Tan.paa)
    UNITAF_INSIGNIA(EOD_Tan,QUOTE(QUOTE(EOD)),Tan,role.EOD.Tan.paa)
    UNITAF_INSIGNIA(JTAC_Tan,QUOTE(QUOTE(JTAC)),Tan,role.JTAC.Tan.paa)
    UNITAF_INSIGNIA(UAV_Tan,QUOTE(QUOTE(UAV Operator)),Tan,role.UAV.Tan.paa)
    UNITAF_INSIGNIA(GM_Tan,QUOTE(QUOTE(Game Master)),Tan,role.GM.Tan.paa)


    // Multicam
    UNITAF_INSIGNIA(Cadet_MC,QUOTE(QUOTE(E-0 Cadet)),MC,Cadet.MC.paa)
    UNITAF_INSIGNIA(Recruit_MC,QUOTE(QUOTE(E-0 Recruit)),MC,Recruit.MC.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_MC,QUOTE(QUOTE(E-2 Private)),MC,E-2.Private.MC.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_MC,QUOTE(QUOTE(E-3 Private First Class)),MC,E-3.PrivateFirstClass.MC.paa)
    UNITAF_INSIGNIA(Specialist_MC,QUOTE(QUOTE(E-4 Specialist)),MC,E-4.Specialist.MC.paa)
    UNITAF_INSIGNIA(Corporal_MC,QUOTE(QUOTE(E-4 Corporal)),MC,E-4.Corporal.MC.paa)
    UNITAF_INSIGNIA(Sergeant_MC,QUOTE(QUOTE(E-5 Sergeant)),MC,E-5.Sergeant.MC.paa)
    UNITAF_INSIGNIA(StaffSergeant_MC,QUOTE(QUOTE(E-6 Staff Sergeant)),MC,E-6.StaffSergeant.MC.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_MC,QUOTE(QUOTE(E-7 Sergeant First Class)),MC,E-7.SergeantFirstClass.MC.paa)
    UNITAF_INSIGNIA(MasterSergeant_MC,QUOTE(QUOTE(E-8 Master Sergeant)),MC,E-8.MasterSergeant.MC.paa)
    UNITAF_INSIGNIA(FirstSergeant_MC,QUOTE(QUOTE(E-8 First Sergeant)),MC,E-8.FirstSergeant.MC.paa)
    UNITAF_INSIGNIA(SergeantMajor_MC,QUOTE(QUOTE(E-9 Master Sergeant)),MC,E-9.SergeantMajor.MC.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_MC,QUOTE(QUOTE(E-9 Command Sergeant Major)),MC,E-9.CommandSergeantMajor.MC.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_MC,QUOTE(QUOTE(E-9 Sergeant Major of the Army)),MC,E-9.SergeantMajorOfTheArmy.MC.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_MC,QUOTE(QUOTE(E-9 Senior Enlisted Advisor to the Chairman)),MC,E-9.SeniorEnlistedAdvisorToTheChairman.MC.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_MC,QUOTE(QUOTE(WO-1 Warrant Officer 1)),MC,WO1.WarrantOfficer1.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_MC,QUOTE(QUOTE(CW-2 Chief Warrant Officer 2)),MC,CW2.ChiefWarrantOfficer2.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_MC,QUOTE(QUOTE(CW-3 Chief Warrant Officer 3)),MC,CW3.ChiefWarrantOfficer3.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_MC,QUOTE(QUOTE(CW-4 Chief Warrant Officer 4)),MC,CW4.ChiefWarrantOfficer4.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_MC,QUOTE(QUOTE(CW-5 Chief Warrant Officer 5)),MC,CW5.ChiefWarrantOfficer5.MC.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_MC,QUOTE(QUOTE(O-1 Second Lieutenant)),MC,O1.SecondLieutenant.MC.paa)
    UNITAF_INSIGNIA(FirstLieutenant_MC,QUOTE(QUOTE(O-2 First Lieutenant)),MC,O2.FirstLieutenant.MC.paa)
    UNITAF_INSIGNIA(Captain_MC,QUOTE(QUOTE(O-3 Captain)),MC,O3.Captain.MC.paa)
    UNITAF_INSIGNIA(Major_MC,QUOTE(QUOTE(O-4 Major)),MC,O4.Major.MC.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_MC,QUOTE(QUOTE(Medic)),MC,role.Medic.MC.paa)
    UNITAF_INSIGNIA(Medic2_MC,QUOTE(QUOTE(Medic (Cross))),MC,role.Medic2.MC.paa)
    UNITAF_INSIGNIA(EOD_MC,QUOTE(QUOTE(EOD)),MC,role.EOD.MC.paa)
    UNITAF_INSIGNIA(JTAC_MC,QUOTE(QUOTE(JTAC)),MC,role.JTAC.MC.paa)
    UNITAF_INSIGNIA(UAV_MC,QUOTE(QUOTE(UAV Operato))r,MC,role.UAV.MC.paa)
    UNITAF_INSIGNIA(GM_MC,QUOTE(QUOTE(Game Master)),MC,role.GM.MC.paa)

    // Black
    UNITAF_INSIGNIA(Cadet_Bl,QUOTE(QUOTE(E-0 Cadet)),Black,Cadet.Bl.paa)
    UNITAF_INSIGNIA(Recruit_Bl,QUOTE(QUOTE(E-0 Recruit)),Black,Recruit.Bl.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_Bl,QUOTE(QUOTE(E-2 Private)),Black,E-2.Private.Bl.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_Bl,QUOTE(QUOTE(E-3 Private First Class)),Black,E-3.PrivateFirstClass.Bl.paa)
    UNITAF_INSIGNIA(Specialist_Bl,QUOTE(QUOTE(E-4 Specialist)),Black,E-4.Specialist.Bl.paa)
    UNITAF_INSIGNIA(Corporal_Bl,QUOTE(QUOTE(E-4 Corporal)),Black,E-4.Corporal.Bl.paa)
    UNITAF_INSIGNIA(Sergeant_Bl,QUOTE(QUOTE(E-5 Sergeant)),Black,E-5.Sergeant.Bl.paa)
    UNITAF_INSIGNIA(StaffSergeant_Bl,QUOTE(QUOTE(E-6 Staff Sergeant)),Black,E-6.StaffSergeant.Bl.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_Bl,QUOTE(QUOTE(E-7 Sergeant First Class)),Black,E-7.SergeantFirstClass.Bl.paa)
    UNITAF_INSIGNIA(MasterSergeant_Bl,QUOTE(QUOTE(E-8 Master Sergeant)),Black,E-8.MasterSergeant.Bl.paa)
    UNITAF_INSIGNIA(FirstSergeant_Bl,QUOTE(QUOTE(E-8 First Sergeant)),Black,E-8.FirstSergeant.Bl.paa)
    UNITAF_INSIGNIA(SergeantMajor_Bl,QUOTE(QUOTE(E-9 Master Sergeant)),Black,E-9.SergeantMajor.Bl.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_Bl,QUOTE(QUOTE(E-9 Command Sergeant Major)),Black,E-9.CommandSergeantMajor.Bl.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_Bl,QUOTE(QUOTE(E-9 Sergeant Major of the Army)),Black,E-9.SergeantMajorOfTheArmy.Bl.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_Bl,QUOTE(QUOTE(E-9 Senior Enlisted Advisor to the Chairman)),Black,E-9.SeniorEnlistedAdvisorToTheChairman.Bl.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_Bl,QUOTE(QUOTE(WO-1 Warrant Officer 1)),Black,WO1.WarrantOfficer1.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_Bl,QUOTE(QUOTE(CW-2 Chief Warrant Officer 2)),Black,CW2.ChiefWarrantOfficer2.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_Bl,QUOTE(QUOTE(CW-3 Chief Warrant Officer 3)),Black,CW3.ChiefWarrantOfficer3.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_Bl,QUOTE(QUOTE(CW-4 Chief Warrant Officer 4)),Black,CW4.ChiefWarrantOfficer4.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_Bl,QUOTE(QUOTE(CW-5 Chief Warrant Officer 5)),Black,CW5.ChiefWarrantOfficer5.Bl.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_Bl,QUOTE(QUOTE(O-1 Second Lieutenant)),Black,O1.SecondLieutenant.Bl.paa)
    UNITAF_INSIGNIA(FirstLieutenant_Bl,QUOTE(QUOTE(O-2 First Lieutenant)),Black,O2.FirstLieutenant.Bl.paa)
    UNITAF_INSIGNIA(Captain_Bl,QUOTE(QUOTE(O-3 Captain)),Black,O3.Captain.Bl.paa)
    UNITAF_INSIGNIA(Major_Bl,QUOTE(QUOTE(O-4 Major)),Black,O4.Major.Bl.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_Bl,QUOTE(QUOTE(Medic)),Black,role.Medic.Bl.paa)
    UNITAF_INSIGNIA(Medic2_Bl,QUOTE(QUOTE(Medic (Cross))),Black,role.Medic2.Bl.paa)
    UNITAF_INSIGNIA(EOD_Bl,QUOTE(QUOTE(EOD)),Black,role.EOD.Bl.paa)
    UNITAF_INSIGNIA(JTAC_Bl,QUOTE(QUOTE(JTAC)),Black,role.JTAC.Bl.paa)
    UNITAF_INSIGNIA(UAV_Bl,QUOTE(QUOTE(UAV Operator)),Black,role.UAV.Bl.paa)
    UNITAF_INSIGNIA(GM_Bl,QUOTE(QUOTE(Game Master)),Black,role.GM.Bl.paa)
};