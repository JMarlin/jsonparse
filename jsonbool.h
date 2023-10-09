#ifndef JSONBOOL_H
#define JSONBOOL_H

#include "jsonparse.h"

typedef struct {
	JSONNodeType type;
	int value;
} JSONBoolNode;

JSONNodeParseResult JSONBoolNode_tryParse(char* jsonInput);
JSONBoolNode* JSONBoolNode_create(int value);
void JSONBoolNode_print(JSONBoolNode* node, int indent);

#endif //JSONBOOL_H
