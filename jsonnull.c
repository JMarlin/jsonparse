#include "jsonnull.h"
#include "jsonerror.h"
#include "printutil.h"

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

JSONNodeParseResult JSONNullNode_checkPosition(char* input, int position, char expected) {

	if(input[position] == expected)
		return (JSONNodeParseResult) { 0 };

	return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONErrorNode_create(
			"Unexpected character found in null literal" )
	};
}

JSONNodeParseResult JSONNullNode_tryParse(char* inputPosition) {

	JSONNodeParseResult result;


	if((result = JSONNullNode_checkPosition(inputPosition, 0, 'n')).node != 0) return result;
	if((result = JSONNullNode_checkPosition(inputPosition, 1, 'u')).node != 0) return result;
	if((result = JSONNullNode_checkPosition(inputPosition, 2, 'l')).node != 0) return result;
	if((result = JSONNullNode_checkPosition(inputPosition, 3, 'l')).node != 0) return result;

	return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONNullNode_create(),
		.currentPosition = inputPosition + 4
	};
}
