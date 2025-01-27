#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define  PI  3.1415926535897932385

double lambda = 9. * PI * PI / 4.;

double do_Equation(double x, int i);
double do_Bisection(float xL, double h, double tol, int i);

int main()
{
	int i, NumberOfRoot = 3;
	double x, xL, h = 0.01, tol = 1.e-8, energy;

	for (i = 0; i < NumberOfRoot; i++) {
		xL = (float)i * PI / 2. + h;
		x = do_Bisection(xL, h, tol, i);
		energy = x * x / lambda - 1.;

		if (i & 0x01) {
			printf("%d : Antisymmetric case; xi = %f and energy = %f U_O \n", i + 1, x, energy);
		} else {
			printf("%d : Symmetric case; xi = %f and energy = %f U_O \n", i + 1, x, energy);
		}
	}

	getchar();

	return 0;
}

double do_Equation(double x, int i)
{
	if (i & 0x01) {
		return (1. / tan(x) + (sqrt(lambda - x * x)) / x);
	} else {
		return (tan(x) - (sqrt(lambda - x * x)) / x);
	}
}

double do_Bisection(float xL, double h, double tol, int i)
{
	int loop = 0;
	double x = xL;

	while (true) {
		x += h;

		if (loop > 5000) {
			return -1;
		} else {

		}

		loop += 1;

		if (do_Equation(x, i) == 0.) {
			return x;
		} else {

		}

		if (fabs(do_Equation(x, i)) < tol) {
			return x;
		} else {

		}

		if (do_Equation(x, i) * do_Equation(x - h, i) < 0) {
			x -= h;
			h *= .5;
		} else {

		}
	}
}
