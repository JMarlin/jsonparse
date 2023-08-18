#include "jsonparse.h"
#include <stdlib.h>

JSONStringNode* JSONStringNode_create(char* value) {

	JSONStringNode* node = (JSONStringNode*)malloc(sizeof(JSONStringNode));

	*node = (JSONStringNode) {
		.type = String,
		.value = value
	};

	return node;
}

JSONNode* JSONParse_parse(char* jsonInput) {

	return (JSONNode*)JSONStringNode_create(jsonInput);
}

void JSONParse_freeNode(JSONNode* node) {

	free((void*)node);
}
