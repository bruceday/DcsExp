#include"dcs.h"

void ABS_ANA_TIME_INDEPENDENT(analog *I1, analog *O1) {
	if (0.0 > (*I1).value) {
		(*O1).value = -(*I1).value;

	}
	else {
		(*O1).value = (*I1).value;

	}
	if ((*I1).status) {
		(*O1).status = FAULT;
	}
	else {
		(*O1).status = NO_FAULT;
	}
}

void AND2_BIN_TIME_INDEPENDENT_AND(binary *I1, binary *I2, binary *O1) {
	(*O1).value = (*I1).value & (*I2).value;
	if ((*I1).status | (*I2).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void BSO_BIN_TIME_INDEPENDENT(binary *I1, binary *B1, binary *I2, binary *B2, binary *O1) {

	if (!(*I1).value | ((*I1).value & (*I2).value)) {
		kcg_copy_binary(O1, B1);
	}
	else {
		kcg_copy_binary(O1, B2);
	}
}

void DFL_init_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC) {

	outC->init = kcg_true;
	outC->_L24 = kcg_true;
	outC->O2.value = kcg_true;
	outC->O2.status = kcg_true;
	outC->O1.value = kcg_true;
	outC->O1.status = kcg_true;
}

void DFL_reset_POL_TIME_DEPENDENT_binary(outC_DFL_POL_TIME_DEPENDENT_binary *outC) {

	outC->init = kcg_true;

}


void DFL_POL_TIME_DEPENDENT_binary(binary *I1, outC_DFL_POL_TIME_DEPENDENT_binary *outC) {

	outC->O1.status = NO_FAULT;
	outC->O2.status = NO_FAULT;
	if ((*I1).status)
	{
		if (outC->init)
		{
			outC->_L24 = VALUE_0;
		}
	}
	else
	{
		outC->_L24 = (*I1).value;
	}
	outC->O1.value = outC->O2.value;
	if ((*I1).status)
	{
		outC->O2.value = VALUE_1;
	}
	else
	{
		outC->O2.value = VALUE_0;
	}
	outC->init = kcg_false;
}

void DIV_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *O1) {
	analog _L17;
	kcg_real _L35;
	kcg_real _L51;

	ABS_ANA_TIME_INDEPENDENT(I2, &_L17);
	_L35 = -MAXFLOAT;
	if (_L17.value == 0.0)
	{
		_L51 = MAXFLOAT;
	}
	else if (_L17.value < MAXFLOAT)
	{
		_L51 = MAXFLOAT * (*I1).value;
	}
	else
	{
		_L51 = (*I1).value / (*I2).value;
	}
	if (_L51 > MAXFLOAT)
	{
		if (_L51 > MAXFLOAT)
			(*O1).value = MAXFLOAT;
	}
	else if (_L51 < _L35)
	{
		(*O1).value = _L35;
	}
	else
	{
		(*O1).value = _L51;
	}
	if (!(*I1).status & !(*I2).status & !(0.0 == (*I2).value))
	{
		(*O1).status = NO_FAULT;
	}
	else
	{
		(*O1).status = FAULT;
	}
}

void FORCE_L_A_POL_TIME_DEPENDENT_analog(analog *I1, analog *I2, kcg_int SIGN, analog *O1) {

	switch (SIGN)
	{
	case 1:
		(*O1).value = (*I1).value;
		(*O1).status = (*I2).status;
		break;
	case 2:
		(*O1).value = (*I2).value;
		(*O1).status = (*I1).status;
		break;
	case 3:
		kcg_copy_analog(O1, I2);
		break;
	default:
		kcg_copy_analog(O1, I1);
		break;
	}
}

void FORCE_L_B_POL_TIME_DEPENDENT_binary(binary *I1, binary *I2, kcg_int SIGN, binary *O1) {

	switch (SIGN)
	{
	case 1:
		(*O1).value = (*I1).value;
		(*O1).status = (*I2).status;
		break;
	case 2:
		(*O1).value = (*I2).value;
		(*O1).status = (*I1).status;
		break;
	case 3:
		kcg_copy_binary(O1, I2);
		break;
	default:
		kcg_copy_binary(O1, I1);
		break;
	}
}


