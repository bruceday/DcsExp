#include<stdio.h>
#include "klee/klee.h"

#define NO_FAULT 0
#define FAULT 1
#define FOURTH_INPUT 4
#define THIRD_INPUT 3
#define FIRST_INPUT 1
#define NO_INPUT 0
#define SECOND_INPUT 2
#define kcg_bool int
#define kcg_int int
#define VALUE_1 1
#define VALUE_0 0

void Vote_2_4_RA_BIN_TIME_INDEPENDENT(
	kcg_bool I1_status,
	kcg_bool I1_value,
	kcg_bool I2_status,
	kcg_bool I2_value,
	kcg_bool I3_status,
	kcg_bool I3_value,
	kcg_bool I4_status,
	kcg_bool I4_value,
	kcg_bool O1_status,
	kcg_bool O1_value
)
{
	kcg_bool tmp;
	kcg_int Local_number_NV;
	kcg_int Local_number_NF;

	kcg_bool _L90_I1_status;
	kcg_bool _L90_I1_value;
	kcg_bool _L90_I2_status;
	kcg_bool _L90_I2_value;
	kcg_bool _L90_I3_status;
	kcg_bool _L90_I3_value;

	kcg_bool _L82_I1_status;
	kcg_bool _L82_I1_value;
	kcg_bool _L82_I2_status;
	kcg_bool _L82_I2_value;
	kcg_bool _L82_I3_status;
	kcg_bool _L82_I3_value;

	kcg_bool _L81_I1_status;
	kcg_bool _L81_I1_value;
	kcg_bool _L81_I2_status;
	kcg_bool _L81_I2_value;
	kcg_bool _L81_I3_status;
	kcg_bool _L81_I3_value;

	kcg_bool _L64_I1_status;
	kcg_bool _L64_I1_value;
	kcg_bool _L64_I2_status;
	kcg_bool _L64_I2_value;
	kcg_bool _L64_I3_status;
	kcg_bool _L64_I3_value;

	kcg_bool _L306;
	kcg_bool _L281;
	kcg_bool _L249;
	kcg_bool _L246;
	kcg_bool _L213;
	kcg_bool _L190;
	kcg_bool _L180;
	kcg_bool _L368;
	kcg_bool _L348;
	kcg_bool _L332;

	O1_status = NO_FAULT;

	_L82_I1_status = I1_status;
	_L82_I1_value = I1_value;
	_L82_I2_status = I2_status;
	_L82_I2_value = I2_value;
	_L82_I3_status = I3_status;
	_L82_I3_value = I3_value;

	_L90_I1_status = I1_status;
	_L90_I1_value = I1_value;
	_L90_I2_status = I2_status;
	_L90_I2_value = I2_value;
	_L90_I3_status = I4_status;
	_L90_I3_value = I4_value;

	_L64_I1_status = I1_status;
	_L64_I1_value = I1_value;
	_L64_I2_status = I3_status;
	_L64_I2_value = I3_value;
	_L64_I3_status = I4_status;
	_L64_I3_value = I4_value;

	_L368 = !I3_status;
	_L332 = !I1_status;
	tmp = !I2_status;
	_L348 = !I4_status;
	if (_L332&tmp&_L368&_L348) {
		Local_number_NF = FOURTH_INPUT;
	}
	else if ((I1_status&tmp&_L368&_L348) | (_L332&_L368&_L348&I2_status) | (_L332&tmp&_L348*I3_status) | (_L332&tmp&_L368&I4_status)) {
		Local_number_NF = THIRD_INPUT;
	}
	else if ((I1_status&I4_status&I3_status&tmp) | (_L332&I2_status&I3_status&I4_status) | (_L368&I1_status&I2_status&I4_status) | (_L348&I1_status&I2_status&I3_status)) {
		Local_number_NF = FIRST_INPUT;
	}
	else if (I1_status&I2_status&I3_status&I4_status) {
		Local_number_NF = NO_INPUT;
	}
	else {
		Local_number_NF = SECOND_INPUT;
	}
	switch (Local_number_NF)
	{
	case 2:
		if (I1_status&I2_status) {
			_L81_I1_status = I3_status;
			_L81_I1_value = I3_value;
			_L81_I2_status = I4_status;
			_L81_I2_value = I4_value;
			_L81_I3_status = I1_status;
			_L81_I3_value = I1_value;
		}
		else if (I1_status&I3_status) {
			_L81_I1_status = I2_status;
			_L81_I1_value = I2_value;
			_L81_I2_status = I4_status;
			_L81_I2_value = I4_value;
			_L81_I3_status = I1_status;
			_L81_I3_value = I1_value;
		}
		else if (I1_status&I4_status) {
			_L81_I1_status = I2_status;
			_L81_I1_value = I2_value;
			_L81_I2_status = I3_status;
			_L81_I2_value = I3_value;
			_L81_I3_status = I1_status;
			_L81_I3_value = I1_value;
		}
		else if (I2_status&I3_status) {
			_L81_I1_status = I1_status;
			_L81_I1_value = I1_value;
			_L81_I2_status = I4_status;
			_L81_I2_value = I4_value;
			_L81_I3_status = I3_status;
			_L81_I3_value = I3_value;
		}
		else if (I2_status&I4_status) {
			_L81_I1_status = _L64_I1_status;
			_L81_I1_value = _L64_I1_value;
			_L81_I2_status = _L64_I2_status;
			_L81_I2_value = _L64_I2_value;
			_L81_I3_status = _L64_I3_status;
			_L81_I3_value = _L64_I3_value;
		}
		else {
			_L81_I1_status = _L90_I1_status;
			_L81_I1_value = _L90_I1_value;
			_L81_I2_status = _L90_I2_status;
			_L81_I2_value = _L90_I2_value;
			_L81_I3_status = _L90_I3_status;
			_L81_I3_value = _L90_I3_value;
		}
		break;
	case 3:
		if (I1_status) {
			_L81_I1_status = I2_status;
			_L81_I1_value = I2_value;
			_L81_I2_status = I3_status;
			_L81_I2_value = I3_value;
			_L81_I3_status = I4_status;
			_L81_I3_value = I4_value;
		}
		else if (I2_status) {
			_L81_I1_status = _L64_I1_status;
			_L81_I1_value = _L64_I1_value;
			_L81_I2_status = _L64_I2_status;
			_L81_I2_value = _L64_I2_value;
			_L81_I3_status = _L64_I3_status;
			_L81_I3_value = _L64_I3_value;
		}
		else if (I3_status) {
			_L81_I1_status = _L90_I1_status;
			_L81_I1_value = _L90_I1_value;
			_L81_I2_status = _L90_I2_status;
			_L81_I2_value = _L90_I2_value;
			_L81_I3_status = _L90_I3_status;
			_L81_I3_value = _L90_I3_value;
		}
		else {
			_L81_I1_status = _L82_I1_status;
			_L81_I1_value = _L82_I1_value;
			_L81_I2_status = _L82_I2_status;
			_L81_I2_value = _L82_I2_value;
			_L81_I3_status = _L82_I3_status;
			_L81_I3_value = _L82_I3_value;
		}
		break;
	case 1:
		_L81_I1_status = _L64_I1_status;
		_L81_I1_value = _L64_I1_value;
		_L81_I2_status = _L64_I2_status;
		_L81_I2_value = _L64_I2_value;
		_L81_I3_status = _L64_I3_status;
		_L81_I3_value = _L64_I3_value;
		break;
	case 4:
		_L81_I1_status = _L64_I1_status;
		_L81_I1_value = _L64_I1_value;
		_L81_I2_status = _L64_I2_status;
		_L81_I2_value = _L64_I2_value;
		_L81_I3_status = _L64_I3_status;
		_L81_I3_value = _L64_I3_value;
		break;
	case 0:
		_L81_I1_status = _L64_I1_status;
		_L81_I1_value = _L64_I1_value;
		_L81_I2_status = _L64_I2_status;
		_L81_I2_value = _L64_I2_value;
		_L81_I3_status = _L64_I3_status;
		_L81_I3_value = _L64_I3_value;
		break;
	default:
		_L81_I1_status = _L64_I1_status;
		_L81_I1_value = _L64_I1_value;
		_L81_I2_status = _L64_I2_status;
		_L81_I2_value = _L64_I2_value;
		_L81_I3_status = _L64_I3_status;
		_L81_I3_value = _L64_I3_value;
		break;
	}

	_L306 = !_L81_I3_value;
	_L281 = !I1_value;
	_L249 = !I4_value;
	_L246 = !_L81_I1_value;
	_L213 = !I2_value;
	_L190 = !_L81_I2_value;
	_L180 = !I3_value;
	if (Local_number_NF == FIRST_INPUT) {
		if ((_L332&I1_value) | (tmp&I2_value) | (_L368&I3_value) |
			(_L348&I4_value)) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_FAULT;
		}
	}
	else if (Local_number_NF == SECOND_INPUT) {
		if (_L81_I1_value&_L81_I2_value) {
			Local_number_NV = SECOND_INPUT;
		}
		else if (_L81_I1_value | _L81_I2_value)
		{
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_INPUT;
		}
	}
	else if (Local_number_NF == THIRD_INPUT) {
		if (_L81_I1_value&_L81_I2_value&_L81_I3_value) {
			Local_number_NV = THIRD_INPUT;
		}
		else if ((_L246&_L81_I2_value&_L81_I3_value) | (_L81_I1_value&_L190&_L81_I3_value) | (_L81_I1_value&_L306&_L81_I2_value))
		{
			Local_number_NV = SECOND_INPUT;
		}
		else if (_L246&_L190&_L306) {
			Local_number_NV = NO_INPUT;
		}
		else
		{
			Local_number_NV = FIRST_INPUT;
		}
	}
	else if (Local_number_NF == FOURTH_INPUT)
	{
		if (_L281&_L213&_L180&_L249) {
			Local_number_NV = NO_INPUT;
		}
		else if (I1_value&I2_value&I3_value&I4_value)
		{
			Local_number_NV = FOURTH_INPUT;
		}
		else if ((_L281&I2_value&I4_value&I3_value) | (I1_value&I4_value&_L213&I3_value) | (I1_value&I2_value&_L180&I4_value) | (I1_value&I2_value&I3_value&_L249))
		{
			Local_number_NV = THIRD_INPUT;
		}
		else if ((_L213&_L180&_L249&I1_value) | (_L281&_L180&_L249&I2_value) | (_L281&_L213&_L249&I3_value) | (_L281&_L213&_L180&I4_value)) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = SECOND_INPUT;
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
			break;
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
			break;
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
			break;
		}
		break;
	case 4:
		switch (Local_number_NV)
		{
		case 4:
			O1_value = VALUE_1;
			break;
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
			break;
		}
		break;
	case 0:
		O1_value = VALUE_1;
		break;
	default:
		O1_value = VALUE_0;
		break;
	}
}


