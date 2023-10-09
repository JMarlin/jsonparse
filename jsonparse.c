#include "jsonparse.h"
#include "jsonstring.h"
#include "jsonnull.h"
#include "jsonbool.h"
#include "jsonerror.h"
#include "parseutil.h"

#include <stdlib.h>

void JSONNode_print(JSONNode* node, int indent) {

	if(node->type == Error)
		JSONErrorNode_print((JSONErrorNode*)node, indent);

	if(node->type == String)
		JSONStringNode_print((JSONStringNode*)node, indent);

	if(node->type == Null)
		JSONNullNode_print((JSONNullNode*)node, indent);

	if(node->type == Bool)
		JSONBoolNode_print((JSONBoolNode*)node, indent);
}
JSONNodeParseResult JSONValue_tryParse(char* inputPosition) {

	return ParseUtil_tryMultiple(inputPosition, (JSONParseFunction[]) {
		JSONNullNode_tryParse,
		JSONBoolNode_tryParse,
		JSONStringNode_tryParse,
		0
	});
}

JSONNodeParseResult JSONElement_tryParse(char* inputPosition) {

	JSONNodeParseResult parseResult =
		ParseUtil_consumeWhitespace(inputPosition);

	parseResult = JSONValue_tryParse(parseResult.currentPosition);

	if(!parseResult.node || parseResult.node->type == Error)
		return parseResult;

	JSONNodeParseResult endWhitespaceParseResult =
		ParseUtil_consumeWhitespace(parseResult.currentPosition);

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
