#include "jsonparse.h"
#include "testdata.h"

int main(int argc, char* argv[]) {

	JSONNode* node = JSONParse_parse(testData[0]);

	JSONParse_freeNode(node);

	return 0;
}
