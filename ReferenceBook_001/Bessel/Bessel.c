#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

double do_Bisection(float xL, double h, double tol, int n);
double do_Bessel(int n, double x);
double do_2Bessel(int n, double x);

int main()
{
	int i, n, NumberOfRoot = 5;
	double x, xL, h = 0.01, tol = 1.e-8;
	FILE* fp = fopen("Bessel.dat", "w");

	for (n = 0; n <= 5; n++) {
		xL = 1.;

		for (i = 0; i < NumberOfRoot; i++) {
			if (i > 0) {
				xL = x + h;
			} else {

			}

			x = do_Bisection(xL, h, tol, n);
			printf("Bessel %d %dth(or st, rd) root : %.4f\n", n, i + 1, x);
			fprintf(fp, "Bessel %d %dth(or st, rd) root : %.4f\n", n, i + 1, x);
		}
	}

	fclose(fp);
	getchar();

	return 0;
}

double do_Bisection(float xL, double h, double tol, int n)
{
	int loop = 0;
	double x = xL;

	while (true) {
		printf("Loop : %d, x = %e, Bessel J(n, x) = %e\n", loop, x, do_Bessel(n, x));
		x += h;

		if (loop > 5000) {
			return -1;
		} else {

		}

		loop++;

		if (do_Bessel(n, x) == 0.) {
			return x;
		} else {

		}

		if (fabs(do_Bessel(n, x)) < tol) {
			return x;
		} else {

		}

		if (do_Bessel(n, x) * do_Bessel(n, x - h) < 0) {
			x -= h;
			h *= .5;
		} else {

		}
	}
}

double do_2Bessel(int n, double x)
{
	int j, m;
	double Bessel[51], BesselSum = 0;

	if (n > 1) {
		return 100;
	} else {

	}

	for (m = 1; m <= 50; m++) {
		Bessel[m] = pow(-1, m) * pow(x / 2, n);

		for (j = 1; j <= m; j++) {
			Bessel[m] *= x / 2;
			Bessel[m] /= (double)j;
			Bessel[m] *= x / 2;
			Bessel[m] /= (double)(j + n);
		}
	}

	Bessel[0] = pow(x, n) / pow(2, n);

	for (j = 0; j <= 50; j++) {
		BesselSum += Bessel[j];
	}

	return BesselSum;
}

double do_Bessel(int n, double x)
{
	switch (n) {
		case 0 :
			return do_2Bessel(0, x);
		case 1 :
			return do_2Bessel(1, x);
		default :
			return (2. * (n - 1) / x * do_Bessel(n - 1, x) - do_Bessel(n - 2, x));
	}
}
