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

JSONNodeParseResult JSONParse_consumeWhitespace(char* inputPosition) {

	if(*inputPosition == 0x20
	|| *inputPosition == 0x0A
	|| *inputPosition == 0x0D
	|| *inputPosition == 0x09 )
		return JSONParse_consumeWhitespace(inputPosition + 1);

	return (JSONNodeParseResult) {
		.node = (JSONNode*)0,
		.currentPosition = inputPosition
	};
}

JSONNodeParseResult JSONElement_tryParse(char* inputPosition) {

	JSONNodeParseResult parseResult =
		JSONParse_consumeWhitespace(inputPosition);

	parseResult = JSONStringNode_tryParse(parseResult.currentPosition);

	if(!parseResult.node || parseResult.node->type == Error)
		return parseResult;

	JSONNodeParseResult endWhitespaceParseResult =
		JSONParse_consumeWhitespace(parseResult.currentPosition);

	if(!endWhitespaceParseResult.currentPosition || *endWhitespaceParseResult.currentPosition != 0) {

		JSONParse_freeNode(parseResult.node);

		return (JSONNodeParseResult) {
			.node = (JSONNode*)JSONErrorNode_create(
				"Unexpected input at expected EOF" ),
			.currentPosition = parseResult.currentPosition
		};
	}

	return parseResult;
}

JSONNode* JSONParse_parse(char* jsonInput) {

	JSONNodeParseResult parseResult = JSONElement_tryParse(jsonInput);

	return parseResult.node;
}

void JSONParse_freeNode(JSONNode* node) {

	free((void*)node);
}
