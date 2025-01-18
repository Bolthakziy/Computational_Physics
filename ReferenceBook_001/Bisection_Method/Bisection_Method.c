#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double do_Function(double x);
double do_Bisection(float xL, double h, double tol);

int main()
{
	int i, numberOfRoot = 2;
	double xL = 0.0, x, h = 0.1, tol = 1.0e-8;

	for (i = 0; i < numberOfRoot; ++i) {
		if (i > 0) {
			xL = x + h;
		} else {

		}

		x = do_Bisection(xL, h, tol);
		printf("%d root = %e\n", i + 1, x);
		system("pause");
	}

	return 0;
}

double do_Function(double x)
{
	return (2 * x * x - 12 * x + 5);
}

double do_Bisection(float xL, double h, double tol)
{
	int loop = 0;
	double x = xL;

	while (true) {
		printf("Loop = %d\tx = %e\tf(x) = %e\n", loop, x, do_Function(x));
		x += h;

		if (loop > 1000) {
			printf("There are too lots of loops....\n");
			return -1;
		} else {

		}

		loop += 1;

		if (fabs(do_Function(x)) < tol) {
			return x;
		} else {

		}

		if ((do_Function(x) * do_Function(x - h)) < 0) {
			x -= h;
			h *= 0.5;
		} else {

		}
	}
}
