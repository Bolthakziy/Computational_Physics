#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double do_Function(double x);
double do_DifferentialFunction(double x);
double do_Newton_Raphson_Method(double xL, double tol);

int main()
{
	int i, NumberOfRoots = 2;
	double tol = 10e-8;
	float xL[] = {0., 2.};

	for (i = 0; i < NumberOfRoots; ++i) {
		printf("%d root = %e\n", i + 1, do_Newton_Raphson_Method(xL[i], tol));
	}

	system("pause");

	return 0;
}

double do_Function(double x)
{
	return (6 * x * x - 17 * x + 5);
}

double do_DifferentialFunction(double x)
{
	return (12 * x - 17);
}

double do_Newton_Raphson_Method(double xL, double tol)
{
	int loop = 0;
	double x = xL;

	while (true) {
		loop += 1;

		if (loop > 5000) {
			return -1;
		} else {

		}

		x = x - do_Function(x) / do_DifferentialFunction(x);
		printf("Loop = %d\tx = %e\t Function(x) = %e\n", loop, x, do_Function(x));

		if (fabs(do_Function(x)) < tol) {
			return x;
		} else {

		}
	}
}
