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


int main()
{
	kcg_real I1_status;
	kcg_real I1_value;
	kcg_real I2_status;
	kcg_real I2_value;
	kcg_int SIGN;
	kcg_real O1_status;
	kcg_real O1_value;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&I2_status, sizeof(I2_status), "I2_status");
	klee_make_symbolic(&I2_value, sizeof(I2_value), "I2_value");
	klee_make_symbolic(&SIGN, sizeof(SIGN), "SIGN");
	klee_make_symbolic(&O1_status, sizeof(O1_status), "O1_status");
	klee_make_symbolic(&O1_value, sizeof(O1_value), "O1_value");
	FORCE_L_A_POL_TIME_DEPENDENT_analog_SE(I1_status, I1_value, I2_status, I2_value, SIGN, O1_status, O1_value);
	return 0;
}