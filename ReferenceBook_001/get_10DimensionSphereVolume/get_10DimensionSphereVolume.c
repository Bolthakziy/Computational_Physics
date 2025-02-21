#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define  di  10
#define  PI  3.1415926535897932385

int main()
{
	unsigned long i, noOfThrow;
	int j, countIn;
	double xi, sphere = 0, Monte, volOfSphere, error;

	for (noOfThrow = 1000; noOfThrow <= 10000000; noOfThrow *= 10) {
		countIn = 0;
		srand((unsigned)time(NULL));

		for (i = 1; i <= noOfThrow; i++) {
			sphere = 0;

			for (j = 1; j <= di; j++) {
				xi = (double) rand() / RAND_MAX;
				sphere += xi * xi;
			}

			if (sphere <= 1.) {
				countIn++;
			} else {

			}
		}

		volOfSphere = pow(PI, 5.) / 120.;
		Monte = pow(2., di) * (double)countIn / noOfThrow;
		error = (Monte - volOfSphere) / volOfSphere;
		printf("Performance times : %ld, %ddimension volume : %lf Relative error : %le\n", noOfThrow, di, Monte, error);
	}

	system("pause");
}
