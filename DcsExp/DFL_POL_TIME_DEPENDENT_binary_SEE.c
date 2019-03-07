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

int main()
{
	kcg_bool I1_status;
	kcg_bool I1_value;
	kcg_bool outC_O1_status;
	kcg_bool outC_O1_value;
	kcg_bool outC_O2_status;
	kcg_bool outC_O2_value;
	kcg_bool outC_init;
	kcg_bool outC__L24;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&outC_O1_status, sizeof(outC_O1_status), "outC_O1_status");
	klee_make_symbolic(&outC_O1_value, sizeof(outC_O1_value), "outC_O1_value");
	klee_make_symbolic(&outC_O2_status, sizeof(outC_O2_status), "outC_O2_status");
	klee_make_symbolic(&outC_O2_value, sizeof(outC_O2_value), "outC_O2_value");
	klee_make_symbolic(&outC_init, sizeof(outC_init), "outC_init");
	klee_make_symbolic(&outC__L24, sizeof(outC__L24), "outC__L24");
	DFL_POL_TIME_DEPENDENT_binary_SEE(I1_status, I1_value, outC_O1_status, outC_O1_value, outC_O2_status, outC_O2_value, outC_init, outC__L24);
	return 0;
}