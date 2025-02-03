#include <stdio.h>
#include <math.h>

#define  PI  3.1415926535897932385

double do_Function(double x);
double do_Simpson(double xin, double xout, int n);

int main()
{
	int n;
	double error, integral, xin = 0., xout = PI / 2., exactValue = 1.;

	printf("Input the number of intervals. : ");
	scanf("%d", &n);

	integral = do_Simpson(xin, xout, n);
	error = (exactValue - integral) / exactValue;
	printf("Simpson(%d) = %f, Relative error = %e\n", n, integral, error);
	getchar();

	return 0;
}

double do_Function(double x)
{
	double y = sin(x);

	return y;
}

double do_Simpson(double xin, double xout, int n)
{
	int i;
	double x, sum_even = 0., sum_odd = 0., h = (xout - xin) / (double)n;

	for (i = 1; i <= n - 1; i += 2) {
		x = xin + (double)i * h;
		sum_odd += do_Function(x);
	}

	for (i = 2; i <= n - 2; i += 2) {
		x = xin + (double)i * h;
		sum_even += do_Function(x);
	}

	return ((do_Function(xin) + do_Function(xout) + 4. * sum_odd + 2. * sum_even) * h / 3.);
}
