#include"dcs_se.h"

void ABS_ANA_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_real I1_value, kcg_bool O1_status, kcg_real O1_value)
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

void DFL_POL_TIME_DEPENDENT_binary_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool outC_O1_status, kcg_bool outC_O1_value,
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


void FSF_POL_TIME_DEPENDENT_analog_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_real I2_value, kcg_bool O1_status, kcg_real O1_value)
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

void THC_ANA_TIME_DEPENDENT_SE(
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
	_4_SSM_ST_SM1 SM1_state_sel;
	_4_SSM_ST_SM1 SM1_state_act;
	if (outC_init)
	{
		SM1_state_sel = _3_SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_sel = outC_SM1_state_nxt;
	}
	switch (SM1_state_sel)
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

void FORCE_L_B_POL_TIME_DEPENDENT_binary_SE(kcg_bool I1_status, kcg_bool I1_value,
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


void FORCE_L_A_POL_TIME_DEPENDENT_analog_SE(kcg_real I1_status, kcg_real I1_value, kcg_real I2_status, kcg_real I2_value, kcg_int SIGN, kcg_real O1_status, kcg_real O1_value)
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

void NOT_BIN_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool O1_status, kcg_bool O1_value)
{
	O1_value = !I1_value;
	O1_status = I1_status;
}

void BSO_BIN_TIME_INDEPENDENT_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool B1_status, kcg_bool B1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool B2_status, kcg_bool B2_value, kcg_bool O1_status, kcg_bool O1_value)
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


void AND2_BIN_TIME_INDEPENDENT_AND_SE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool I2_status, kcg_bool I2_value, kcg_bool O1_status, kcg_bool O1_value)
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



