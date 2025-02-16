#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define  PI  3.141593

double do_Function(double x);
double do_MonteCarlo2(double x_left, double x_right, long n);

int main()
{
	long n;
	double x_left = 0., x_right = PI / 2, y_min = 0., y_max = 1., integral, error, exactValue = 1.;

	for (n = 100; n <= 1000000; n *= 10) {
		integral = do_MonteCarlo2(x_left, x_right, n);
		error = (exactValue - integral) / exactValue;
		printf("Monte Carlo2(%ld) = %f\t\t Realtive Error = %e\n", n, integral, error);
	}
	getchar();

	return 0;
}

double do_Function(double x)
{
	return sin(x);
}

double do_MonteCarlo2(double x_left, double x_right, long n)
{
	long i;
	double x, y_sum = 0;

	srand((unsigned)time(NULL));

	for (i = 1; i <= n; i++) {
		x = x_left + (x_right - x_left) * (double)rand() / RAND_MAX;
		y_sum += do_Function(x);
	}

	return ((x_right - x_left) * y_sum / n);
}
