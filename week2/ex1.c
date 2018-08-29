#include <stdio.h>

#include <limits.h>

#include <float.h>


int main(void) {

	int intmax;

	float fltmax;

	double dblmax;

	intmax = INT_MAX;

	fltmax = FLT_MAX;

	dblmax = DBL_MAX;

	

	printf("%d\n", intmax);

	printf("%f\n", fltmax);

	printf("%f\n", dblmax);


	

	printf("%d\n", (int)sizeof(intmax));

	printf("%d\n", (int)sizeof(fltmax));

	printf("%d\n", (int)sizeof(dblmax));

	return 0;

}
