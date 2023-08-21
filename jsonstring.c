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

JSONNode* JSONStringNode_tryParse(char* jsonInput) {

	if(*jsonInput != '"') return (JSONNode*)JSONErrorNode_create(
		"String did not begin with a double-quote" );

	jsonInput++;

	char* startOfStringValue = jsonInput;

	for(; *jsonInput && *jsonInput != '"'; jsonInput++) { } 

	if(*jsonInput != '"') return (JSONNode*)JSONErrorNode_create(
		"Did not encounter closing quote while parsing string" );

	*jsonInput = 0;

	JSONNode* stringNode = (JSONNode*)JSONStringNode_create(startOfStringValue);

	if(!stringNode) return (JSONNode*)JSONErrorNode_create(
		"Failed to allocate a string node" );

	return stringNode;
}
