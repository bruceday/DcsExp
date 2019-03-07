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

void ABS_ANA_TIME_INDEPENDENT_SEE(kcg_bool I1_status, kcg_real I1_value, kcg_bool O1_status, kcg_real O1_value)
{
	if (0.0 > I1_value) {
		O1_value = -I1_value;

	}
	else {
		O1_value = I1_value;

	}
	if (I1_status) {
		O1_status = FAULT;
	}
	else {
		O1_status = NO_FAULT;
	}
}

void DFL_POL_TIME_DEPENDENT_binary_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool outC_O1_status, kcg_bool outC_O1_value,
	kcg_bool outC_O2_status, kcg_bool outC_O2_value, kcg_bool outC_init, kcg_bool outC__L24)
{
	outC_O1_status = NO_FAULT;
	outC_O2_status = NO_FAULT;
	if (I1_status)
	{
		if (outC_init)
		{
			outC__L24 = VALUE_0;
		}
	}
	else
	{
		outC__L24 = I1_value;
	}
	outC_O1_value = outC_O2_value;
	if (I1_status)
	{
		outC_O2_value = VALUE_1;
	}
	else
	{
		outC_O2_value = VALUE_0;
	}
	outC_init = kcg_false;
}


void FSF_POL_TIME_DEPENDENT_analog_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_real I2_value, kcg_bool O1_status, kcg_real O1_value)
{
	O1_value = I2_value;
	if (!I2_status | !I1_value | I1_status)
	{
		O1_status = FAULT;
	}
	else
	{
		O1_status = NO_FAULT;
	}
}

void THC_ANA_TIME_DEPENDENT_SEE(
	kcg_bool I1_status,
	kcg_real I1_value,
	kcg_real SVAL,
	kcg_real HYST,
	kcg_bool outC_O1_status,
	kcg_bool outC_O1_value,
	kcg_bool outC_init,
	_4_SSM_ST_SM1 outC_SM1_state_nxt,
	kcg_bool outC_OutputValue
)
{
	_4_SSM_ST_SM1 SM1_state_SEEl;
	_4_SSM_ST_SM1 SM1_state_act;
	if (outC_init)
	{
		SM1_state_SEEl = _3_SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_SEEl = outC_SM1_state_nxt;
	}
	switch (SM1_state_SEEl)
	{
	case _3_SSM_st_Init_SM1:
		SM1_state_act = _3_SSM_st_Init_SM1;
		break;
	case _2_SSM_st_NO_FAULT_SM1:
		if (I1_status) {
			SM1_state_act = _1_SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = _2_SSM_st_NO_FAULT_SM1;
		}
		break;
	case _1_SSM_st_FAULT_SM1:
		if (I1_status) {
			SM1_state_act = _1_SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = _2_SSM_st_NO_FAULT_SM1;
		}
		break;
	}
	switch (SM1_state_act)
	{
	case _3_SSM_st_Init_SM1:
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
			outC_SM1_state_nxt = _1_SSM_st_FAULT_SM1;
		}
		else
		{
			outC_SM1_state_nxt = _2_SSM_st_NO_FAULT_SM1;
		}
		break;
	case _2_SSM_st_NO_FAULT_SM1:
		outC_O1_status = NO_FAULT;
		if (I1_value > SVAL) {
			outC_OutputValue = VALUE_1;
		}
		else if (I1_value < SVAL - HYST) {
			outC_OutputValue = VALUE_0;
		}
		outC_O1_value = outC_OutputValue;
		outC_SM1_state_nxt = _2_SSM_st_NO_FAULT_SM1;
		break;
	case _1_SSM_st_FAULT_SM1:
		outC_O1_value = outC_OutputValue;
		outC_O1_status = FAULT;
		outC_SM1_state_nxt = _1_SSM_st_FAULT_SM1;
		break;
	}
	outC_init = kcg_false;
}

void FORCE_L_B_POL_TIME_DEPENDENT_binary_SEE(kcg_bool I1_status, kcg_bool I1_value,
	kcg_bool I2_status, kcg_bool I2_value, kcg_int SIGN, kcg_bool O1_status, kcg_bool O1_value)
{
	switch (SIGN)
	{
	case 1:
		O1_value = I1_value;
		O1_status = I2_status;
		break;
	case 2:
		O1_value = I2_value;
		O1_status = I1_status;
		break;
	case 3:
		O1_status = I2_status;
		O1_value = I2_value;
		break;
	default:
		O1_status = I1_status;
		O1_value = I1_value;
		break;
	}
}


void FORCE_L_A_POL_TIME_DEPENDENT_analog_SEE(kcg_real I1_status, kcg_real I1_value, kcg_real I2_status, kcg_real I2_value, kcg_int SIGN, kcg_real O1_status, kcg_real O1_value)
{
	switch (SIGN)
	{
	case 1:
		O1_value = I1_value;
		O1_status = I2_status;
		break;
	case 2:
		O1_value = I2_value;
		O1_status = I1_status;
		break;
	case 3:
		O1_status = I2_status;
		O1_value = I2_value;
		break;
	default:
		O1_status = I1_status;
		O1_value = I1_value;
		break;
	}
}

