#include "jsonnull.h"
#include "jsonerror.h"
#include "printutil.h"
#include "parseutil.h"

#include <stdlib.h>
#include <stdio.h>

void JSONNullNode_print(JSONNullNode* node, int indent) {

	printIndent(indent);
	printf("NULL");
}

JSONNullNode* JSONNullNode_create() {

	JSONNullNode* node = (JSONNullNode*)malloc(sizeof(JSONNullNode));

	*node = (JSONNullNode) {
		.type = Null
	};

	return node;
}

JSONNodeParseResult JSONNullNode_tryParse(char* inputPosition) {

	JSONNodeParseResult result = ParseUtil_matchString(inputPosition, "null");

	if(result.node == 0)
		result.node = (JSONNode*)JSONNullNode_create();

	return result;
}
