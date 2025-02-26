#include <stdio.h>
#include <math.h>

double f(double x, double y);
double exactF(double x);
double euler(double x0, double y0, double h);
double rungeKutta(double x0, double y0, double h);

int main()
{
	int i, n;
	double x, ye, yrk, yExact, h, x0 = 0., y0 = 3., xn = 2.;

	printf("Input the number of intervals. : ");
	scanf("%d", &n);

	h = (xn - x0) / n;
	ye = y0;
	yrk = y0;

	for (i = 0; i < n; i++) {
		x = x0 + h * i;
		ye = euler(x, ye, h);
		yrk = rungeKutta(x, yrk, h);
		yExact = exactF(x + h);

		if (i % 10 == 0) {
			printf("x : %lf\tEuler : %lf\tRungekutta : %lf\tExactValue : %lf\n", x + h, ye, yrk, yExact);
			printf("Relative Error(Euler) : %lf\tRelative Error(RungeKutta) : %lf\n", yExact - ye, yExact - yrk);
		} else {

		}
	}

	getchar();

	return 0;
}

double f(double x, double y)
{
	return (4. * x - 2. * x * y);
}

double exactF(double x)
{
	return (2. + exp(-x * x));
}

double euler(double x0, double y0, double h)
{
	return (y0 + h * f(x0, y0));
}

double rungeKutta(double x0, double y0, double h)
{
	double k1 = h * f(x0, y0), k2 = h * f(x0 + h / 2., y0 + k1 / 2.), k3 = h * f(x0 + h / 2., y0 + k2 / 2.), k4 = h * f(x0 + h, y0 + k3);

	return (y0 + (k1 + 2. * k2 + 2. * k3 + k4) / 6.);
}
