#ifndef JSONERROR_H
#define JSONERROR_H

#include "jsonparse.h"

typedef struct {
	JSONNodeType type;
	char* message;
} JSONErrorNode;

JSONErrorNode* JSONErrorNode_create(char* message);
void JSONErrorNode_print(JSONErrorNode* node, int indent);

#endif //JSONERROR_H
