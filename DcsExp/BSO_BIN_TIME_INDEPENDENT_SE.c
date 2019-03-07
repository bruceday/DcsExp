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

int main()
{
	kcg_bool I1_status;
	kcg_bool I1_value;
	kcg_bool B1_status;
	kcg_bool B1_value;
	kcg_bool I2_status;
	kcg_bool I2_value;
	kcg_bool B2_status;
	kcg_bool B2_value;
	kcg_bool O1_status;
	kcg_bool O1_value;
	klee_make_symbolic(&I1_status, sizeof(I1_status), "I1_status");
	klee_make_symbolic(&I1_value, sizeof(I1_value), "I1_value");
	klee_make_symbolic(&B1_status, sizeof(B1_status), "B1_status");
	klee_make_symbolic(&B1_value, sizeof(B1_value), "B1_value");
	klee_make_symbolic(&I2_status, sizeof(I2_status), "I2_status");
	klee_make_symbolic(&I2_value, sizeof(I2_value), "I2_value");
	klee_make_symbolic(&B2_status, sizeof(B2_status), "B2_status");
	klee_make_symbolic(&B2_value, sizeof(B2_value), "B2_value");
	klee_make_symbolic(&O1_status, sizeof(O1_status), "O1_status");
	klee_make_symbolic(&O1_value, sizeof(O1_value), "O1_value");
	BSO_BIN_TIME_INDEPENDENT_SE(I1_status, I1_value, B1_status, B1_value, I2_status, I2_value, B2_status, B2_value, O1_status, O1_value);
	return 0;
}