void FORCE_L_B_POL_TIME_INDEPENDENT_binary(
	kcg_bool I1_status,
	kcg_bool I1_value,
	kcg_bool I2_status,
	kcg_bool I2_value,
	kcg_int SIGN,
	kcg_bool O1_status,
	kcg_bool O1_value
)
{
	kcg_int SIGN = 2;
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
	default:
		O1_status = I1_status;
		O1_value = I1_value;
		break;
	}
}

void FSF_POL_TIME_INDEPENDENT_binary(
	kcg_bool I1_status,
	kcg_bool I1_value,
	kcg_bool I2_status,
	kcg_bool I2_value,
	kcg_bool O1_status,
	kcg_bool O1_value
)
{
	O1_value = I2_value;
	if (I2_status | I1_value | I1_status) {
		O1_status = FAULT;
	}
	else
	{
		O1_status = NO_FAULT;
	}
}

void SeExp(
	kcg_bool I1_status,
	kcg_bool I1_value,
	kcg_bool I2_status,
	kcg_bool I2_value,
	kcg_bool I3_status,
	kcg_bool I3_value,
	kcg_bool I4_status,
	kcg_bool I4_value,
	kcg_bool I5_status,
	kcg_bool I5_value,
	kcg_bool I6_status,
	kcg_bool I6_value,
	kcg_bool I7_status,
	kcg_bool I7_value,
	kcg_bool I8_status,
	kcg_bool I8_value,
	kcg_bool I9_status,
	kcg_bool I9_value,
	kcg_bool I10_status,
	kcg_bool I10_value,
	kcg_bool I11_status,
	kcg_bool I11_value,
	kcg_bool O1_status,
	kcg_bool O1_value,
	kcg_bool O2_status,
	kcg_bool O2_value,
	kcg_bool O3_status,
	kcg_bool O3_value,
	kcg_bool O4_status,
	kcg_bool O4_value,
	kcg_bool O5_status,
	kcg_bool O5_value,
	kcg_bool O6_status,
	kcg_bool O6_value,
	kcg_bool O7_status,
	kcg_bool O7_value,
	kcg_bool O8_status,
	kcg_bool O8_value,
	kcg_bool O9_status,
	kcg_bool O9_value,
	kcg_bool O10_status,
	kcg_bool O10_value,
	kcg_bool O11_status,
	kcg_bool O11_value,
	kcg_bool O12_status,
	kcg_bool O12_value,
	kcg_int S1,
	kcg_int S2,
	kcg_int S3
)
{
	FORCE_L_B_POL_TIME_INDEPENDENT_binary(I1_status, I1_value, I2_status, I2_value, S1, O1_status, O1_value);
	Vote_2_4_RA_BIN_TIME_INDEPENDENT(O1_status, O1_value, I3_status, I3_value, I4_status, I4_value, I5_status, I5_value, O2_status, O2_value);
	FSF_POL_TIME_INDEPENDENT_binary(O2_status, O2_value, O3_status, O3_value, O4_status, O4_value);
	FORCE_L_B_POL_TIME_INDEPENDENT_binary(O3_status, O3_value, O4_status, O4_value, S2, O5_status, O5_value);
	Vote_2_4_RA_BIN_TIME_INDEPENDENT(O5_status, O5_value, I6_status, I6_value, I7_status, I7_value, I8_status, I8_value, O6_status, O6_value);
	FSF_POL_TIME_INDEPENDENT_binary(O6_status, O6_value, O7_status, O7_value, O8_status, O8_value);
	FORCE_L_B_POL_TIME_INDEPENDENT_binary(O7_status, O7_value, O8_status, O8_value, S3, O9_status, O9_value);
	Vote_2_4_RA_BIN_TIME_INDEPENDENT(O9_status, O9_value, O9_status, O9_value, I10_status, I10_value, I11_status, I11_value, O10_status, O10_value);
	FSF_POL_TIME_INDEPENDENT_binary(O10_status, O10_value, O11_status, O11_value, O12_status, O12_value);
}

