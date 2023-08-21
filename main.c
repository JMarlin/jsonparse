#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jsonparse.h"
#include "testdata.h"

int main(int argc, char* argv[]) {

	for(int i = 0; i < sizeof(testData)/sizeof(*testData); i++) {

		int stringLength = strlen(testData[i]) + 1;
		char* buffer = (char*)malloc(stringLength);

		strncpy(buffer, testData[i], stringLength);

		printf("---------------------------\n");
		printf("Test %d                    \n", i + 1);
		printf("---------------------------\n");
		printf("Input:                     \n");
		printf("    %s                     \n", testData[i]);
		printf("---------------------------\n");

		JSONNode* node = JSONParse_parse(buffer);

		printf("Output:                    \n");
		JSONNode_print(node, 1);
		printf("\n\n\n");

		JSONParse_freeNode(node);
		free((void*)buffer);
	}

	return 0;
}
