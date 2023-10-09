#ifndef PARSEUTIL_H
#define PARSEUTIL_H

JSONNodeParseResult ParseUtil_tryMultiple(char* inputPosition, JSONParseFunction functionList[]);
JSONNodeParseResult ParseUtil_checkPosition(char* input, int position, char expected);
JSONNodeParseResult ParseUtil_matchString(char* inputPosition, char* expectedValue);
JSONNodeParseResult ParseUtil_consumeWhitespace(char* inputPosition);

#endif //PARSEUTIL_H
