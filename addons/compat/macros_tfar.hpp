//--
// Copied from TFAR 
//--

//Helpers for setting vehicles Isolation and if they have LR
#define MACRO_VEC_ISOLATION(vehicle,baseClass,isolation) class vehicle : baseClass { \
    tf_isolatedAmount = isolation; \
}

#define MACRO_VEC_LR(vehicle,baseClass,hasLR) class vehicle : baseClass { \
    tf_hasLRradio = hasLR; \
}

#define MACRO_VEC_ISOLATION_LR(vehicle,baseClass,isolation,hasLR) class vehicle : baseClass { \
    tf_hasLRradio = hasLR; \
    tf_isolatedAmount = isolation; \
}

#define Intercom_Variable format [ARR_2('TFAR_IntercomSlot_%1',(netID ACE_Player))]
#define Intercom_Condition(chan) \
    _vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [Intercom_Variable, -2];\
    if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot', TFAR_defaultIntercomSlot]};\
    _intercom != chan
//INFO! First 20 channels should be reserved for TFAR use.

#define IntercomMacro class ACE_SelfActions : ACE_SelfActions { \
    class TFAR_IntercomChannel { \
        displayName = CSTRING(Intercom_ACESelfAction_Name); \
        condition = "true"; \
        statement = ""; \
        icon = ""; \
        class TFAR_IntercomChannel_disabled { \
            displayName = "Disabled"; \
            condition = QUOTE(Intercom_Condition(-1)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,-1,true)];); \
        }; \
        class TFAR_IntercomChannel_1 { \
            displayName = CSTRING(Intercom_ACESelfAction_Channel1); \
            condition = QUOTE(Intercom_Condition(0)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,0,true)];); \
        }; \
        class TFAR_IntercomChannel_2 { \
            displayName = CSTRING(Intercom_ACESelfAction_Channel2); \
            condition = QUOTE(Intercom_Condition(1)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,1,true)];); \
        }; \
        class TFAR_IntercomChannel_Misc_1 { \
            displayName = "Misc channel 1"; \
            condition = QUOTE(Intercom_Condition(2)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,2,true)];); \
        }; \
        class TFAR_IntercomChannel_Misc_2 { \
            displayName = "Misc channel 2"; \
            condition = QUOTE(Intercom_Condition(3)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,3,true)];); \
        }; \
        class TFAR_IntercomChannel_Misc_3 { \
            displayName = "Misc channel 3"; \
            condition = QUOTE(Intercom_Condition(4)); \
            statement = QUOTE((vehicle ACE_Player) setVariable [ARR_3(Intercom_Variable,4,true)];); \
        }; \
    }; \
};

#define MACRO_VEC_ISOLATION_LR_Intercom(veeeeehicle,baseClass,isolation,hasLR,intercom) class veeeeehicle : baseClass { \
    tf_hasLRradio = hasLR; \
    tf_isolatedAmount = isolation; \
    TFAR_hasIntercom = intercom; \
    IntercomMacro \
}