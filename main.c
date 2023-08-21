#include <stdio.h>

#include "jsonparse.h"
#include "testdata.h"

int main(int argc, char* argv[]) {

	for(int i = 0; i < sizeof(testData)/sizeof(*testData); i++) {

		printf("---------------------------\n");
		printf("Test %d                    \n", i + 1);
		printf("---------------------------\n");
		printf("Input:                     \n");
		printf("    %s                     \n", testData[i]);
		printf("---------------------------\n");

		JSONNode* node = JSONParse_parse(testData[i]);

		printf("Output:                    \n");
		JSONNode_print(node, 1);
		printf("\n\n\n");

		JSONParse_freeNode(node);
	}

	return 0;
}
