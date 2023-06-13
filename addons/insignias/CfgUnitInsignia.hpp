#define UNITAF_INSIGNIA(CLASSNAME,NAME,COLOR,FILE) \
    class GVAR(CLASSNAME) { \
        displayName = QUOTE([UNITAF] NAME (COLOR)); \
        author = "$STR_unitaf_main_Author"; \
        texture = QUOTE(\u\UNITAF\addons\insignias\ui\##FILE); \
        dlc = QUOTE(PREFIX); \
    };

class CfgUnitInsignia
{
    // Olive Drab
    UNITAF_INSIGNIA(Cadet_OD,E-0 Cadet,OD,Cadet.OD.paa)
    UNITAF_INSIGNIA(Recruit_OD,E-0 Recruit,OD,Recruit.OD.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_OD,E-2 Private,OD,E-2.Private.OD.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_OD, E-3 Private First Class,OD,E-3.PrivateFirstClass.OD.paa)
    UNITAF_INSIGNIA(Specialist_OD,E-4 Specialist,OD,E-4.Specialist.OD.paa)
    UNITAF_INSIGNIA(Corporal_OD,E-4 Corporal,OD,E-4.Corporal.OD.paa)
    UNITAF_INSIGNIA(Sergeant_OD,E-5 Sergeant,OD,E-5.Sergeant.OD.paa)
    UNITAF_INSIGNIA(StaffSergeant_OD,E-6 Staff Sergeant,OD,E-6.StaffSergeant.OD.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_OD,E-7 Sergeant First Class,OD,E-7.SergeantFirstClass.OD.paa)
    UNITAF_INSIGNIA(MasterSergeant_OD,E-8 Master Sergeant,OD,E-8.MasterSergeant.OD.paa)
    UNITAF_INSIGNIA(FirstSergeant_OD,E-8 First Sergeant,OD,E-8.FirstSergeant.OD.paa)
    UNITAF_INSIGNIA(SergeantMajor_OD,E-9 Master Sergeant,OD,E-9.SergeantMajor.OD.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_OD,E-9 Command Sergeant Major,OD,E-9.CommandSergeantMajor.OD.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_OD,E-9 Sergeant Major of the Army,OD,E-9.SergeantMajorOfTheArmy.OD.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_OD,E-9 Senior Enlisted Advisor to the Chairman,OD,E-9.SeniorEnlistedAdvisorToTheChairman.OD.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_OD,WO-1 Warrant Officer 1,OD,WO1.WarrantOfficer1.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_OD,CW-2 Chief Warrant Officer 2,OD,CW2.ChiefWarrantOfficer2.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_OD,CW-3 Chief Warrant Officer 3,OD,CW3.ChiefWarrantOfficer3.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_OD,CW-4 Chief Warrant Officer 4,OD,CW4.ChiefWarrantOfficer4.OD.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_OD,CW-5 Chief Warrant Officer 5,OD,CW5.ChiefWarrantOfficer5.OD.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_OD,O-1 Second Lieutenant,OD,O1.SecondLieutenant.OD.paa)
    UNITAF_INSIGNIA(FirstLieutenant_OD,O-2 First Lieutenant,OD,O2.FirstLieutenant.OD.paa)
    UNITAF_INSIGNIA(Captain_OD,O-3 Captain,OD,O3.Captain.OD.paa)
    UNITAF_INSIGNIA(Major_OD,O-4 Major,OD,O4.Major.OD.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_OD,Medic,OD,role.Medic.OD.paa)
    UNITAF_INSIGNIA(Medic2_OD,Medic (Cross),OD,role.Medic2.OD.paa)
    UNITAF_INSIGNIA(EOD_OD,EOD,OD,role.EOD.OD.paa)
    UNITAF_INSIGNIA(JTAC_OD,JTAC,OD,role.JTAC.OD.paa)
    UNITAF_INSIGNIA(UAV_OD,UAV Operator,OD,role.UAV.OD.paa)
    UNITAF_INSIGNIA(GM_OD,Game Master,OD,role.GM.OD.paa)

    // Tan
    UNITAF_INSIGNIA(Cadet_Tan,E-0 Cadet,Tan,Cadet.Tan.paa)
    UNITAF_INSIGNIA(Recruit_Tan,E-0 Recruit,Tan,Recruit.Tan.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_Tan,E-2 Private,Tan,E-2.Private.Tan.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_Tan, E-3 Private First Class,Tan,E-3.PrivateFirstClass.Tan.paa)
    UNITAF_INSIGNIA(Specialist_Tan,E-4 Specialist,Tan,E-4.Specialist.Tan.paa)
    UNITAF_INSIGNIA(Corporal_Tan,E-4 Corporal,Tan,E-4.Corporal.Tan.paa)
    UNITAF_INSIGNIA(Sergeant_Tan,E-5 Sergeant,Tan,E-5.Sergeant.Tan.paa)
    UNITAF_INSIGNIA(StaffSergeant_Tan,E-6 Staff Sergeant,Tan,E-6.StaffSergeant.Tan.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_Tan,E-7 Sergeant First Class,Tan,E-7.SergeantFirstClass.Tan.paa)
    UNITAF_INSIGNIA(MasterSergeant_Tan,E-8 Master Sergeant,Tan,E-8.MasterSergeant.Tan.paa)
    UNITAF_INSIGNIA(FirstSergeant_Tan,E-8 First Sergeant,Tan,E-8.FirstSergeant.Tan.paa)
    UNITAF_INSIGNIA(SergeantMajor_Tan,E-9 Master Sergeant,Tan,E-9.SergeantMajor.Tan.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_Tan,E-9 Command Sergeant Major,Tan,E-9.CommandSergeantMajor.Tan.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_Tan,E-9 Sergeant Major of the Army,Tan,E-9.SergeantMajorOfTheArmy.Tan.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_Tan,E-9 Senior Enlisted Advisor to the Chairman,Tan,E-9.SeniorEnlistedAdvisorToTheChairman.Tan.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_Tan,WO-1 Warrant Officer 1,Tan,WO1.WarrantOfficer1.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_Tan,CW-2 Chief Warrant Officer 2,Tan,CW2.ChiefWarrantOfficer2.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_Tan,CW-3 Chief Warrant Officer 3,Tan,CW3.ChiefWarrantOfficer3.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_Tan,CW-4 Chief Warrant Officer 4,Tan,CW4.ChiefWarrantOfficer4.Tan.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_Tan,CW-5 Chief Warrant Officer 5,Tan,CW5.ChiefWarrantOfficer5.Tan.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_Tan,O-1 Second Lieutenant,Tan,O1.SecondLieutenant.Tan.paa)
    UNITAF_INSIGNIA(FirstLieutenant_Tan,O-2 First Lieutenant,Tan,O2.FirstLieutenant.Tan.paa)
    UNITAF_INSIGNIA(Captain_Tan,O-3 Captain,Tan,O3.Captain.Tan.paa)
    UNITAF_INSIGNIA(Major_Tan,O-4 Major,Tan,O4.Major.Tan.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_Tan,Medic,Tan,role.Medic.Tan.paa)
    UNITAF_INSIGNIA(Medic2_Tan,Medic (Cross),Tan,role.Medic2.Tan.paa)
    UNITAF_INSIGNIA(EOD_Tan,EOD,Tan,role.EOD.Tan.paa)
    UNITAF_INSIGNIA(JTAC_Tan,JTAC,Tan,role.JTAC.Tan.paa)
    UNITAF_INSIGNIA(UAV_Tan,UAV Operator,Tan,role.UAV.Tan.paa)
    UNITAF_INSIGNIA(GM_Tan,Game Master,Tan,role.GM.Tan.paa)


    // Multicam
    UNITAF_INSIGNIA(Cadet_MC,E-0 Cadet,MC,Cadet.MC.paa)
    UNITAF_INSIGNIA(Recruit_MC,E-0 Recruit,MC,Recruit.MC.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_MC,E-2 Private,MC,E-2.Private.MC.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_MC, E-3 Private First Class,MC,E-3.PrivateFirstClass.MC.paa)
    UNITAF_INSIGNIA(Specialist_MC,E-4 Specialist,MC,E-4.Specialist.MC.paa)
    UNITAF_INSIGNIA(Corporal_MC,E-4 Corporal,MC,E-4.Corporal.MC.paa)
    UNITAF_INSIGNIA(Sergeant_MC,E-5 Sergeant,MC,E-5.Sergeant.MC.paa)
    UNITAF_INSIGNIA(StaffSergeant_MC,E-6 Staff Sergeant,MC,E-6.StaffSergeant.MC.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_MC,E-7 Sergeant First Class,MC,E-7.SergeantFirstClass.MC.paa)
    UNITAF_INSIGNIA(MasterSergeant_MC,E-8 Master Sergeant,MC,E-8.MasterSergeant.MC.paa)
    UNITAF_INSIGNIA(FirstSergeant_MC,E-8 First Sergeant,MC,E-8.FirstSergeant.MC.paa)
    UNITAF_INSIGNIA(SergeantMajor_MC,E-9 Master Sergeant,MC,E-9.SergeantMajor.MC.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_MC,E-9 Command Sergeant Major,MC,E-9.CommandSergeantMajor.MC.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_MC,E-9 Sergeant Major of the Army,MC,E-9.SergeantMajorOfTheArmy.MC.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_MC,E-9 Senior Enlisted Advisor to the Chairman,MC,E-9.SeniorEnlistedAdvisorToTheChairman.MC.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_MC,WO-1 Warrant Officer 1,MC,WO1.WarrantOfficer1.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_MC,CW-2 Chief Warrant Officer 2,MC,CW2.ChiefWarrantOfficer2.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_MC,CW-3 Chief Warrant Officer 3,MC,CW3.ChiefWarrantOfficer3.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_MC,CW-4 Chief Warrant Officer 4,MC,CW4.ChiefWarrantOfficer4.MC.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_MC,CW-5 Chief Warrant Officer 5,MC,CW5.ChiefWarrantOfficer5.MC.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_MC,O-1 Second Lieutenant,MC,O1.SecondLieutenant.MC.paa)
    UNITAF_INSIGNIA(FirstLieutenant_MC,O-2 First Lieutenant,MC,O2.FirstLieutenant.MC.paa)
    UNITAF_INSIGNIA(Captain_MC,O-3 Captain,MC,O3.Captain.MC.paa)
    UNITAF_INSIGNIA(Major_MC,O-4 Major,MC,O4.Major.MC.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_MC,Medic,MC,role.Medic.MC.paa)
    UNITAF_INSIGNIA(Medic2_MC,Medic (Cross),MC,role.Medic2.MC.paa)
    UNITAF_INSIGNIA(EOD_MC,EOD,MC,role.EOD.MC.paa)
    UNITAF_INSIGNIA(JTAC_MC,JTAC,MC,role.JTAC.MC.paa)
    UNITAF_INSIGNIA(UAV_MC,UAV Operator,MC,role.UAV.MC.paa)
    UNITAF_INSIGNIA(GM_MC,Game Master,MC,role.GM.MC.paa)

    // Black
    UNITAF_INSIGNIA(Cadet_Bl,E-0 Cadet,Black,Cadet.Bl.paa)
    UNITAF_INSIGNIA(Recruit_Bl,E-0 Recruit,Black,Recruit.Bl.paa)

    // Enlisted
    UNITAF_INSIGNIA(Private_Bl,E-2 Private,Black,E-2.Private.Bl.paa)
    UNITAF_INSIGNIA(PrivateFirstClass_Bl, E-3 Private First Class,Black,E-3.PrivateFirstClass.Bl.paa)
    UNITAF_INSIGNIA(Specialist_Bl,E-4 Specialist,Black,E-4.Specialist.Bl.paa)
    UNITAF_INSIGNIA(Corporal_Bl,E-4 Corporal,Black,E-4.Corporal.Bl.paa)
    UNITAF_INSIGNIA(Sergeant_Bl,E-5 Sergeant,Black,E-5.Sergeant.Bl.paa)
    UNITAF_INSIGNIA(StaffSergeant_Bl,E-6 Staff Sergeant,Black,E-6.StaffSergeant.Bl.paa)
    UNITAF_INSIGNIA(SergeantFirstClass_Bl,E-7 Sergeant First Class,Black,E-7.SergeantFirstClass.Bl.paa)
    UNITAF_INSIGNIA(MasterSergeant_Bl,E-8 Master Sergeant,Black,E-8.MasterSergeant.Bl.paa)
    UNITAF_INSIGNIA(FirstSergeant_Bl,E-8 First Sergeant,Black,E-8.FirstSergeant.Bl.paa)
    UNITAF_INSIGNIA(SergeantMajor_Bl,E-9 Master Sergeant,Black,E-9.SergeantMajor.Bl.paa)
    UNITAF_INSIGNIA(CommandSergeantMajor_Bl,E-9 Command Sergeant Major,Black,E-9.CommandSergeantMajor.Bl.paa)
    UNITAF_INSIGNIA(SergeantMajorOfTheArmy_Bl,E-9 Sergeant Major of the Army,Black,E-9.SergeantMajorOfTheArmy.Bl.paa)
    UNITAF_INSIGNIA(SeniorEnlistedAdvisorToTheChairman_Bl,E-9 Senior Enlisted Advisor to the Chairman,Black,E-9.SeniorEnlistedAdvisorToTheChairman.Bl.paa)

    // Warrant Officer
    UNITAF_INSIGNIA(WarrantOfficer1_Bl,WO-1 Warrant Officer 1,Black,WO1.WarrantOfficer1.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer2_Bl,CW-2 Chief Warrant Officer 2,Black,CW2.ChiefWarrantOfficer2.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer3_Bl,CW-3 Chief Warrant Officer 3,Black,CW3.ChiefWarrantOfficer3.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer4_Bl,CW-4 Chief Warrant Officer 4,Black,CW4.ChiefWarrantOfficer4.Bl.paa)
    UNITAF_INSIGNIA(ChiefWarrantOfficer5_Bl,CW-5 Chief Warrant Officer 5,Black,CW5.ChiefWarrantOfficer5.Bl.paa)

    // Officers
    UNITAF_INSIGNIA(SecondLieutenant_Bl,O-1 Second Lieutenant,Black,O1.SecondLieutenant.Bl.paa)
    UNITAF_INSIGNIA(FirstLieutenant_Bl,O-2 First Lieutenant,Black,O2.FirstLieutenant.Bl.paa)
    UNITAF_INSIGNIA(Captain_Bl,O-3 Captain,Black,O3.Captain.Bl.paa)
    UNITAF_INSIGNIA(Major_Bl,O-4 Major,Black,O4.Major.Bl.paa)
    
    // Roles
    UNITAF_INSIGNIA(Medic1_Bl,Medic,Black,role.Medic.Bl.paa)
    UNITAF_INSIGNIA(Medic2_Bl,Medic (Cross),Black,role.Medic2.Bl.paa)
    UNITAF_INSIGNIA(EOD_Bl,EOD,Black,role.EOD.Bl.paa)
    UNITAF_INSIGNIA(JTAC_Bl,JTAC,Black,role.JTAC.Bl.paa)
    UNITAF_INSIGNIA(UAV_Bl,UAV Operator,Black,role.UAV.Bl.paa)
    UNITAF_INSIGNIA(GM_Bl,Game Master,Black,role.GM.Bl.paa)
};