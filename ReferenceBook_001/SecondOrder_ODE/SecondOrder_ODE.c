#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void diffEq(double x, double y[], double yp[]);
void ruku(double xi, double yi[], double h);

int main()
{
	int i, stepNumber = 1000;
	double xi = 0., xlast = 1., h, yi[3], exactSol;
	FILE* fp = fopen("SecondOrder_ODE.dat", "a");

	yi[1] = -1., yi[2] = 2.;
	h = (xlast - xi) / stepNumber;
	printf("Step number : %d\n", stepNumber);
	fprintf(fp, "Step number : %d\n", stepNumber);

	for (i = 1; i <= stepNumber; i++) {
		ruku(xi, yi, h);
		xi = xi + h;
		exactSol = xi * xi + 2. * xi -1.;
		printf("x = %.3f, y = %.5f, yExact = %.5f, Relative Error : %.3e\n", xi, yi[1], exactSol, (yi[1] - exactSol) / exactSol);
		fprintf(fp, "x = %.3f, y = %.5f, yExact = %.5f, Relative Error : %.3e\n", xi, yi[1], exactSol, (yi[1] - exactSol) / exactSol);
	}

	fclose(fp);
	system("pause");

	return 0;
}

void diffEq(double x, double y[], double yp[])
{
	yp[1] = y[2];
	yp[2] = (2. * x * y[2] - 2. * y[1]) / (1. + x * x);
}

void ruku(double xi, double yi[], double h)
{
	int m;
	double x, y[3], yp[3], k[3][5];

	x = xi;
	y[1] = yi[1];
	y[2] = yi[2];
	k[1][1] = y[2];
	diffEq(x, y, yp);
	k[2][1] = yp[2];

	x = xi + h / 2.;
	y[1] = yi[1] + h / 2. * k[1][1];
	y[2] = yi[2] + h / 2. * k[2][1];
	k[1][2] = y[2];
	diffEq(x, y, yp);
	k[2][2] = yp[2];

	x = xi + h / 2.;
	y[1] = yi[1] + h / 2. * k[1][2];
	y[2] = yi[2] + h / 2. * k[2][2];
	k[1][3] = y[2];
	diffEq(x, y, yp);
	k[2][3] = yp[2];
	
	x = xi + h / 2.;
	y[1] = yi[1] + h / 2. * k[1][3];
	y[2] = yi[2] + h / 2. * k[2][3];
	k[1][4] = y[2];
	diffEq(x, y, yp);
	k[2][4] = yp[2];

	for (m = 1; m <= 2; m++) {
		yi[m] = yi[m] + h / 6. * (k[m][1] + 2. * k[m][2] + 2. * k[m][3] + k[m][4]);
	}
}
