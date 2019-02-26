typedef int kcg_int;
typedef unsigned char kcg_bool;
typedef float kcg_real;
typedef char kcg_char;
#define kcg_false ((kcg_bool)0)
#define kcg_true ((kcg_bool)1)

typedef struct kcg_tag_analog { kcg_real value; kcg_bool status; }analog;
typedef struct kcg_tag_binary { kcg_bool value; kcg_bool status; }binary;
typedef struct kcg_tag_mulriple { kcg_int value; kcg_bool status; }mulriple;
typedef struct kcg_ta_VOTE2 { binary I1; binary I2; }VOTE2;

#define kcg_copy_VOTE2(kcg_C1,kcg_C2)(kcg_assign_struct((kcg_C1),(kcg_C2),sizeof(VOTE2)))
typedef kcg_bool array_bool_5[5];

#ifndef  kcg_assign
#include "string.h"
#define kcg_assign(kcg_C1,kcg_C2,kcg_size)(memcpy((kcg_C1),(kcg_C2),(kcg_size)))
#endif // ! kcg_assign

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif // !kcg_assign_struct

#ifndef kcg_copy_binary
#define kcg_copy_binary(kcg_C1,kcg_C2)(kcg_assign_struct((kcg_C1),(kcg_C2),sizeof(binary)))
#endif // !kcg_copy_binary

#ifndef kcg_copy_analog
#define kcg_copy_analog(kcg_C1,kcg_C2)(kcg_assign_struct((kcg_C1),(kcg_C2),sizeof(analog)))
#endif // !kcg_copy_analog

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

extern void ABS_ANA_TIME_INDEPENDENT(analog *I1, analog *O1);

extern void AND2_BIN_TIME_INDEPENDENT_AND(binary *I1, binary *I2, binary *O1);

extern void BSO_BIN_TIME_INDEPENDENT(binary *I1, binary *B1, binary *I2, binary *B2, binary *O1);

typedef struct {
	binary O1;
	binary O2;
	kcg_bool init;
	kcg_bool _L24;
}outC_DFL_POL_TIME_DEPENDENT_binary;

extern void DFL_init_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC);

extern void DFL_reset_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC);

extern void DFL_POL_TIME_DEPENDENT_binary(binary *I1, outC_DFL_POL_TIME_DEPENDENT_binary *outC);
extern void DIV_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *O1);

extern void FORCE_L_A_POL_TIME_DEPENDENT_analog(analog *I1, analog *I2, kcg_int SIGN, analog *O1);

extern void FORCE_L_B_POL_TIME_DEPENDENT_binary(binary *I1, binary *I2, kcg_int SIGN, binary *O1);


extern void FSF_POL_TIME_DEPENDENT_analog(binary *I1, analog *I2, analog *O1);

extern void FSF_POL_TIME_DEPENDENT_binary(binary *I1, binary *I2, binary *O1);

extern void GOC_ANA_TIME_INDEPENDENT(analog *I1, kcg_real OFFSET, kcg_real GAIN, analog *O1);

extern void HTI_A_POL_TIME_INDEPENDENT_analog(kcg_real I1, analog *O1);

extern void MTB_SYSLIB(mulriple *I1, binary *O1, binary *O2, binary *O3, binary *O4, binary *O5);
extern void MUL2_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *O1);
extern void MUL3_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *I3, analog *O1);

extern void NOT_BIN_TIME_INDEPENDENT(binary *I1, binary *O1);

extern void ODR02_BIN_TIME_INDEPENDENT_ODR(binary *I1, binary *I2, binary *O1);


extern void ODR03_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *O1
);

extern void ODR04_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *O1
);


extern void ODR05_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *O1
);


extern void ODR06_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *O1
);

extern void ODR07_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *O1
);

extern void ODR08_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *I8,
	binary *O1
);

extern void ODR09_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *I8,
	binary *I9,
	binary *O1
);


extern void ODR010_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *I8,
	binary *I9,
	binary *I10,
	binary *O1
);


extern void SQR_ANA_TIME_INDEPENDENT(
	analog *I1,
	analog *O1
);

extern void SUM02_ANA_TIME_INDEPENDENT_SUM(
	analog *I1,
	analog *I2,
	kcg_real G1,
	kcg_real G2,
	analog *O1
);


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

typedef struct {
	binary O1;
	kcg_bool init;
	_4_SSM_ST_SM1 SM1_state_nxt;
	kcg_bool OutputValue;
}outC_THC_ANA_TIME_DEPENDENT;

extern void THC_init_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT *outC);

extern void THC_reset_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT *outC);

extern void THC_ANA_TIME_DEPENDENT(
	analog *I1,
	kcg_real SVAL,
	kcg_real HYST,
	outC_THC_ANA_TIME_DEPENDENT *outC
);


typedef struct {
	binary O1;
	kcg_bool init;
	SSM_ST_SM1 SM1_state_nxt;
	kcg_bool OutputValue;
}outC_TLC_ANA_TIME_DEPENDENT;


