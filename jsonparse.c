#include "jsonparse.h"

#include <stdio.h>
#include <stdlib.h>

void printIndent(int indent) {

	for(int i = 0; i < indent; i++)
		printf("    ");
}

void JSONStringNode_print(JSONStringNode* node, int indent) {

	printIndent(indent);
	printf("\"%s\"", node->value);
}

void JSONErrorNode_print(JSONErrorNode* node, int indent) {

	printIndent(indent);
	printf("ERROR: %s", node->message);
}

void JSONNode_print(JSONNode* node, int indent) {

	if(node->type == Error)
		JSONErrorNode_print((JSONErrorNode*)node, indent);

	if(node->type == String)
		JSONStringNode_print((JSONStringNode*)node, indent);
}

JSONStringNode* JSONStringNode_create(char* value) {

	JSONStringNode* node = (JSONStringNode*)malloc(sizeof(JSONStringNode));

	*node = (JSONStringNode) {
		.type = String,
		.value = value
	};

	return node;
}

JSONErrorNode* JSONErrorNode_create(char* message) {

	JSONErrorNode* node = (JSONErrorNode*)malloc(sizeof(JSONErrorNode));

	*node = (JSONErrorNode) {
		.type = Error,
		.message = message
	};

	return node;
}

JSONNode* JSONStringNode_tryParse(char* jsonInput) {

	if(jsonInput[0] != '"')
		return (JSONNode*)JSONErrorNode_create("String did not begin with a double-quote");

	JSONNode* stringNode =
		(JSONNode*)JSONStringNode_create("[uh we don't actually parse strings yet]");

	if(!stringNode)
		return (JSONNode*)JSONErrorNode_create("Failed to allocate a string node");

	return stringNode;
}

JSONNode* JSONParse_parse(char* jsonInput) {

	return (JSONNode*)JSONStringNode_tryParse(jsonInput);
}

void JSONParse_freeNode(JSONNode* node) {

	free((void*)node);
}
