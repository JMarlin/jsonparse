#ifndef JSONNULL_H
#define JSONNULL_H

#include "jsonparse.h"

typedef struct {
	JSONNodeType type;
} JSONNullNode;

JSONNodeParseResult JSONNullNode_tryParse(char* jsonInput);
JSONNullNode* JSONNullNode_create();
void JSONNullNode_print(JSONNullNode* node, int indent);

#endif //JSONNULL_H
