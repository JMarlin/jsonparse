#include "jsonparse.h"
#include "testdata.h"

int main(int argc, char* argv[]) {

	JSONResult result = JSONParse_parse(testData[0]);

	return 0;
}
