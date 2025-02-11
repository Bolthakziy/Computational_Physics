#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define  PI  3.1415926535897932385

double do_Function(double x);
double do_MonteCarloIntegral(double x_left, double x_right, double y_min, double y_max, long n);

int main()
{
	long n;
	double x_left = 0., x_right = PI / 2., y_min = 0., y_max = 1., integral, error, exactValue = 1.;

	for (n = 100; n <= 1000000; n *= 10) {
		integral = do_MonteCarloIntegral(x_left, x_right, y_min, y_max, n);
		error = (exactValue - integral) / exactValue;
		printf("Monte Carlo(%ld) = %f\t\t Relative Error = %e\n", n, integral, error);
	}

	getchar();

	return 0;
}

double do_Function(double x)
{
	return (sin(x));
}

double do_MonteCarloIntegral(double x_left, double x_right, double y_min, double y_max, long n)
{
	int i, count_in = 0;
	double x, y;

	srand((unsigned)time(NULL));

	for (i = 1; i <= n; i++) {
		x = x_left + (x_right - x_left) * (double)rand() / RAND_MAX;
		y = y_min + (y_max - y_min) * (double)rand() / RAND_MAX;

		if (y <= do_Function(x)) {
			count_in++;
		} else {

		}
	}

	return ((x_right - x_left) * (y_max - y_min) * count_in / n);
}
