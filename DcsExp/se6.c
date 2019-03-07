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




void NOT_BIN_TIME_INDEPENDENT_SEE(kcg_bool I1_status, kcg_bool I1_value, kcg_bool O1_status, kcg_bool O1_value)
{
	O1_value = !I1_value;
	O1_status = I1_status;
}


void Operator_SEE(
	kcg_bool outC_H1RRF001MDBF_status, 
	kcg_real outC_H1RRF001MDBF_value,
	kcg_bool inC_H1RRF001MDX_status,
	kcg_real  inC_H1RRF001MDX_value,
	kcg_bool outC_N1RRFS012N1X14_status, 
	kcg_real outC_N1RRFS012N1X14_value,
	kcg_bool outC_N1KRP091KS_status, 
	kcg_bool outC_N1KRP091KS_value,
	kcg_bool inC_RRFS012B01_1_forc_status,
	kcg_bool inC_RRFS012B01_1_forc_value,
	kcg_bool inC_RRFS012B01_1_b_force,
	kcg_bool RRFS012B01_1_out_status,
	kcg_bool RRFS012B01_1_out_value,
	kcg_bool inC_H1YDA301MPB_status,
	kcg_bool inC_H1YDA301MPB_value,
	kcg_bool outC_Context_74_O1_status,
	kcg_bool outC_Context_74_O1_value,
	kcg_bool outC_Context_74_O2_status, 
	kcg_bool outC_Context_74_O2_value,
	kcg_bool outC_Context_74_init,
	kcg_bool outC_Context_74__L24
)
{

	DFL_POL_TIME_DEPENDENT_binary_SEE(inC_H1YDA301MPB_status, inC_H1YDA301MPB_value,
		outC_Context_74_O1_status, outC_Context_74_O1_value,
		outC_Context_74_O2_status, outC_Context_74_O2_value,
		outC_Context_74_init,
		outC_Context_74__L24);

	FSF_POL_TIME_DEPENDENT_analog_SEE(outC_Context_74_O1_status, outC_Context_74_O1_value,
		inC_H1RRF001MDX_status, inC_H1RRF001MDX_value,
		outC_N1RRFS012N1X14_status, outC_N1RRFS012N1X14_value);	

	FORCE_L_B_POL_TIME_DEPENDENT_binary_SEE(outC_N1RRFS012N1X14_status,
		outC_N1RRFS012N1X14_value,
		inC_RRFS012B01_1_forc_status,
		inC_RRFS012B01_1_forc_value,
		inC_RRFS012B01_1_b_force,
		RRFS012B01_1_out_status,
		RRFS012B01_1_out_value);

	FORCE_L_B_POL_TIME_DEPENDENT_binary_SEE(RRFS012B01_1_out_status,
		RRFS012B01_1_out_value,
		inC_RRFS012B01_1_forc_status,
		inC_RRFS012B01_1_forc_value,
		inC_RRFS012B01_1_b_force,
		RRFS012B01_1_out_status,
		RRFS012B01_1_out_value);

	FSF_POL_TIME_DEPENDENT_analog_SEE(RRFS012B01_1_out_status, RRFS012B01_1_out_value,
		inC_H1RRF001MDX_status, inC_H1RRF001MDX_value,
		outC_N1RRFS012N1X14_status, outC_N1RRFS012N1X14_value);

}

int main()
{
	kcg_bool outC_H1RRF001MDBF_status;
	kcg_real outC_H1RRF001MDBF_value;
	kcg_bool inC_H1RRF001MDX_status;
	kcg_real  inC_H1RRF001MDX_value;
	kcg_bool outC_N1RRFS012N1X14_status;
	kcg_real outC_N1RRFS012N1X14_value;
	kcg_bool outC_N1KRP091KS_status;
	kcg_bool outC_N1KRP091KS_value;
	kcg_bool inC_RRFS012B01_1_forc_status;
	kcg_bool inC_RRFS012B01_1_forc_value;
	kcg_bool inC_RRFS012B01_1_b_force;
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

	klee_make_symbolic(&outC_H1RRF001MDBF_status, sizeof(outC_H1RRF001MDBF_status), "outC_H1RRF001MDBF_status");
	klee_make_symbolic(&outC_H1RRF001MDBF_value, sizeof(outC_H1RRF001MDBF_value), "outC_H1RRF001MDBF_value");
	klee_make_symbolic(&inC_H1RRF001MDX_status, sizeof(inC_H1RRF001MDX_status), "inC_H1RRF001MDX_status");
	klee_make_symbolic(&inC_H1RRF001MDX_value, sizeof(inC_H1RRF001MDX_value), "inC_H1RRF001MDX_value");
	klee_make_symbolic(&outC_N1RRFS012N1X14_status, sizeof(outC_N1RRFS012N1X14_status), "outC_N1RRFS012N1X14_status");
	klee_make_symbolic(&outC_N1RRFS012N1X14_value, sizeof(outC_N1RRFS012N1X14_value), "outC_N1RRFS012N1X14_value");
	klee_make_symbolic(&outC_N1KRP091KS_status, sizeof(outC_N1KRP091KS_status), "outC_N1KRP091KS_status");
	klee_make_symbolic(&outC_N1KRP091KS_value, sizeof(outC_N1KRP091KS_value), "outC_N1KRP091KS_value");
	klee_make_symbolic(&inC_RRFS012B01_1_forc_status, sizeof(inC_RRFS012B01_1_forc_status), "inC_RRFS012B01_1_forc_status");
	klee_make_symbolic(&inC_RRFS012B01_1_forc_value, sizeof(inC_RRFS012B01_1_forc_value), "inC_RRFS012B01_1_forc_value");
	klee_make_symbolic(&inC_RRFS012B01_1_b_force, sizeof(inC_RRFS012B01_1_b_force), "inC_RRFS012B01_1_b_force");
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


	

	Operator_SEE(
		outC_H1RRF001MDBF_status,
		outC_H1RRF001MDBF_value,
		inC_H1RRF001MDX_status,
		inC_H1RRF001MDX_value,
		outC_N1RRFS012N1X14_status,
		outC_N1RRFS012N1X14_value,
		outC_N1KRP091KS_status,
		outC_N1KRP091KS_value,
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
		outC_Context_74__L24
	);
	return 0;
}
