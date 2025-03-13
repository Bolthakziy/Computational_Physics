#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void diffEq(double x, double y[], double yp[]);
void ruku(double xi, double yi[], double h);

int main()
{
	int i, stepNumber;
	double xi = 0., xlast = 10., smallO, h = 0.01, yi1_0 = 0.5, yi2_0 = 0.;
	double yi[3];
	FILE *fp;

	yi[1] = yi1_0, yi[2] = yi2_0;
	stepNumber = (int)((xlast - xi) / h + 0.5);

	fp = fopen("PhysicalPendulum.dat", "w");
	printf("\nInitial angle = %.3f, Initial angular speed : %.3f\n", yi1_0, yi2_0);
	fprintf(fp, "\nInitial angle = %.3f, Initial angular speed : %.3f\n", yi1_0, yi2_0);

	for (i = 1; i <= stepNumber; i++) {
		ruku(xi, yi, h);
		xi = xi + h;
		smallO = yi1_0 * cos(xi);
		printf("Time = %.3f, Theta = %.5f, Small Oscillation = %.5f, Subtle Error = %.3e\n", xi, yi[1], smallO, yi[1] - smallO);
		fprintf(fp, "Time = %.3f, Theta = %.5f, Small Oscillation = %.5f, Subtle Error = %.3e\n", xi, yi[1], smallO, yi[1] - smallO);
	}

	fclose(fp);
	system("pause");

	return 0;
}

void diffEq(double x, double y[], double yp[])
{
	yp[1] = y[2];
	yp[2] = -sin(y[1]);
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

	x = xi + h;
	y[1] = yi[1] + h * k[1][3];
	y[2] = yi[2] + h * k[2][3];
	k[1][4] = y[2];
	diffEq(x, y, yp);
	k[2][4] = yp[2];

	for (m = 1; m <= 2; m++) {
		yi[m] = yi[m] + h / 6. * (k[m][1] + 2. * k[m][2] + 2. * k[m][3] + k[m][4]);
	}
}
