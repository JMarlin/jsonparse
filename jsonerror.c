#include "jsonerror.h"
#include "printutil.h"

#include <stdio.h>
#include <stdlib.h>

void JSONErrorNode_print(JSONErrorNode* node, int indent) {

	printIndent(indent);
	printf("ERROR: %s", node->message);
}

JSONErrorNode* JSONErrorNode_create(char* message) {

	JSONErrorNode* node = (JSONErrorNode*)malloc(sizeof(JSONErrorNode));

	*node = (JSONErrorNode) {
		.type = Error,
		.message = message
	};

	return node;
}