void NOT_BIN_TIME_INDEPENDENT_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool O1_status, kcg_bool O1_value)
{
	O1_value = !I1_value;
	O1_status = I1_status;
}

void BSO_BIN_TIME_INDEPENDENT_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool B1_status, kcg_bool B1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool B2_status, kcg_bool B2_value, kcg_bool O1_status, kcg_bool O1_value)
{
	if (!I1_value | (I1_value & I2_value)) {
		O1_status = B1_status;
		O1_value = B1_value;
	}
	else {
		O1_status = B2_status;
		O1_value = B2_value;
	}
}

void Vote_2_3_RA_BIN_TIME_INDEPENDENT_SEE(
	kcg_bool I1_status, kcg_bool I1_value,
	kcg_bool I2_status, kcg_bool I2_value,
	kcg_bool I3_status, kcg_bool I3_value,
	kcg_bool O1_status, kcg_bool O1_value
)
{
	kcg_bool _L237;
	kcg_bool _L284;
	kcg_bool _L315;
	kcg_bool _L201;
	kcg_bool _L203;
	kcg_bool _L220;
	kcg_bool Local_NF_VOTE2_I1_status;
	kcg_bool Local_NF_VOTE2_I1_value;
	kcg_bool Local_NF_VOTE2_I2_status;
	kcg_bool Local_NF_VOTE2_I2_value;
	kcg_int Local_number_NV;
	kcg_int Local_number_NF;
	O1_status = NO_FAULT;
	_L315 = !I2_value;
	_L201 = !I3_status;
	_L220 = !I1_status;
	_L203 = !I2_status;
	if (_L201&_L220&_L203)
	{
		Local_number_NF = THIRD_INPUT;
	}
	else if ((_L201&_L220&I2_status) | (_L201&_L203&I1_status) | (_L203&_L220&I3_status))
	{
		Local_number_NF = SECOND_INPUT;
	}
	else if (I1_status&I2_status&I3_status)
	{
		Local_number_NF = NO_INPUT;
	}
	else
	{
		Local_number_NF = FIRST_INPUT;
	}
	if (_L201&_L220&I2_status) {
		Local_NF_VOTE2_I1_status = I1_status;
		Local_NF_VOTE2_I1_value = I1_value;
		Local_NF_VOTE2_I2_status = I3_status;
		Local_NF_VOTE2_I2_value = I3_value;
	}
	else if (_L201&_L203&I1_status)
	{
		Local_NF_VOTE2_I1_status = I1_status;
		Local_NF_VOTE2_I1_value = I1_value;
		Local_NF_VOTE2_I2_status = I3_status;
		Local_NF_VOTE2_I2_value = I3_value;
	}
	else
	{
		Local_NF_VOTE2_I1_status = I1_status;
		Local_NF_VOTE2_I1_value = I1_value;
		Local_NF_VOTE2_I2_status = I2_status;
		Local_NF_VOTE2_I2_value = I2_value;
	}
	_L237 = !I1_value;
	_L284 = !I3_value;
	if (Local_number_NF == FIRST_INPUT) {
		if ((_L220&I1_value) | (_L203&I2_value) | (_L201&I3_value)) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_INPUT;
		}
	}
	else if (Local_number_NF == SECOND_INPUT) {
		if (Local_NF_VOTE2_I1_value&Local_NF_VOTE2_I2_value) {
			Local_number_NV = SECOND_INPUT;
		}
		else if (Local_NF_VOTE2_I1_value | Local_NF_VOTE2_I2_value) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_INPUT;
		}
	}
	else if (Local_number_NF == THIRD_INPUT) {
		if (I1_value&I2_value&I3_value) {
			Local_number_NV = THIRD_INPUT;
		}
		else if ((_L237&I2_value&I3_value) | (I1_value&
			_L315&I3_value) | (I1_value&_L284&I2_value)) {
			Local_number_NV = SECOND_INPUT;
		}
		else if (_L237&_L315&_L284) {
			Local_number_NV = NO_INPUT;
		}
		else
		{
			Local_number_NV = FIRST_INPUT;
		}
	}
	else
	{
		Local_number_NV = NO_INPUT;
	}
	switch (Local_number_NF)
	{
	case 1:
		switch (Local_number_NV)
		{
		case 1:
			O1_value = VALUE_1;
			break;
		case 0:
			O1_value = VALUE_1;
			break;
		default:
			O1_value = VALUE_0;
		}
		break;
	case 2:
		switch (Local_number_NV)
		{
		case 1:
			O1_value = VALUE_1;
			break;
		case 2:
			O1_value = VALUE_1;
			break;
		case 0:
			O1_value = VALUE_0;
			break;
		default:
			O1_value = VALUE_0;
		}
		break;
	case 3:
		switch (Local_number_NV)
		{
		case 3:
			O1_value = VALUE_1;
			break;
		case 2:
			O1_value = VALUE_1;
			break;
		case 1:
			O1_value = VALUE_0;
			break;
		case 0:
			O1_value = VALUE_0;
			break;
		default:
			O1_value = VALUE_0;
		}
		break;
	case 0:
		O1_value = VALUE_1;
		break;
	default:
		O1_value = VALUE_0;
	}
}


