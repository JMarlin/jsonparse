#include "jsonparse.h"
#include "jsonerror.h"

JSONNodeParseResult ParseUtil_tryMultiple(char* inputPosition, JSONParseFunction parseFunctions[]) {

	JSONNodeParseResult result = {
		.node = 0
	};

	for(int i = 0; parseFunctions[i] != 0; i++) {
		
		result = parseFunctions[i](inputPosition);

		if(result.node != 0 && result.node->type != Error)
			return result;
	}

	return result;
}

JSONNodeParseResult ParseUtil_checkPosition(char* input, int position, char expected) {

	if(input[position] == expected)
		return (JSONNodeParseResult) { 0 };

	return (JSONNodeParseResult) {
		.node = (JSONNode*)JSONErrorNode_create(
			"Unexpected character found in bool literal" )
	};
}

JSONNodeParseResult ParseUtil_matchString(char* inputPosition, char* expectedValue) {

	JSONNodeParseResult result;
	int i;

	for(i = 0; expectedValue[i]; i++)
		if((result = ParseUtil_checkPosition(inputPosition, i, expectedValue[i])).node != 0)
			return result;

	return (JSONNodeParseResult) {
		.node = 0,
		.currentPosition = inputPosition + i
	};
}

JSONNodeParseResult ParseUtil_consumeWhitespace(char* inputPosition) {

	if(*inputPosition == 0x20
	|| *inputPosition == 0x0A
	|| *inputPosition == 0x0D
	|| *inputPosition == 0x09 )
		return ParseUtil_consumeWhitespace(inputPosition + 1);

	return (JSONNodeParseResult) {
		.node = (JSONNode*)0,
		.currentPosition = inputPosition
	};
}

