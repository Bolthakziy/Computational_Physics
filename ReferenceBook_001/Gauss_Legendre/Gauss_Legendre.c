#include <stdio.h>
#include <math.h>

#define  PI  3.1415926535897932385

double do_Function(double y);

int main()
{
	FILE *fp;
	double x[6][6], w[6][6];
	double integral, exactValue, error;
	int i, j;

	x[1][0] = -0.577350269189626;
	x[1][1] = -x[1][0];
	w[1][0] = 1.000000000000000;
	w[1][1] = w[1][0];

	x[2][0] = -0.774596669241483;
	x[2][1] = 0.;
	x[2][2] = -x[2][0];
	w[2][0] = 0.555555555555556;
	w[2][1] = 0.888888888888889;
	w[2][2] = w[2][0];

	x[3][0] = -0.861136311594053;
	x[3][1] = -0.339981043584856;
	x[3][2] = -x[3][1];
	x[3][3] = -x[3][0];
	w[3][0] = 0.347854845137454;
	w[3][1] = 0.652145154862546;
	w[3][2] = w[3][1];
	w[3][3] = w[3][0];
	
	x[4][0] = -0.906179845938664;
	x[4][1] = -0.538469310105683;
	x[4][2] = 0.;
	x[4][3] = -x[4][1];
	x[4][4] = -x[4][0];
	w[4][0] = 0.236926885056189;
	w[4][1] = 0.478628670499367;
	w[4][2] = 0.568888888888889;
	w[4][3] = w[4][1];
	w[4][4] = w[4][0];

	exactValue = 1.;
	fp = fopen("Gauss_Legendra.dat", "w");

	for (i = 1; i <= 4; ++i) {
		integral = 0.;

		for (j = 0; j <= i; j++) {
			integral += PI / 4. * do_Function(x[i][j]) * w[i][j];
		}

		error = (exactValue - integral) / exactValue;
		printf(" N = %d, Integral = %f, Relative error = %e\n", i, integral, error);
		fprintf(fp, " N = %d, Integral = %f, Relative error = %e\n", i, integral, error);
	}

	fclose(fp);
	getchar();

	return 0;
}

double do_Function(double y)
{
	return sin(PI * y / 4. + PI / 4.);
}