extern void TLC_init_ANA_TIME_DEPENDENT(outC_TLC_ANA_TIME_DEPENDENT *outC);

extern void TLC_reset_ANA_TIME_DEPENDENT(outC_TLC_ANA_TIME_DEPENDENT *outC);

extern void TLC_ANA_TIME_DEPENDENT(
	analog *I1,
	kcg_real SVAL,
	kcg_real HYST,
	outC_TLC_ANA_TIME_DEPENDENT *outC
);

extern void Vote_2_3_RA_BIN_TIME_INDEPENDENT(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *O1
);


extern void VSB_filter_POL_TIME_INDEPENDENT_binary(
	binary *I1,
	binary *O1,
	binary *O2
);


typedef struct inC_Operator {
	binary N1KRPF031N4X12_NO1;
	kcg_int KRPF030A01_1_b_force;
	binary H1UHA013SY1B;
	binary H1UHA013SY1X;
	binary KRPF010CB02_1_force;
	binary KRPD010CB02_1_b_force;
	binary N1KRPF010CN13X21_N01;
	binary N1KRPF010CN13X21_NO2;
	binary N1KRPF010CN13X31_N01;
	binary N1KRPF010CN13X31_N02;
	binary KRPF010GB02_1_force;
	binary KRPF010GB02_1_b_force;
	binary H1UHA014SY1B;
	binary H1UHA014SY1BF;
	binary _17_Context_45;
	binary H1UHA014SY1X;
	binary N1KRP100KS;
	binary KRPF010DB02_1_force;
	binary KRPF010DB02_1_b_force;
	binary KRPF010DB02_1_out;
	binary KCS501B01_1_out;
	binary N1KRPF010DN14X21_NO1;
	binary KCS501B02_1_out;
	binary N1KRPF010DN14X21_NO2;
	binary N1KRPF010DN21X31_NO1;
	binary N1KRPF010DN21X31_NO2;
	binary KRPF010CB02_1_out;
	binary KRPF010GB02_1_out;
	binary H1RRF001MDB;
	analog H1RRF001MDX;
	analog N1RRFS012N1X14;
	kcg_real S1RRF002XUSVAL;
	binary RRFS012B01_1_force;
	kcg_int RRFS012B01_1_b_force;
	binary H1YDA301MPB;
	analog H1YDA301MPX;
	analog H1KRPF030A01_1_force;
	binary H1KRPF030A01_b_force;
	binary S1KRP155XUSVAL;
	kcg_real S1KRP155XUHYST;
	binary S1KRP157XUSVAL;
	binary S1KRP157XUHYST;
	binary SYS_CARDERR_202_1;
	binary KCS501B01_1_force;
	binary RRFS01B01_1_b_force;
	binary SYS_CARDERR_202_2;
	binary KCS501B02_1_force;
	binary RRFS01B02_1_b_force;
	kcg_real S1KRP154XUHSVAL;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_73;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_76;
	kcg_real S1RRF002XUHYST;
	outC_THC_ANA_TIME_DEPENDENT Context_46;
	binary H1RRF001MDX110;
	binary RRFS012B01_1_out;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_74;
	binary H1YDA301MPBF;
	analog H1KRPF030N3X14;
	analog KRPF030A01_1_out;
	binary Context_45;
	binary N1KRPF031N2X14;
	binary Context_44;
	outC_TLC_ANA_TIME_DEPENDENT Context_43;
	binary N1KRPF031N3X14;
	binary N1KRPF031N3X12_N_01;
	outC_TLC_ANA_TIME_DEPENDENT Context_42;
	binary H1KRP027CC1;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_75;
	binary N1KRP091KS;
	binary N1KRPF031N8X21_N01;
	binary N1KRPF031N8X21_N02;
	binary N1KRPF031N12X31_N01;
	binary N1KRPF031N12X31_N02;
	binary N1KRPF031N4X21_N01;
	binary KRPF031B01_1_force;
	kcg_int KRPF031B01_1_b_force;
	binary KRPF031B01_1_out;
	outC_THC_ANA_TIME_DEPENDENT Context_32;
	binary H1KRP026CC1;
	binary N1KRP088KS;
	binary N1KRPF030N4X21_N01;
	binary N1KRPF030N4X21_N02;
	binary N1KRPF030N6X31_N01;
	binary N1KRPF030N6X31_N02;
	binary N1KRPF030N2X12_N01;
	binary N1KRPF030N7X14;
	binary S1KRP153XUHSVAL;
	binary S1KRP153XUHYST;
	binary Context_33;
	binary H1YDA101MPBF;
	binary KRPF031B02_1_force;
	binary KRPF031B02_b_1_force;
	analog KRPF031B02_1_out;
	binary Context_72;
	binary H1YDA101MTBF;
	binary H1YDA101MTX;
	binary N1KRPF029N3X14;
	kcg_real S1KRP151XUSVAL;
	kcg_real S1KRP151XUHYST;
	binary Context_31;
	binary N1KRP186IA;
	binary S1KRP152XUSVAL;
	binary S1KRP152XUHYST;
	binary N1KRPF029N2X12_N01;
	binary N1KRPF024CC1;
	binary N1KRPF029N4X21_N01;
	binary N1KRPF029N4X21_N02;
	binary N1KRPF029N6X31_N01;
	binary N1KRPF029N7X14;
	binary KRPF029B02_1_force;
	binary KRPF029B01_b_1_force;
	binary KRPF029B02_1_out;
	binary N1RRF001MDX110;
	binary N1KRPF031N2X12_NO1;
	kcg_int KCS501B01_1_b_force;
}inC_Operator;


