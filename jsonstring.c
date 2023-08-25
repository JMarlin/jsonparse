#include "jsonstring.h"
#include "jsonerror.h"
#include "printutil.h"

#include <stdio.h>
#include <stdlib.h>

void JSONStringNode_print(JSONStringNode* node, int indent) {

	printIndent(indent);
	printf("<<%s>>", node->value);
}

JSONStringNode* JSONStringNode_create(char* value) {

	JSONStringNode* node = (JSONStringNode*)malloc(sizeof(JSONStringNode));

	*node = (JSONStringNode) {
		.type = String,
		.value = value
	};

	return node;
}

JSONNodeParseResult JSONStringNode_tryParse(char* inputPosition) {

	char* currentPosition = inputPosition;

	if(*currentPosition != '"') return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONErrorNode_create(
			"String did not begin with a double-quote" ),
		.currentPosition = inputPosition
	};

	currentPosition++;

	char* startOfStringValue = currentPosition;

	for(; *currentPosition && *currentPosition != '"'; currentPosition++) { } 

	if(*currentPosition != '"') return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONErrorNode_create(
			"Did not encounter closing quote while parsing string" ),
		.currentPosition = inputPosition
	};

	*currentPosition = 0;

	JSONNode* stringNode = (JSONNode*)JSONStringNode_create(startOfStringValue);

	if(!stringNode) return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONErrorNode_create(
			"Failed to allocate a string node" ),
		.currentPosition = inputPosition
	};

	return (JSONNodeParseResult) {
		.node = stringNode,
		.currentPosition = currentPosition + 1
	};
}