void FSF_POL_TIME_DEPENDENT_analog(binary *I1, analog *I2, analog *O1) {

	(*O1).value = (*I2).value;
	if (!(*I2).status | !(*I1).value | (*I1).status)
	{
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void FSF_POL_TIME_DEPENDENT_binary(binary *I1, binary *I2, binary *O1) {

	(*O1).value = (*I2).value;
	if (!(*I2).status | !(*I1).value | (*I1).status)
	{
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void GOC_ANA_TIME_INDEPENDENT(analog *I1, kcg_real OFFSET, kcg_real GAIN, analog *O1) {

	(*O1).value = OFFSET + GAIN * (*I1).value;
	(*O1).status = (*I1).status;
}

void HTI_A_POL_TIME_INDEPENDENT_analog(kcg_real I1, analog *O1) {

	(*O1).value = I1;
	(*O1).status = NO_FAULT;
}

void MTB_SYSLIB(mulriple *I1, binary *O1, binary *O2, binary *O3, binary *O4, binary *O5) {

	array_bool_5 _L6;
	(*O5).status = (*I1).status;
	(*O4).status = (*I1).status;
	(*O3).status = (*I1).status;
	(*O1).status = (*I1).status;
	(*O2).status = (*I1).status;
	switch ((*I1).value)
	{
	case 1:
		_L6[0] = VALUE_1;
		_L6[1] = VALUE_0;
		_L6[2] = VALUE_0;
		_L6[3] = VALUE_0;
		_L6[4] = VALUE_0;
		break;
	case 2:
		_L6[0] = VALUE_0;
		_L6[1] = VALUE_1;
		_L6[2] = VALUE_0;
		_L6[3] = VALUE_0;
		_L6[4] = VALUE_0;
		break;
	case 3:
		_L6[0] = VALUE_0;
		_L6[1] = VALUE_0;
		_L6[2] = VALUE_1;
		_L6[3] = VALUE_0;
		_L6[4] = VALUE_0;
		break;

	case 4:
		_L6[0] = VALUE_0;
		_L6[1] = VALUE_0;
		_L6[2] = VALUE_0;
		_L6[3] = VALUE_1;
		_L6[4] = VALUE_0;
		break;

	case 5:
		_L6[0] = VALUE_0;
		_L6[1] = VALUE_0;
		_L6[2] = VALUE_0;
		_L6[3] = VALUE_0;
		_L6[4] = VALUE_1;
		break;


	default:
		_L6[0] = VALUE_0;
		_L6[1] = VALUE_0;
		_L6[2] = VALUE_0;
		_L6[3] = VALUE_0;
		_L6[4] = VALUE_0;
		break;
	}
	(*O5).value = _L6[4];
	(*O4).value = _L6[3];
	(*O3).value = _L6[2];
	(*O1).value = _L6[0];
	(*O2).value = _L6[1];
}

void MUL2_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *O1) {

	(*O1).value = (*I1).value *(*I2).value;
	if (!(*I1).status & !(*I2).status)
	{
		(*O1).status = NO_FAULT;
	}
	else
	{
		(*O1).status = FAULT;
	}
}
void MUL3_ANA_TIME_INDEPENDENT(analog *I1, analog *I2, analog *I3, analog *O1) {
	analog _L20;
	MUL2_ANA_TIME_INDEPENDENT(I1, I2, &_L20);
	(*O1).value = _L20.value *(*I3).value;
	if (!_L20.status & !(*I3).status)
	{
		(*O1).status = NO_FAULT;
	}
	else
	{
		(*O1).status = FAULT;
	}
}

void NOT_BIN_TIME_INDEPENDENT(binary *I1, binary *O1) {

	(*O1).value = !(*I1).value;
	(*O1).status = (*I1).status;
}

void ODR02_BIN_TIME_INDEPENDENT_ODR(binary *I1, binary *I2, binary *O1) {

	(*O1).value = (*I1).value | (*I2).value;

	if ((*O1).status | (*I2).status)
	{
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void ODR03_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *O1
)
{
	binary _L3;
	ODR02_BIN_TIME_INDEPENDENT_ODR(I1, I2, &_L3);
	(*O1).value = _L3.value | (*I3).value;
	if (_L3.status | (*I3).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void ODR04_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *O1
)
{
	binary _L3;
	ODR03_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, &_L3);
	(*O1).value = _L3.value | (*I4).value;
	if (_L3.status | (*I4).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}


void ODR05_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *O1
)
{
	binary _L3;
	ODR04_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, &_L3);
	(*O1).value = _L3.value | (*I5).value;
	if (_L3.status | (*I5).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}


void ODR06_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *O1
)
{
	binary _L3;
	ODR05_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, I5, &_L3);
	(*O1).value = _L3.value | (*I6).value;
	if (_L3.status | (*I6).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void ODR07_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *O1
)
{
	binary _L3;
	ODR06_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, I5, I6, &_L3);
	(*O1).value = _L3.value | (*I7).value;
	if (_L3.status | (*I7).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void ODR08_BIN_TIME_INDEPENDENT_ODR(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *I4,
	binary *I5,
	binary *I6,
	binary *I7,
	binary *I8,
	binary *O1
)
{
	binary _L3;
	ODR07_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, I5, I6, I7, &_L3);
	(*O1).value = _L3.value | (*I8).value;
	if (_L3.status | (*I8).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void ODR09_BIN_TIME_INDEPENDENT_ODR(
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
)
{
	binary _L3;
	ODR08_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, I5, I6, I7, I8, &_L3);
	(*O1).value = _L3.value | (*I9).value;
	if (_L3.status | (*I9).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}


void ODR010_BIN_TIME_INDEPENDENT_ODR(
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
)
{
	binary _L3;
	ODR09_BIN_TIME_INDEPENDENT_ODR(I1, I2, I3, I4, I5, I6, I7, I8, I9, &_L3);
	(*O1).value = _L3.value | (*I10).value;
	if (_L3.status | (*I10).status) {
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}


void SQR_ANA_TIME_INDEPENDENT(
	analog *I1,
	analog *O1
)
{
	analog tmp;
	ABS_ANA_TIME_INDEPENDENT(I1, &tmp);
	(*O1).value = Sqrt_MathLib(tmp.value);
	if (((*I1).value < 0.0) | (*I1).status)
	{
		(*O1).status = FAULT;
	}
	else
	{
		(*O1).status = NO_FAULT;
	}
}

void SUM02_ANA_TIME_INDEPENDENT_SUM(
	analog *I1,
	analog *I2,
	kcg_real G1,
	kcg_real G2,
	analog *O1
)
{
	(*O1).value = G1 * (*I1).value + G2 * (*I2).value;
	if (!(*I1).status & !(*I2).status)
	{
		(*O1).status = NO_FAULT;
	}
	else
	{
		(*O1).status = FAULT;
	}
}


void THC_init_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT *outC)
{
	outC->init = kcg_true;
	outC->OutputValue = kcg_true;
	outC->SM1_state_nxt = _3_SSM_st_Init_SM1;
	outC->O1.value = kcg_true;
	outC->O1.status = kcg_true;
}

void THC_reset_ANA_TIME_DEPENDENT(outC_THC_ANA_TIME_DEPENDENT *outC)
{
	outC->init = kcg_true;
}

void THC_ANA_TIME_DEPENDENT(
	analog *I1,
	kcg_real SVAL,
	kcg_real HYST,
	outC_THC_ANA_TIME_DEPENDENT *outC
)
{
	_4_SSM_ST_SM1 SM1_state_sel;
	_4_SSM_ST_SM1 SM1_state_act;
	if (outC->init)
	{
		SM1_state_sel = _3_SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_sel = outC->SM1_state_nxt;
	}
	switch (SM1_state_sel)
	{
	case _3_SSM_st_Init_SM1:
		SM1_state_act = _3_SSM_st_Init_SM1;
		break;
	case _2_SSM_st_NO_FAULT_SM1:
		if ((*I1).status) {
			SM1_state_act = _1_SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = _2_SSM_st_NO_FAULT_SM1;
		}
		break;
	case _1_SSM_st_FAULT_SM1:
		if ((*I1).status) {
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
		outC->O1.value = VALUE_0;
		if ((*I1).status) {
			outC->O1.status = FAULT;
		}
		else
		{
			outC->O1.status = NO_FAULT;
		}
		outC->OutputValue = VALUE_0;
		if ((*I1).status) {
			outC->SM1_state_nxt = _1_SSM_st_FAULT_SM1;
		}
		else
		{
			outC->SM1_state_nxt = _2_SSM_st_NO_FAULT_SM1;
		}
		break;
	case _2_SSM_st_NO_FAULT_SM1:
		outC->O1.status = NO_FAULT;
		if ((*I1).value > SVAL) {
			outC->OutputValue = VALUE_1;
		}
		else if ((*I1).value < SVAL - HYST) {
			outC->OutputValue = VALUE_0;
		}
		outC->O1.value = outC->OutputValue;
		outC->SM1_state_nxt = _2_SSM_st_NO_FAULT_SM1;
		break;
	case _1_SSM_st_FAULT_SM1:
		outC->O1.value = outC->OutputValue;
		outC->O1.status = FAULT;
		outC->SM1_state_nxt = _1_SSM_st_FAULT_SM1;
		break;
	}
	outC->init = kcg_false;
}


void TLC_init_ANA_TIME_DEPENDENT(outC_TLC_ANA_TIME_DEPENDENT *outC)
{
	outC->init = kcg_true;
	outC->OutputValue = kcg_true;
	outC->SM1_state_nxt = SSM_st_Init_SM1;
	outC->O1.value = kcg_true;
	outC->O1.status = kcg_true;
}

void TLC_reset_ANA_TIME_DEPENDENT(outC_TLC_ANA_TIME_DEPENDENT *outC)
{
	outC->init = kcg_true;
}

void TLC_ANA_TIME_DEPENDENT(
	analog *I1,
	kcg_real SVAL,
	kcg_real HYST,
	outC_TLC_ANA_TIME_DEPENDENT *outC
)
{
	SSM_ST_SM1 SM1_state_sel;
	SSM_ST_SM1 SM1_state_act;
	if (outC->init)
	{
		SM1_state_sel = SSM_st_Init_SM1;
	}
	else
	{
		SM1_state_sel = outC->SM1_state_nxt;
	}
	switch (SM1_state_sel)
	{
	case SSM_st_Init_SM1:
		SM1_state_act = SSM_st_Init_SM1;
		break;
	case SSM_st_NO_FAULT_SM1:
		if ((*I1).status) {
			SM1_state_act = SSM_st_FAULT_SM1;
		}
		else
		{
			SM1_state_act = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_FAULT_SM1:
		if ((*I1).status) {
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
		outC->O1.value = VALUE_0;
		if ((*I1).status) {
			outC->O1.status = FAULT;
		}
		else
		{
			outC->O1.status = NO_FAULT;
		}
		outC->OutputValue = VALUE_0;
		if ((*I1).status) {
			outC->SM1_state_nxt = SSM_st_FAULT_SM1;
		}
		else
		{
			outC->SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		}
		break;
	case SSM_st_NO_FAULT_SM1:
		outC->O1.status = NO_FAULT;
		if ((*I1).value < SVAL) {
			outC->OutputValue = VALUE_1;
		}
		else if ((*I1).value > SVAL + HYST) {
			outC->OutputValue = VALUE_0;
		}
		outC->O1.value = outC->OutputValue;
		outC->SM1_state_nxt = SSM_st_NO_FAULT_SM1;
		break;
	case SSM_st_FAULT_SM1:
		outC->O1.value = outC->OutputValue;
		outC->O1.status = FAULT;
		outC->SM1_state_nxt = SSM_st_FAULT_SM1;
		break;
	}
	outC->init = kcg_false;
}

void Vote_2_3_RA_BIN_TIME_INDEPENDENT(
	binary *I1,
	binary *I2,
	binary *I3,
	binary *O1
)
{
	kcg_bool _L237;
	kcg_bool _L284;
	kcg_bool _L315;
	kcg_bool _L201;
	kcg_bool _L203;
	kcg_bool _L220;
	VOTE2 Local_NF;
	kcg_int Local_number_NV;
	kcg_int Local_number_NF;
	(*O1).status = NO_FAULT;
	_L315 = !(*I2).value;
	_L201 = !(*I3).status;
	_L220 = !(*I1).status;
	_L203 = !(*I2).status;
	if (_L201&_L220&_L203)
	{
		Local_number_NF = THIRD_INPUT;
	}
	else if ((_L201&_L220&(*I2).status) | (_L201&_L203&(*I1).status) | (_L203&_L220&(*I3).status))
	{
		Local_number_NF = SECOND_INPUT;
	}
	else if ((*I1).status&(*I2).status&(*I3).status)
	{
		Local_number_NF = NO_INPUT;
	}
	else
	{
		Local_number_NF = FIRST_INPUT;
	}
	if (_L201&_L220&(*I2).status) {
		kcg_copy_binary(&Local_NF.I1, I1);
		kcg_copy_binary(&Local_NF.I2, I3);
	}
	else if (_L201&_L203&(*I1).status)
	{
		kcg_copy_binary(&Local_NF.I1, I2);
		kcg_copy_binary(&Local_NF.I2, I3);
	}
	else
	{
		kcg_copy_binary(&Local_NF.I1, I1);
		kcg_copy_binary(&Local_NF.I2, I2);
	}
	_L237 = !(*I1).value;
	_L284 = !(*I3).value;
	if (Local_number_NF == FIRST_INPUT) {
		if ((_L220&(*I1).value) | (_L203&(*I2).value) | (_L201&(*I3).value)) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_INPUT;
		}
	}
	else if (Local_number_NF == SECOND_INPUT) {
		if (Local_NF.I1.value&Local_NF.I2.value) {
			Local_number_NV = SECOND_INPUT;
		}
		else if (Local_NF.I1.value | Local_NF.I2.value) {
			Local_number_NV = FIRST_INPUT;
		}
		else
		{
			Local_number_NV = NO_INPUT;
		}
	}
	else if (Local_number_NF == THIRD_INPUT) {
		if ((*I1).value&(*I2).value&(*I3).value) {
			Local_number_NV = THIRD_INPUT;
		}
		else if ((_L237&(*I2).value&(*I3).value) | ((*I1).value&
			_L315&(*I3).value) | ((*I1).value&_L284&(*I2).value)) {
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
			(*O1).value = VALUE_1;
			break;
		case 0:
			(*O1).value = VALUE_1;
			break;
		default:
			(*O1).value = VALUE_0;
		}
		break;
	case 2:
		switch (Local_number_NV)
		{
		case 1:
			(*O1).value = VALUE_1;
			break;
		case 2:
			(*O1).value = VALUE_1;
			break;
		case 0:
			(*O1).value = VALUE_0;
			break;
		default:
			(*O1).value = VALUE_0;
		}
		break;
	case 3:
		switch (Local_number_NV)
		{
		case 3:
			(*O1).value = VALUE_1;
			break;
		case 2:
			(*O1).value = VALUE_1;
			break;
		case 1:
			(*O1).value = VALUE_0;
			break;
		case 0:
			(*O1).value = VALUE_0;
			break;
		default:
			(*O1).value = VALUE_0;
		}
		break;
	case 0:
		(*O1).value = VALUE_1;
		break;
	default:
		(*O1).value = VALUE_0;
	}
}


void VSB_filter_POL_TIME_INDEPENDENT_binary(
	binary *I1,
	binary *O1,
	binary *O2
)
{
	(*O2).status = NO_FAULT;
	(*O1).value = (*I1).value;
	(*O1).status = NO_FAULT;
	if ((*I1).status) {
		(*O2).value = VALUE_1;
	}
	else
	{
		(*O2).value = VALUE_0;
	}
}


