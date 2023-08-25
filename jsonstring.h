#ifndef JSONSTRING_H
#define JSONSTRING_H

#include "jsonparse.h"

typedef struct {
	JSONNodeType type;
	char* value;
} JSONStringNode;

JSONNodeParseResult JSONStringNode_tryParse(char* jsonInput);
JSONStringNode* JSONStringNode_create(char* value);
void JSONStringNode_print(JSONStringNode* node, int indent);

#endif //JSONSTRING_H
