#include "printutil.h"

#include <stdio.h>

void printIndent(int indent) {

	for(int i = 0; i < indent; i++)
		printf("    ");
}