void AND2_BIN_TIME_INDEPENDENT_AND_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool O1_status, kcg_bool O1_value)
{
	O1_value = I1_value & I2_value;
	if (I1_status | I2_status) {
		O1_status = FAULT;
	}
	else
	{
		O1_status = NO_FAULT;
	}
}

void TLC_ANA_TIME_DEPENDENT_SEE(
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
	SSM_ST_SM1 SM1_state_SEEl;
	SSM_ST_SM1 SM1_state_act;
	if (outC_init)
	{
		SM1_state_SEEl = SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_SEEl = outC_SM1_state_nxt;
	}
	switch (SM1_state_SEEl)
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





void Operator_SEE(
	kcg_bool tmp6_status,
	kcg_bool tmp6_value,
	kcg_bool tmp5_status,
	kcg_bool tmp5_value,
	kcg_bool tmp4_status,
	kcg_bool tmp4_value,
	kcg_bool inC_H1RRF001MDB_status,
	kcg_bool inC_H1RRF001MDB_value,
	kcg_bool outC_Context_76_O1_status,
	kcg_bool outC_Context_76_O1_value,
	kcg_bool outC_Context_76_O2_status,
	kcg_bool outC_Context_76_O2_value,
	kcg_bool outC_Context_76_init,
	kcg_bool outC_Context_76__L24,
	kcg_bool outC_H1RRF001MDBF_status,
	kcg_bool outC_H1RRF001MDBF_value,
	kcg_bool inC_H1RRF001MDX_status,
	kcg_real inC_H1RRF001MDX_value,
	kcg_bool outC_N1RRFS012N1X14_status,
	kcg_real outC_N1RRFS012N1X14_value,
	kcg_real inC_S1RRF002XUSVAL,
	kcg_real inC_S1RRF002XUHYST,
	kcg_bool outC_Context_46_O1_status,
	kcg_bool outC_Context_46_O1_value,
	kcg_bool outC_Context_46_init,
	_4_SSM_ST_SM1 outC_Context_46_SM1_state_nxt,
	kcg_bool outC_Context_46_OutputValue,
	kcg_bool outC_N1RRF001MDX110_status,
	kcg_bool outC_N1RRF001MDX110_value,
	kcg_bool inC_RRFS012B01_1_forc_status,
	kcg_bool inC_RRFS012B01_1_forc_value,
	kcg_int inC_RRFS012B01_1_b_force,
	kcg_bool RRFS012B01_1_out_status,
	kcg_bool RRFS012B01_1_out_value,
	kcg_bool inC_H1YDA301MPB_status,
	kcg_bool inC_H1YDA301MPB_value,
	kcg_bool outC_Context_74_O1_status,
	kcg_bool outC_Context_74_O1_value,
	kcg_bool outC_Context_74_O2_status,
	kcg_bool outC_Context_74_O2_value,
	kcg_bool outC_Context_74_init,
	kcg_bool outC_Context_74__L24,
	kcg_bool outC_H1YDA301MPBF_status,
	kcg_bool outC_H1YDA301MPBF_value,
	kcg_bool inC_H1YDA301MPX_status,
	kcg_real inC_H1YDA301MPX_value,
	kcg_bool outC_H1KRPF0N3X14_status,
	kcg_real outC_H1KRPF0N3X14_value,
	kcg_real inC_H1KRPF0A01_1_force_status,
	kcg_real inC_H1KRPF0A01_1_force_value,
	kcg_int inC_KRPF0A01_1_b_force,
	kcg_bool outC_KRPF0A01_1_out_status,
	kcg_real outC_KRPF0A01_1_out_value,
	kcg_bool outC_KRPF031B02_1_out_status,
	kcg_real outC_KRPF031B02_1_out_value,
	kcg_bool outC_Context_45_O1_status,
	kcg_bool outC_Context_45_O1_value,
	kcg_bool outC_Context_45_init,
	_4_SSM_ST_SM1 outC_Context_45_SM1_state_nxt,
	kcg_bool outC_Context_45_OutputValue,
	kcg_bool outC_N1KRP186IA_status,
	kcg_bool outC_N1KRP186IA_value,
	kcg_bool inC_S1KRP151XUSVAL,
	kcg_real inC_S1KRP151XUHYS,
	kcg_bool outC_Context_44_O1_status,
	kcg_bool outC_Context_44_O1_value,
	kcg_bool outC_Context_44_init,
	SSM_ST_SM1 outC_Context_44_SM1_state_nxt,
	kcg_bool outC_Context_44_OutputValue,
	kcg_bool outC_N1KRPF031N2X14_status,
	kcg_bool outC_N1KRPF031N2X14_value,
	kcg_real inC_S1KRP151XUHYST,
	kcg_bool outC_Context_43_O1_status,
	kcg_bool outC_Context_43_O1_value,
	kcg_bool outC_Context_43_O1_init,
	SSM_ST_SM1 outC_Context_43_O1_SM1_state_nxt,
	kcg_bool outC_Context_43_O1_OutputValue,
	kcg_bool outC_N1KRPF031N3X14_status,
	kcg_bool outC_N1KRPF031N3X14_value)
{

	DFL_POL_TIME_DEPENDENT_binary_SEE(inC_H1RRF001MDB_status, inC_H1RRF001MDB_value, outC_Context_76_O1_status,
		outC_Context_76_O1_value, outC_Context_76_O2_status, outC_Context_76_O2_value, outC_Context_76_init, outC_Context_76__L24);

	outC_H1RRF001MDBF_status = outC_Context_76_O1_status;
	outC_H1RRF001MDBF_value = outC_Context_76_O1_value;

	FSF_POL_TIME_DEPENDENT_analog_SEE(outC_H1RRF001MDBF_status, outC_H1RRF001MDBF_value,
		inC_H1RRF001MDX_status, inC_H1RRF001MDX_value,
		outC_N1RRFS012N1X14_status, outC_N1RRFS012N1X14_value);

	THC_ANA_TIME_DEPENDENT_SEE(outC_N1RRFS012N1X14_status,
		outC_N1RRFS012N1X14_value,
		inC_S1RRF002XUSVAL, inC_S1RRF002XUHYST,
		outC_Context_46_O1_status,
		outC_Context_46_O1_value,
		outC_Context_46_init,
		outC_Context_46_SM1_state_nxt,
		outC_Context_46_OutputValue);

	outC_N1RRF001MDX110_status = outC_Context_46_O1_status;
	outC_N1RRF001MDX110_value = outC_Context_46_O1_value;

	FORCE_L_B_POL_TIME_DEPENDENT_binary_SEE(outC_H1RRF001MDBF_status,
		outC_H1RRF001MDBF_value,
		inC_RRFS012B01_1_forc_status,
		inC_RRFS012B01_1_forc_value,
		inC_RRFS012B01_1_b_force,
		RRFS012B01_1_out_status,
		RRFS012B01_1_out_value);


	DFL_POL_TIME_DEPENDENT_binary_SEE(inC_H1YDA301MPB_status, inC_H1YDA301MPB_value,
		outC_Context_74_O1_status, outC_Context_74_O1_value,
		outC_Context_74_O2_status, outC_Context_74_O2_value,
		outC_Context_74_init,
		outC_Context_74__L24);

	outC_H1YDA301MPBF_status = outC_Context_74_O1_status;
	outC_H1YDA301MPBF_value = outC_Context_74_O1_value;

	FSF_POL_TIME_DEPENDENT_analog_SEE(outC_H1YDA301MPBF_status, outC_H1YDA301MPBF_value,
		inC_H1YDA301MPX_status,
		inC_H1YDA301MPX_value,
		outC_H1KRPF0N3X14_status,
		outC_H1KRPF0N3X14_value);

	FORCE_L_A_POL_TIME_DEPENDENT_analog_SEE(outC_H1KRPF0N3X14_status,
		outC_H1KRPF0N3X14_value,
		inC_H1KRPF0A01_1_force_status,
		inC_H1KRPF0A01_1_force_value,
		inC_KRPF0A01_1_b_force,
		outC_KRPF0A01_1_out_status,
		outC_KRPF0A01_1_out_value);

	THC_ANA_TIME_DEPENDENT_SEE(outC_KRPF031B02_1_out_status,
		outC_KRPF031B02_1_out_value,
		inC_S1RRF002XUSVAL,
		inC_S1RRF002XUHYST,
		outC_Context_45_O1_status,
		outC_Context_45_O1_value,
		outC_Context_45_init,
		outC_Context_45_SM1_state_nxt,
		outC_Context_45_OutputValue);


	outC_N1KRP186IA_status = outC_Context_45_O1_status;
	outC_N1KRP186IA_value = outC_Context_45_O1_value;

	TLC_ANA_TIME_DEPENDENT_SEE(outC_KRPF0A01_1_out_status,
		outC_KRPF0A01_1_out_value,
		inC_S1KRP151XUSVAL,
		inC_S1KRP151XUHYS,
		outC_Context_44_O1_status,
		outC_Context_44_O1_value,
		outC_Context_44_init,
		outC_Context_44_SM1_state_nxt,
		outC_Context_44_OutputValue);

	outC_N1KRPF031N2X14_status = outC_Context_44_O1_status;
	outC_N1KRPF031N2X14_value = outC_Context_44_O1_value;

	TLC_ANA_TIME_DEPENDENT_SEE(
		outC_KRPF0A01_1_out_status,
		outC_KRPF0A01_1_out_value,
		inC_S1KRP151XUSVAL,
		inC_S1KRP151XUHYST,
		outC_Context_43_O1_status,
		outC_Context_43_O1_value,
		outC_Context_43_O1_init,
		outC_Context_43_O1_SM1_state_nxt,
		outC_Context_43_O1_OutputValue);

	outC_N1KRPF031N3X14_status = outC_Context_43_O1_status;
	outC_N1KRPF031N3X14_value = outC_Context_43_O1_value;
}

int main()
{
	kcg_bool tmp6_status;
	kcg_bool tmp6_value;
	kcg_bool tmp5_status;
	kcg_bool tmp5_value;
	kcg_bool tmp4_status;
	kcg_bool tmp4_value;
	kcg_bool inC_H1RRF001MDB_status;
	kcg_bool inC_H1RRF001MDB_value;
	kcg_bool outC_Context_76_O1_status;
	kcg_bool outC_Context_76_O1_value;
	kcg_bool outC_Context_76_O2_status;
	kcg_bool outC_Context_76_O2_value;
	kcg_bool outC_Context_76_init;
	kcg_bool outC_Context_76__L24;
	kcg_bool outC_H1RRF001MDBF_status;
	kcg_bool outC_H1RRF001MDBF_value;
	kcg_bool inC_H1RRF001MDX_status;
	kcg_real inC_H1RRF001MDX_value;
	kcg_bool outC_N1RRFS012N1X14_status;
	kcg_real outC_N1RRFS012N1X14_value;
	kcg_real inC_S1RRF002XUSVAL;
	kcg_real inC_S1RRF002XUHYST;
	kcg_bool outC_Context_46_O1_status;
	kcg_bool outC_Context_46_O1_value;
	kcg_bool outC_Context_46_init;
	_4_SSM_ST_SM1 outC_Context_46_SM1_state_nxt;
	kcg_bool outC_Context_46_OutputValue;
	kcg_bool outC_N1RRF001MDX110_status;
	kcg_bool outC_N1RRF001MDX110_value;
	kcg_bool inC_RRFS012B01_1_forc_status;
	kcg_bool inC_RRFS012B01_1_forc_value;
	kcg_int inC_RRFS012B01_1_b_force;
	kcg_bool RRFS012B01_1_out_status;
	kcg_bool RRFS012B01_1_out_value;
	kcg_bool inC_H1YDA301MPB_status;
	kcg_bool inC_H1YDA301MPB_value;
	kcg_bool outC_Context_74_O1_status;
	kcg_bool outC_Context_74_O1_value;
	kcg_bool outC_Context_74_O2_status;
	kcg_bool outC_Context_74_O2_value;
	kcg_bool outC_Context_74_init;
	kcg_bool outC_Context_74__L24;
	kcg_bool outC_H1YDA301MPBF_status;
	kcg_bool outC_H1YDA301MPBF_value;
	kcg_bool inC_H1YDA301MPX_status;
	kcg_real inC_H1YDA301MPX_value;
	kcg_bool outC_H1KRPF0N3X14_status;
	kcg_real outC_H1KRPF0N3X14_value;
	kcg_real inC_H1KRPF0A01_1_force_status;
	kcg_real inC_H1KRPF0A01_1_force_value;
	kcg_int inC_KRPF0A01_1_b_force;
	kcg_bool outC_KRPF0A01_1_out_status;
	kcg_real outC_KRPF0A01_1_out_value;
	kcg_bool outC_KRPF031B02_1_out_status;
	kcg_real outC_KRPF031B02_1_out_value;
	kcg_bool outC_Context_45_O1_status;
	kcg_bool outC_Context_45_O1_value;
	kcg_bool outC_Context_45_init;
	_4_SSM_ST_SM1 outC_Context_45_SM1_state_nxt;
	kcg_bool outC_Context_45_OutputValue;
	kcg_bool outC_N1KRP186IA_status;
	kcg_bool outC_N1KRP186IA_value;
	kcg_bool inC_S1KRP151XUSVAL;
	kcg_real inC_S1KRP151XUHYS;
	kcg_bool outC_Context_44_O1_status;
	kcg_bool outC_Context_44_O1_value;
	kcg_bool outC_Context_44_init;
	SSM_ST_SM1 outC_Context_44_SM1_state_nxt;
	kcg_bool outC_Context_44_OutputValue;
	kcg_bool outC_N1KRPF031N2X14_status;
	kcg_bool outC_N1KRPF031N2X14_value;
	kcg_real inC_S1KRP151XUHYST;
	kcg_bool outC_Context_43_O1_status;
	kcg_bool outC_Context_43_O1_value;
	kcg_bool outC_Context_43_O1_init;
	SSM_ST_SM1 outC_Context_43_O1_SM1_state_nxt;
	kcg_bool outC_Context_43_O1_OutputValue;
	kcg_bool outC_N1KRPF031N3X14_status;
	kcg_bool outC_N1KRPF031N3X14_value;

	klee_make_symbolic(&tmp6_status, sizeof(tmp6_status), "tmp6_status");
	klee_make_symbolic(&tmp6_value, sizeof(tmp6_value), "tmp6_value");
	klee_make_symbolic(&tmp5_status, sizeof(tmp5_status), "tmp5_status");
	klee_make_symbolic(&tmp5_value, sizeof(tmp5_value), "tmp5_value");
	klee_make_symbolic(&tmp4_status, sizeof(tmp4_status), "tmp4_status");
	klee_make_symbolic(&tmp4_value, sizeof(tmp4_value), "tmp4_value");
	klee_make_symbolic(&inC_H1RRF001MDB_status, sizeof(inC_H1RRF001MDB_status), "inC_H1RRF001MDB_status");
	klee_make_symbolic(&inC_H1RRF001MDB_value, sizeof(inC_H1RRF001MDB_value), "inC_H1RRF001MDB_value");
	klee_make_symbolic(&outC_Context_76_O1_status, sizeof(outC_Context_76_O1_status), "outC_Context_76_O1_status");
	klee_make_symbolic(&outC_Context_76_O1_value, sizeof(outC_Context_76_O1_value), "outC_Context_76_O1_value");
	klee_make_symbolic(&outC_Context_76_O2_status, sizeof(outC_Context_76_O2_status), "outC_Context_76_O2_status");
	klee_make_symbolic(&outC_Context_76_O2_value, sizeof(outC_Context_76_O2_value), "outC_Context_76_O2_value");
	klee_make_symbolic(&outC_Context_76_init, sizeof(outC_Context_76_init), "outC_Context_76_init");
	klee_make_symbolic(&outC_Context_76__L24, sizeof(outC_Context_76__L24), "outC_Context_76__L24");
	klee_make_symbolic(&outC_H1RRF001MDBF_status, sizeof(outC_H1RRF001MDBF_status), "outC_H1RRF001MDBF_status");
	klee_make_symbolic(&outC_H1RRF001MDBF_value, sizeof(outC_H1RRF001MDBF_value), "outC_H1RRF001MDBF_value");
	klee_make_symbolic(&inC_H1RRF001MDX_status, sizeof(inC_H1RRF001MDX_status), "inC_H1RRF001MDX_status");
	klee_make_symbolic(&inC_H1RRF001MDX_value, sizeof(inC_H1RRF001MDX_value), "inC_H1RRF001MDX_value");
	klee_make_symbolic(&outC_N1RRFS012N1X14_status, sizeof(outC_N1RRFS012N1X14_status), "outC_N1RRFS012N1X14_status");
	klee_make_symbolic(&outC_N1RRFS012N1X14_value, sizeof(outC_N1RRFS012N1X14_value), "outC_N1RRFS012N1X14_value");
	klee_make_symbolic(&inC_S1RRF002XUSVAL, sizeof(inC_S1RRF002XUSVAL), "inC_S1RRF002XUSVAL");
	klee_make_symbolic(&inC_S1RRF002XUHYST, sizeof(inC_S1RRF002XUHYST), "inC_S1RRF002XUHYST");
	klee_make_symbolic(&outC_Context_46_O1_status, sizeof(outC_Context_46_O1_status), "outC_Context_46_O1_status");
	klee_make_symbolic(&outC_Context_46_O1_value, sizeof(outC_Context_46_O1_value), "outC_Context_46_O1_value");
	klee_make_symbolic(&outC_Context_46_init, sizeof(outC_Context_46_init), "outC_Context_46_init");
	klee_make_symbolic(&outC_Context_46_SM1_state_nxt, sizeof(outC_Context_46_SM1_state_nxt), "_4_SSM_ST_SM1 outC_Context_46_SM1_state_nxt");
	klee_make_symbolic(&outC_Context_46_OutputValue, sizeof(outC_Context_46_OutputValue), "outC_Context_46_OutputValue");
	klee_make_symbolic(&outC_N1RRF001MDX110_status, sizeof(outC_N1RRF001MDX110_status), "outC_N1RRF001MDX110_status");
	klee_make_symbolic(&outC_N1RRF001MDX110_value, sizeof(outC_N1RRF001MDX110_value), "outC_N1RRF001MDX110_value");
	klee_make_symbolic(&inC_RRFS012B01_1_forc_status, sizeof(inC_RRFS012B01_1_forc_status), "inC_RRFS012B01_1_forc_status");
	klee_make_symbolic(&inC_RRFS012B01_1_forc_value, sizeof(inC_RRFS012B01_1_forc_value), "inC_RRFS012B01_1_forc_value");
	klee_make_symbolic(&inC_RRFS012B01_1_b_force, sizeof(inC_RRFS012B01_1_b_force), " inC_RRFS012B01_1_b_force");
	klee_make_symbolic(&RRFS012B01_1_out_status, sizeof(RRFS012B01_1_out_status), "RRFS012B01_1_out_status");
	klee_make_symbolic(&RRFS012B01_1_out_value, sizeof(RRFS012B01_1_out_value), "RRFS012B01_1_out_value");
	klee_make_symbolic(&inC_H1YDA301MPB_status, sizeof(inC_H1YDA301MPB_status), "inC_H1YDA301MPB_status");
	klee_make_symbolic(&inC_H1YDA301MPB_value, sizeof(inC_H1YDA301MPB_value), "inC_H1YDA301MPB_value");
	klee_make_symbolic(&outC_Context_74_O1_status, sizeof(outC_Context_74_O1_status), "outC_Context_74_O1_status");
	klee_make_symbolic(&outC_Context_74_O1_value, sizeof(outC_Context_74_O1_value), "outC_Context_74_O1_value");
	klee_make_symbolic(&outC_Context_74_O2_status, sizeof(outC_Context_74_O2_status), "outC_Context_74_O2_status");
	klee_make_symbolic(&outC_Context_74_O2_value, sizeof(outC_Context_74_O2_value), "outC_Context_74_O2_value");
	klee_make_symbolic(&outC_Context_74_init, sizeof(outC_Context_74_init), "outC_Context_74_init");
	klee_make_symbolic(&outC_Context_74__L24, sizeof(outC_Context_74__L24), "outC_Context_74__L24");
	klee_make_symbolic(&outC_H1YDA301MPBF_status, sizeof(outC_H1YDA301MPBF_status), "outC_H1YDA301MPBF_status");
	klee_make_symbolic(&outC_H1YDA301MPBF_value, sizeof(outC_H1YDA301MPBF_value), "outC_H1YDA301MPBF_value");
	klee_make_symbolic(&inC_H1YDA301MPX_status, sizeof(inC_H1YDA301MPX_status), "inC_H1YDA301MPX_status");
	klee_make_symbolic(&inC_H1YDA301MPX_value, sizeof(inC_H1YDA301MPX_value), "inC_H1YDA301MPX_value");
	klee_make_symbolic(&outC_H1KRPF0N3X14_status, sizeof(outC_H1KRPF0N3X14_status), "outC_H1KRPF0N3X14_status");
	klee_make_symbolic(&outC_H1KRPF0N3X14_value, sizeof(outC_H1KRPF0N3X14_value), "outC_H1KRPF0N3X14_value");
	klee_make_symbolic(&inC_H1KRPF0A01_1_force_status, sizeof(inC_H1KRPF0A01_1_force_status), "inC_H1KRPF0A01_1_force_status");
	klee_make_symbolic(&inC_H1KRPF0A01_1_force_value, sizeof(inC_H1KRPF0A01_1_force_value), "inC_H1KRPF0A01_1_force_value");
	klee_make_symbolic(&inC_KRPF0A01_1_b_force, sizeof(inC_KRPF0A01_1_b_force), " inC_KRPF0A01_1_b_force");
	klee_make_symbolic(&outC_KRPF0A01_1_out_status, sizeof(outC_KRPF0A01_1_out_status), "outC_KRPF0A01_1_out_status");
	klee_make_symbolic(&outC_KRPF0A01_1_out_value, sizeof(outC_KRPF0A01_1_out_value), "outC_KRPF0A01_1_out_value");
	klee_make_symbolic(&outC_KRPF031B02_1_out_status, sizeof(outC_KRPF031B02_1_out_status), "outC_KRPF031B02_1_out_status");
	klee_make_symbolic(&outC_KRPF031B02_1_out_value, sizeof(outC_KRPF031B02_1_out_value), "outC_KRPF031B02_1_out_value");
	klee_make_symbolic(&outC_Context_45_O1_status, sizeof(outC_Context_45_O1_status), "outC_Context_45_O1_status");
	klee_make_symbolic(&outC_Context_45_O1_value, sizeof(outC_Context_45_O1_value), "outC_Context_45_O1_value");
	klee_make_symbolic(&outC_Context_45_init, sizeof(outC_Context_45_init), "outC_Context_45_init");
	klee_make_symbolic(&outC_Context_45_SM1_state_nxt, sizeof(outC_Context_45_SM1_state_nxt), "_4_SSM_ST_SM1 outC_Context_45_SM1_state_nxt");
	klee_make_symbolic(&outC_Context_45_OutputValue, sizeof(outC_Context_45_OutputValue), "outC_Context_45_OutputValue");
	klee_make_symbolic(&outC_N1KRP186IA_status, sizeof(outC_N1KRP186IA_status), "outC_N1KRP186IA_status");
	klee_make_symbolic(&outC_N1KRP186IA_value, sizeof(outC_N1KRP186IA_value), "outC_N1KRP186IA_value");
	klee_make_symbolic(&inC_S1KRP151XUSVAL, sizeof(inC_S1KRP151XUSVAL), "inC_S1KRP151XUSVAL");
	klee_make_symbolic(&inC_S1KRP151XUHYS, sizeof(inC_S1KRP151XUHYS), "inC_S1KRP151XUHYS");
	klee_make_symbolic(&outC_Context_44_O1_status, sizeof(outC_Context_44_O1_status), "outC_Context_44_O1_status");
	klee_make_symbolic(&outC_Context_44_O1_value, sizeof(outC_Context_44_O1_value), "outC_Context_44_O1_value");
	klee_make_symbolic(&outC_Context_44_init, sizeof(outC_Context_44_init), "outC_Context_44_init");
	klee_make_symbolic(&outC_Context_44_SM1_state_nxt, sizeof(outC_Context_44_SM1_state_nxt), "SSM_ST_SM1 outC_Context_44_SM1_state_nxt");
	klee_make_symbolic(&outC_Context_44_OutputValue, sizeof(outC_Context_44_OutputValue), "outC_Context_44_OutputValue");
	klee_make_symbolic(&outC_N1KRPF031N2X14_status, sizeof(outC_N1KRPF031N2X14_status), "outC_N1KRPF031N2X14_status");
	klee_make_symbolic(&outC_N1KRPF031N2X14_value, sizeof(outC_N1KRPF031N2X14_value), "outC_N1KRPF031N2X14_value ");
	klee_make_symbolic(&inC_S1KRP151XUHYST, sizeof(inC_S1KRP151XUHYST), "inC_S1KRP151XUHYST");
	klee_make_symbolic(&outC_Context_43_O1_status, sizeof(outC_Context_43_O1_status), "outC_Context_43_O1_status");
	klee_make_symbolic(&outC_Context_43_O1_value, sizeof(outC_Context_43_O1_value), "outC_Context_43_O1_value");
	klee_make_symbolic(&outC_Context_43_O1_init, sizeof(outC_Context_43_O1_init), "outC_Context_43_O1_init");
	klee_make_symbolic(&outC_Context_43_O1_SM1_state_nxt, sizeof(outC_Context_43_O1_SM1_state_nxt), "SSM_ST_SM1 outC_Context_43_O1_SM1_state_nxt");
	klee_make_symbolic(&outC_Context_43_O1_OutputValue, sizeof(outC_Context_43_O1_OutputValue), "outC_Context_43_O1_OutputValue");
	klee_make_symbolic(&outC_N1KRPF031N3X14_status, sizeof(outC_N1KRPF031N3X14_status), "outC_N1KRPF031N3X14_status");
	klee_make_symbolic(&outC_N1KRPF031N3X14_value, sizeof(outC_N1KRPF031N3X14_value), "outC_N1KRPF031N3X14_value");

	Operator_SEE(
		tmp6_status,
		tmp6_value,
		tmp5_status,
		tmp5_value,
		tmp4_status,
		tmp4_value,
		inC_H1RRF001MDB_status,
		inC_H1RRF001MDB_value,
		outC_Context_76_O1_status,
		outC_Context_76_O1_value,
		outC_Context_76_O2_status,
		outC_Context_76_O2_value,
		outC_Context_76_init,
		outC_Context_76__L24,
		outC_H1RRF001MDBF_status,
		outC_H1RRF001MDBF_value,
		inC_H1RRF001MDX_status,
		inC_H1RRF001MDX_value,
		outC_N1RRFS012N1X14_status,
		outC_N1RRFS012N1X14_value,
		inC_S1RRF002XUSVAL,
		inC_S1RRF002XUHYST,
		outC_Context_46_O1_status,
		outC_Context_46_O1_value,
		outC_Context_46_init,
		outC_Context_46_SM1_state_nxt,
		outC_Context_46_OutputValue,
		outC_N1RRF001MDX110_status,
		outC_N1RRF001MDX110_value,
		inC_RRFS012B01_1_forc_status,
		inC_RRFS012B01_1_forc_value,
		inC_RRFS012B01_1_b_force,
		RRFS012B01_1_out_status,
		RRFS012B01_1_out_value,
		inC_H1YDA301MPB_status,
		inC_H1YDA301MPB_value,
		outC_Context_74_O1_status,
		outC_Context_74_O1_value,
		outC_Context_74_O2_status,
		outC_Context_74_O2_value,
		outC_Context_74_init,
		outC_Context_74__L24,
		outC_H1YDA301MPBF_status,
		outC_H1YDA301MPBF_value,
		inC_H1YDA301MPX_status,
		inC_H1YDA301MPX_value,
		outC_H1KRPF0N3X14_status,
		outC_H1KRPF0N3X14_value,
		inC_H1KRPF0A01_1_force_status,
		inC_H1KRPF0A01_1_force_value,
		inC_KRPF0A01_1_b_force,
		outC_KRPF0A01_1_out_status,
		outC_KRPF0A01_1_out_value,
		outC_KRPF031B02_1_out_status,
		outC_KRPF031B02_1_out_value,
		outC_Context_45_O1_status,
		outC_Context_45_O1_value,
		outC_Context_45_init,
		outC_Context_45_SM1_state_nxt,
		outC_Context_45_OutputValue,
		outC_N1KRP186IA_status,
		outC_N1KRP186IA_value,
		inC_S1KRP151XUSVAL,
		inC_S1KRP151XUHYS,
		outC_Context_44_O1_status,
		outC_Context_44_O1_value,
		outC_Context_44_init,
		outC_Context_44_SM1_state_nxt,
		outC_Context_44_OutputValue,
		outC_N1KRPF031N2X14_status,
		outC_N1KRPF031N2X14_value,
		inC_S1KRP151XUHYST,
		outC_Context_43_O1_status,
		outC_Context_43_O1_value,
		outC_Context_43_O1_init,
		outC_Context_43_O1_SM1_state_nxt,
		outC_Context_43_O1_OutputValue,
		outC_N1KRPF031N3X14_status,
		outC_N1KRPF031N3X14_value);
	return 0;
}
