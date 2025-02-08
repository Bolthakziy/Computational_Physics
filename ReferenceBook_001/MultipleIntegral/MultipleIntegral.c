#include <stdio.h>
#include <math.h>

double do_Function(double x, double y);
double do_IntegralFunction(double y, double x0, double xn, int n);
double do_Simpson2D(double x0, double xn, double y0, double yn, int n);

int main()
{
	int n = 100;
	double error, integral, x0 = 1., xn = 2., y0 = 3., yn = 4., exactValue = 111. / 6.;

	integral = do_Simpson2D(x0, xn, y0, yn, n);
	error = (integral - exactValue) / exactValue;

	printf("2D-Simpson (%d) = %f Relative error = %e\n", n, integral, error);

	return 0;
}

double do_Function(double x, double y)
{
	double expression = x * y * y;

	return expression;
}

double do_IntegralFunction(double y, double x0, double xn, int n)
{
	int i;
	double x, sum_even = 0., sum_odd = 0., h = (xn - x0) / (double)n;

	for (i = 1; i <= n - 1; i += 2) {
		x = x0 + i * h;
		sum_odd += do_Function(x, y);
	}

	for (i = 2; i <= n - 2; i += 2) {
		x = x0 + i * h;
		sum_even += do_Function(x, y);
	}

	return ((do_Function(x0, y) + do_Function(xn, y) + 4. * sum_odd + 2. * sum_even) * h / 3.);
}

double do_Simpson2D(double x0, double xn, double y0, double yn, int n)
{
	int i;
	double y, sum_even = 0., sum_odd = 0., yh = (yn - y0) / (double)n;

	for (i = 1; i <= n - 1; i += 2) {
		y = y0 + i * yh;
		sum_odd += do_IntegralFunction(y, x0, xn, n);
	}

	for (i = 2; i <= n - 2; i += 2) {
		y = y0 + i * yh;
		sum_even += do_IntegralFunction(y, x0, xn, n);
	}

	return ((do_IntegralFunction(y0, x0, xn, n) + do_IntegralFunction(yn, x0, xn, n) + 4. * sum_odd + 2. * sum_even) * yh / 3.);
}