int main()
{
	kcg_bool I1_status;
	kcg_bool I1_value;
	kcg_bool I2_status;
	kcg_bool I2_value;
	kcg_bool I3_status;
	kcg_bool I3_value;
	kcg_bool I4_status;
	kcg_bool I4_value;
	kcg_bool I5_status;
	kcg_bool I5_value;
	kcg_bool I6_status;
	kcg_bool I6_value;
	kcg_bool I7_status;
	kcg_bool I7_value;
	kcg_bool I8_status;
	kcg_bool I8_value;
	kcg_bool I9_status;
	kcg_bool I9_value;
	kcg_bool I10_status;
	kcg_bool I10_value;
	kcg_bool I11_status;
	kcg_bool I11_value;
	kcg_bool O1_status;
	kcg_bool O1_value;
	kcg_bool O2_status;
	kcg_bool O2_value;
	kcg_bool O3_status;
	kcg_bool O3_value;
	kcg_bool O4_status;
	kcg_bool O4_value;
	kcg_bool O5_status;
	kcg_bool O5_value;
	kcg_bool O6_status;
	kcg_bool O6_value;
	kcg_bool O7_status;
	kcg_bool O7_value;
	kcg_bool O8_status;
	kcg_bool O8_value;
	kcg_bool O9_status;
	kcg_bool O9_value;
	kcg_bool O10_status;
	kcg_bool O10_value;
	kcg_bool O11_status;
	kcg_bool O11_value;
	kcg_bool O12_status;
	kcg_bool O12_value;
	kcg_int S1;
	kcg_int S2;
	kcg_int S3;

	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&I2_status, sizeof(I2_status), "I2_status");
	klee_make_symbolic(&I2_value, sizeof(I2_value), "I2_value");
	klee_make_symbolic(&I3_status, sizeof(I3_status), "I3_status");
	klee_make_symbolic(&I3_value, sizeof(I3_value), "I3_value");
	klee_make_symbolic(&I4_status, sizeof(I4_status), "I4_status");
	klee_make_symbolic(&I4_value, sizeof(I4_value), "I4_value");
	klee_make_symbolic(&I5_status, sizeof(I5_status), "I5_status");
	klee_make_symbolic(&I5_value, sizeof(I5_value), "I5_value");
	klee_make_symbolic(&I6_status, sizeof(I6_status), "I6_status");
	klee_make_symbolic(&I6_value, sizeof(I6_value), "I6_value");
	klee_make_symbolic(&I7_status, sizeof(I7_status), "I7_status");
	klee_make_symbolic(&I7_value, sizeof(I7_value), "I7_value");
	klee_make_symbolic(&I8_status, sizeof(I8_status), "I8_status");
	klee_make_symbolic(&I8_value, sizeof(I8_value), "I8_value");
	klee_make_symbolic(&I9_status, sizeof(I9_status), "I9_status");
	klee_make_symbolic(&I9_value, sizeof(I9_value), "I9_value");
	klee_make_symbolic(&I10_status, sizeof(I10_status), "I10_status");
	klee_make_symbolic(&I10_value, sizeof(I10_value), "I10_value");
	klee_make_symbolic(&I11_status, sizeof(I11_status), "I11_status");
	klee_make_symbolic(&I11_value, sizeof(I11_value), "I11_value");
	klee_make_symbolic(&O1_status, sizeof(O1_status), "O1_status");
	klee_make_symbolic(&O1_value, sizeof(O1_value), "O1_value");
	klee_make_symbolic(&O2_status, sizeof(O2_status), "O2_status");
	klee_make_symbolic(&O2_value, sizeof(O2_value), "O2_value");
	klee_make_symbolic(&O3_status, sizeof(O3_status), "O3_status");
	klee_make_symbolic(&O3_value, sizeof(O3_value), "O3_value");
	klee_make_symbolic(&O4_status, sizeof(O4_status), "O4_status");
	klee_make_symbolic(&O4_value, sizeof(O4_value), "O4_value");
	klee_make_symbolic(&O5_status, sizeof(O5_status), "O5_status");
	klee_make_symbolic(&O5_value, sizeof(O5_value), "O5_value");
	klee_make_symbolic(&O6_status, sizeof(O6_status), "O6_status");
	klee_make_symbolic(&O6_value, sizeof(O6_value), "O6_value");
	klee_make_symbolic(&O7_status, sizeof(O7_status), "O7_status");
	klee_make_symbolic(&O7_value, sizeof(O7_value), "O7_value");
	klee_make_symbolic(&O8_status, sizeof(O8_status), "O8_status");
	klee_make_symbolic(&O8_value, sizeof(O8_value), "O8_value");
	klee_make_symbolic(&O9_status, sizeof(O9_status), "O9_status");
	klee_make_symbolic(&O9_value, sizeof(O9_value), "O9_value");
	klee_make_symbolic(&O10_status, sizeof(O10_status), "O10_status");
	klee_make_symbolic(&O10_value, sizeof(O10_value), "O10_value");
	klee_make_symbolic(&O11_status, sizeof(O11_status), "O11_status");
	klee_make_symbolic(&O11_value, sizeof(O11_value), "O11_value");
	klee_make_symbolic(&O12_status, sizeof(O12_status), "O12_status");
	klee_make_symbolic(&O12_value, sizeof(O12_value), "O12_value");
	klee_make_symbolic(&S1, sizeof(S1), "S1");
	klee_make_symbolic(&S2, sizeof(S2), "S2");
	klee_make_symbolic(&S3, sizeof(S3), "S3");

	SeExp(I1_status,
		I1_value,
		I2_status,
		I2_value,
		I3_status,
		I3_value,
		I4_status,
		I4_value,
		I5_status,
		I5_value,
		I6_status,
		I6_value,
		I7_status,
		I7_value,
		I8_status,
		I8_value,
		I9_status,
		I9_value,
		I10_status,
		I10_value,
		I11_status,
		I11_value,
		O1_status,
		O1_value,
		O2_status,
		O2_value,
		O3_status,
		O3_value,
		O4_status,
		O4_value,
		O5_status,
		O5_value,
		O6_status,
		O6_value,
		O7_status,
		O7_value,
		O8_status,
		O8_value,
		O9_status,
		O9_value,
		O10_status,
		O10_value,
		O11_status,
		O11_value,
		O12_status,
		O12_value,
		S1,
		S2,
		S3);

	return 0;
}
