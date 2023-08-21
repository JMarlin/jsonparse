#include "jsonparse.h"
#include "jsonstring.h"
#include "jsonerror.h"

#include <stdlib.h>

void JSONNode_print(JSONNode* node, int indent) {

	if(node->type == Error)
		JSONErrorNode_print((JSONErrorNode*)node, indent);

	if(node->type == String)
		JSONStringNode_print((JSONStringNode*)node, indent);
}

JSONNode* JSONParse_parse(char* jsonInput) {

	return (JSONNode*)JSONStringNode_tryParse(jsonInput);
}

void JSONParse_freeNode(JSONNode* node) {

	free((void*)node);
}
