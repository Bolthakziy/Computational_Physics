#include <stdio.h>
#include <math.h>

#define  PI  3.1415926535897932385

double do_Function(double x);
double do_Trapezoid(double xin, double xout, int n);

int main()
{
	int n;
	double error, integral, exactValue = 1., xin = 0., xout = PI / 2;

	printf("Input the number of distances. : ");
	scanf("%d", &n);
	integral = do_Trapezoid(xin, xout, n);
	error = (exactValue - integral) / exactValue;
	printf("Trapezoid(%d) = %f, Relative error = %e\n", n, integral, error);
	getchar();

	return 0;
}

double do_Function(double x)
{
	double y = sin(x);

	return y;
}

double do_Trapezoid(double xin, double xout, int n)
{
	int i;
	double x = 0, sum_mid = 0, h = (xout - xin) / n;

	for (i = 0; i < n - 1; i++) {
		x = xin + i * h;
		sum_mid += do_Function(x);
	}

	return ((do_Function(xin) + do_Function(xout) + 2. * sum_mid) * h / 2);
}