typedef struct  outC_Operator {
	outC_DFL_POL_TIME_DEPENDENT_binary _16_Context_44;
	binary H1RRF001MDBF;
	binary H1UHA013SY1BF;
	binary N1KRP099KS;
	binary N1KKP099KS;
	binary KRPF010CB02_1_out;
	binary KCS501B01_1_out;
	binary KCS501B02_1_out;
	outC_DFL_POL_TIME_DEPENDENT_binary _17_Context_45;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_76;
	analog N1RRFS012N1X14;
	binary H1RRF001MDB;
	analog H1RRF001MDX;
	kcg_real S1RRF002XUSVAL;
	binary N1KRPF031N13X14;
	binary RRFS012B01_1_force;
	kcg_int RRFS012B01_1_b_force;
	binary H1YDA301MPB;
	binary H1YDA301MPX;
	analog H1KRPF030A01_1_force;
	binary H1KRPF030A01_b_force;
	binary S1KRP155XUSVAL;
	kcg_real S1KRP155XUHYST;
	binary S1KRP157XUSVAL;
	binary S1KRP157XUHYST;
	binary SYS_CARDERR_202_1;
	binary KCS501B01_1_force;
	binary RRFS01B01_1_b_force;
	binary SYS_CARDERR_202_2;
	binary KCS501B02_1_force;
	binary RRFS01B02_1_b_force;
	kcg_real S1KRP154XUHSVAL;
	kcg_real S1RRF002XUHYST;
	outC_THC_ANA_TIME_DEPENDENT Context_46;
	analog H1RRF001MDX110;
	binary RRFS012B01_1_out;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_74;
	binary H1YDA301MPBF;
	analog H1KRPF030N3X14;
	analog KRPF030A01_1_out;
	outC_THC_ANA_TIME_DEPENDENT Context_45;
	binary N1KRPF031N2X14;
	outC_TLC_ANA_TIME_DEPENDENT Context_44;
	outC_TLC_ANA_TIME_DEPENDENT Context_43;
	binary N1KRPF031N3X14;
	binary N1KRPF031N3X12_N_01;
	outC_TLC_ANA_TIME_DEPENDENT Context_42;
	binary H1KRP027CC1;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_75;
	binary N1KRP091KS;
	binary N1KRPF031N8X21_N01;
	binary N1KRPF031N8X21_N02;
	binary N1KRPF031N12X31_N01;
	binary N1KRPF031N12X31_N02;
	binary N1KRPF031N4X21_N01;
	binary KRPF031B01_1_force;
	kcg_int KRPF031B01_1_b_force;
	binary KRPF031B01_1_out;
	outC_THC_ANA_TIME_DEPENDENT Context_32;
	outC_DFL_POL_TIME_DEPENDENT_binary Context_73;
	binary H1KRP026CC1;
	binary N1KRP088KS;
	binary N1KRPF030N4X21_N01;
	binary N1KRPF030N4X21_N02;
	binary N1KRPF030N6X31_N01;
	binary N1KRPF030N6X31_N02;
	binary N1KRPF030N2X12_N01;
	binary N1KRPF030N7X14;
	binary S1KRP153XUHSVAL;
	binary S1KRP153XUHYST;
	binary Context_33;
	binary H1YDA101MPBF;
	binary KRPF031B02_1_force;
	binary KRPF031B02_b_1_force;
	analog KRPF031B02_1_out;
	binary Context_72;
	binary H1YDA101MTBF;
	binary H1YDA101MTX;
	binary N1KRPF029N3X14;
	kcg_real S1KRP151XUSVAL;
	kcg_real S1KRP151XUHYST;
	binary Context_31;
	binary N1KRP186IA;
	binary S1KRP152XUSVAL;
	binary S1KRP152XUHYST;
	binary N1KRPF029N2X12_N01;
	binary N1KRPF024CC1;
	binary N1KRPF029N4X21_N01;
	binary N1KRPF029N4X21_N02;
	binary N1KRPF029N6X31_N01;
	binary N1KRPF029N7X14;
	binary KRPF029B02_1_force;
	binary KRPF029B01_b_1_force;
	binary KRPF029B02_1_out;
	binary N1RRF001MDX110;
	binary N1KRPF031N2X12_NO1;
	kcg_int KCS501B01_1_b_force;
}outC_Operator;


