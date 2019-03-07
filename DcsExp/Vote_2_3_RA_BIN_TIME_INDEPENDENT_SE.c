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

void Vote_2_3_RA_BIN_TIME_INDEPENDENT_SE(
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

int main()
{
	kcg_bool I1_status;
	kcg_bool I1_value;
	kcg_bool I2_status;
	kcg_bool I2_value;
	kcg_bool I3_status;
	kcg_bool I3_value;
	kcg_bool O1_status; 
	kcg_bool O1_value;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&I2_status, sizeof(I2_status), "I2_status");
	klee_make_symbolic(&I2_value, sizeof(I2_value), "I2_value");
	klee_make_symbolic(&I3_status, sizeof(I3_status), "I3_status");
	klee_make_symbolic(&I3_value, sizeof(I3_value), "I3_value");
	klee_make_symbolic(&O1_status, sizeof(O1_status), "O1_status");
	klee_make_symbolic(&O1_value, sizeof(O1_value), "O1_value");
	Vote_2_3_RA_BIN_TIME_INDEPENDENT_SE(
		I1_status, I1_value,
	    I2_status, I2_value,
		I3_status, I3_value,
		O1_status, O1_value
	);
	return 0;
}