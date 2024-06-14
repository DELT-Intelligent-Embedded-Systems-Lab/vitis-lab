#include "compute.hpp"
#include <fstream>
#include <iostream>

int main (void) {

	data_t segOut[totalNumWords];

	FILE * fp;

	fp = fopen("out.dat","w");

	const data_t segIn[totalNumWords] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32};

	compute(segIn, segOut);

	for(int i = 0; i < totalNumWords; i++) {
		printf("%d\t%d\n", segIn[i], segOut[i]);
	}

	fclose(fp);

	if (system("diff -w test_gold.dat \"Test_gold.dat\"")) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
		return 1;
	} else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
		return 0;
	}

	return 0;
}

