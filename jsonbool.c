#include "jsonbool.h"
#include "jsonerror.h"
#include "printutil.h"
#include "parseutil.h"

#include <stdlib.h>
#include <stdio.h>

void JSONBoolNode_print(JSONBoolNode* node, int indent) {

	printIndent(indent);
	printf(node->value ? "true" : "false");
}

JSONBoolNode* JSONBoolNode_create(int value) {

	JSONBoolNode* node = (JSONBoolNode*)malloc(sizeof(JSONBoolNode));

	*node = (JSONBoolNode) {
		.type = Bool,
		.value = value
	};

	return node;
}


JSONNodeParseResult JSONBoolNode_tryParseTrue(char* inputPosition) {

	JSONNodeParseResult result = ParseUtil_matchString(inputPosition, "true");

	if(result.node == 0)
		result.node = (JSONNode*)JSONBoolNode_create(1);

	return result;
}

JSONNodeParseResult JSONBoolNode_tryParseFalse(char* inputPosition) {

	JSONNodeParseResult result = ParseUtil_matchString(inputPosition, "false");

	if(result.node == 0)
		result.node = (JSONNode*)JSONBoolNode_create(0);

	return result;
}

JSONNodeParseResult JSONBoolNode_tryParse(char* inputPosition) {

	return ParseUtil_tryMultiple(inputPosition, (JSONParseFunction[]) {
		JSONBoolNode_tryParseFalse,
		JSONBoolNode_tryParseTrue,
		0
	});
}
