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

int main()
{
	kcg_bool I1_status;
	kcg_real I1_value;
	kcg_bool O1_status;
	kcg_real O1_value;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&O1_status, sizeof(O1_status), "O1_status");
	klee_make_symbolic(&O1_value, sizeof(O1_value), "O1_value");
	ABS_ANA_TIME_INDEPENDENT_SEE(I1_status, I1_value, O1_status, O1_value);
	return 0;
}