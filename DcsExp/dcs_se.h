typedef int kcg_int;
typedef unsigned char kcg_bool;
typedef int kcg_real;
typedef char kcg_char;
#define kcg_false ((kcg_bool)0)
#define kcg_true ((kcg_bool)1)

#define THIRD_INPUT 3
#define FIRST_INPUT 1
#define NO_INPUT 0
#define SECOND_INPUT 2
#define MINFLOAT 8.5E-37
#define MAXFLOAT 3.3E+38
#define NO_FAULT kcg_false
#define FAULT kcg_true
#define VALUE_0 kcg_false
#define VALUE_1 kcg_true

#define ExpR_MatchLib(In) exp(In)
#define LogR_MathLib(In) log10(In)
#define LnR_MathLib(In) log(In)
#define Sqrt_MathLib(In) sqrt(In)

extern void ABS_ANA_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_real I1_value, kcg_bool O1_status, kcg_real O1_value);

extern void FSF_POL_TIME_DEPENDENT_analog_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_real I2_value, kcg_bool O1_status, kcg_real O1_value);

typedef enum kcg_tag__10_SSM_TR_SM1 {
	_9_SSM_TR_no_trans_SM1,
	_8_SSM_TR_Init_1_SM1,
	_7_SSM_TR_Init_2_SM1,
	_6_SSM_TR_NO_FAULT_1_SM1,
	_5_SSM_TR_FAULT_1_SM1
}_10_SSM_TR_SM1;


typedef enum kcg_tag__4_SSM_ST_SM1 {
	_3_SSM_st_Init_SM1,
	_2_SSM_st_NO_FAULT_SM1,
	_1_SSM_st_FAULT_SM1
}_4_SSM_ST_SM1;

typedef enum kcg_tag_SSM_TR_SM1 {
	SSM_TR_no_trans_SM1,
	SSM_TR_Init_1_SM1,
	SSM_TR_Init_2_SM1,
	SSM_TR_NO_FAULT_1_SM1,
	SSM_TR_FAULT_1_SM1
}SSM_TR_SM1;

typedef enum kcg_tag_SSM_ST_SM1 {
	SSM_st_Init_SM1,
	SSM_st_NO_FAULT_SM1,
	SSM_st_FAULT_SM1
}SSM_ST_SM1;

void THC_ANA_TIME_DEPENDENT_SE(
	kcg_bool I1_status,
	kcg_real I1_value,
	kcg_real SVAL,
	kcg_real HYST,
	kcg_bool outC_O1_status,
	kcg_bool outC_O1_value,
	kcg_bool outC_init,
	_4_SSM_ST_SM1 SM1_state_nxt,
	kcg_bool OutputValue
);

void FORCE_L_B_POL_TIME_DEPENDENT_binary_SE(kcg_bool I1_status, kcg_bool I1_value,
	kcg_bool I2_status, kcg_bool I2_value, kcg_int SIGN, kcg_bool O1_status, kcg_bool O1_value);

void DFL_POL_TIME_DEPENDENT_binary_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool outC_O1_status,
	kcg_bool outC_O1_value,
	kcg_bool outC_O2_status,
	kcg_bool outC_O2_value,
	kcg_bool outC_init,
	kcg_bool outC__L24);

void FORCE_L_A_POL_TIME_DEPENDENT_analog_SE(kcg_real I1_status, kcg_real I1_value, kcg_real I2_status, kcg_real I2_value, kcg_int SIGN, kcg_real O1_status, kcg_real O1_value);

void NOT_BIN_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool O1_status, kcg_bool O1_value);

void BSO_BIN_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool B1_status, kcg_bool B1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool B2_status, kcg_bool B2_value, kcg_bool O1_status, kcg_bool O1_value);

void Vote_2_3_RA_BIN_TIME_INDEPENDENT_SE(
	kcg_bool I1_status, kcg_bool I1_value,
	kcg_bool I2_status, kcg_bool I2_value,
	kcg_bool I3_status, kcg_bool I3_value,
	kcg_bool O1_status, kcg_bool O1_value
);

void AND2_BIN_TIME_INDEPENDENT_AND_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool O1_status, kcg_bool O1_value);

void TLC_ANA_TIME_DEPENDENT_SE(
	kcg_bool I1_status,
	kcg_real I1_value,
	kcg_real SVAL,
	kcg_real HYST,
	kcg_bool O1_status,
	kcg_bool O1_value,
	kcg_bool O1_init,
	SSM_ST_SM1 SM1_state_nxt,
	kcg_bool OutputValue
);




