#include <ctype.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

/**
 * gcc cstat.c  -lm
 */
int main(int argc, char** argv) {
	double min = DBL_MAX;
	double max = DBL_MIN;
	double sum = 0;
	double sum2 = 0;
	int count = 0;
	int bad = 0;

	char* line = NULL;
	size_t len = 0;

	double in = 0;
	
	while (getline(&line, &len, stdin) != -1) {
		if (sscanf(line, "%lf", &in) != 1) { 
			//fprintf(stderr, "Skipping malformed line %s", line);
			bad++;
			continue;
		}
		if (in < min) min = in;
		if (in > max) max = in;
		sum		+= in;
		sum2	+= in * in;
		count	+= 1;
	}

	double avg = sum / count;
	double var = sum2 / count - pow(avg, 2); // Or unbiased?
	double std = sqrt(var);
	
	printf("cnt:\t%d\n", count);
	printf("bad:\t%d\n", bad);
	printf("sum:\t%.8g\n", sum);
	printf("min:\t%.8g\n", min);
	printf("max:\t%.8g\n", max);
	printf("avg:\t%.8g\n", avg);
	printf("var:\t%.8g\n", var);
	printf("std:\t%.8g\n", std);	
}
