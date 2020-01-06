#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>

double get_bmi(const double length, const double weight) {
	return weight/(length*length);
}

double get_proper_weight(const double length) {
	return length*length*22.0f;
}

int main(int argc, char const *argv[]) {
	switch (argc) {
		case 2:{
			if (argv[1][0] == '-') {
				if (!strncmp("h", argv[1]+1, 2) || !strncmp("-help", argv[1]+1, 6)) {
					printf("---usage---\n");
					printf("bmi: bmi length weight\n");
					printf("weigth at bmi 22: bmi length\n");
					printf("help: bmi -h, bmi --help\n");
					return 0;
				}else{
					printf("unrecognized command line option '%s'\n", argv[1]);
					return 1;
				}
			}
			double length;
			sscanf(argv[1], "%lf", &length);
			if (fabs(length) < DBL_EPSILON) {
				printf("incorrect input\n");
				return 1;
			}
			if (length > 10.0f) {
				length/=100;
			}
			printf("%f\n", get_proper_weight(length));
			break;
		}
		case 3:{
			double length, weight;
			sscanf(argv[1], "%lf", &length);
			sscanf(argv[2], "%lf", &weight);
			if (fabs(length) < DBL_EPSILON || fabs(weight) < DBL_EPSILON) {
				printf("incorrect input\n");
				return 1;
			}
			if (length > 10.0f) {
				length/=100;
			}
			printf("%f\n", get_bmi(length, weight));
			break;
		}
		default:{
			printf("too many(few) arguments.\n");
			return 1;
		}
	}
	return 0;
}
