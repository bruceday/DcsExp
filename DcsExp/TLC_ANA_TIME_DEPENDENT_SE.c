#include<stdio.h>
#include "klee/klee.h"

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


void TLC_ANA_TIME_DEPENDENT_SE(
	kcg_bool I1_status,
	kcg_real I1_value,
	kcg_real SVAL,
	kcg_real HYST,
	kcg_bool outC_O1_status,
	kcg_bool outC_O1_value,
	kcg_bool outC_init,
	SSM_ST_SM1 outC_SM1_state_nxt,
	kcg_bool outC_OutputValue
)
{
	SSM_ST_SM1 SM1_state_sel;
	SSM_ST_SM1 SM1_state_act;
	if (outC_init)
	{
		SM1_state_sel = SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_sel = outC_SM1_state_nxt;
	}
	switch (SM1_state_sel)
	{
	case SSM_st_Init_SM1:
		SM1_state_act = SSM_st_Init_SM1;
		break;
	case SSM_st_NO_FAULT_SM1:
		if (I1_status) {
			SM1_state_act = SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_FAULT_SM1:
		if (I1_status) {
			SM1_state_act = SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = SSM_st_NO_FAULT_SM1;
		}
		break;
	}
	switch (SM1_state_act)
	{
	case SSM_st_Init_SM1:
		outC_O1_value = VALUE_0;
		if (I1_status) {
			outC_O1_status = FAULT;
		}
		else
		{
			outC_O1_status = NO_FAULT;
		}
		outC_OutputValue = VALUE_0;
		if (I1_status) {
			outC_SM1_state_nxt = SSM_st_FAULT_SM1;
		}
		else
		{
			outC_SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_NO_FAULT_SM1:
		outC_O1_status = NO_FAULT;
		if (I1_value < SVAL) {
			outC_OutputValue = VALUE_1;
		}
		else if (I1_value > SVAL + HYST) {
			outC_OutputValue = VALUE_0;
		}
		outC_O1_value = outC_OutputValue;
		outC_SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		break;
	case SSM_st_FAULT_SM1:
		outC_O1_value = outC_OutputValue;
		outC_O1_status = FAULT;
		outC_SM1_state_nxt = SSM_st_FAULT_SM1;
		break;
	}
	outC_init = kcg_false;
}

int main()
{
	kcg_bool I1_status;
	kcg_real I1_value;
	kcg_real SVAL;
	kcg_real HYST;
	kcg_bool outC_O1_status;
	kcg_bool outC_O1_value;
	kcg_bool outC_init;
	SSM_ST_SM1 outC_SM1_state_nxt;
	kcg_bool outC_OutputValue;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&SVAL, sizeof(SVAL), "SVAL");
	klee_make_symbolic(&HYST, sizeof(HYST), "HYST");
	klee_make_symbolic(&outC_O1_status, sizeof(outC_O1_status), "outC_O1_status");
	klee_make_symbolic(&outC_O1_value, sizeof(outC_O1_value), "outC_O1_value");
	klee_make_symbolic(&outC_init, sizeof(outC_init), "outC_init");
	klee_make_symbolic(&outC_SM1_state_nxt, sizeof(outC_SM1_state_nxt), "outC_SM1_state_nxt");
	klee_make_symbolic(&outC_OutputValue, sizeof(outC_OutputValue), "outC_OutputValuee");
	TLC_ANA_TIME_DEPENDENT_SE(I1_status, I1_value, SVAL, HYST, outC_O1_status, outC_O1_value, outC_init, outC_SM1_state_nxt, outC_OutputValue);
	return 0;
}