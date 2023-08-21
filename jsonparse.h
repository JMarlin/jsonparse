#ifndef JSONPARSE_H
#define JSONPARSE_H

typedef enum {
	Error,
	String
} JSONNodeType;

typedef struct {
	JSONNodeType type;
} JSONNode;

JSONNode* JSONParse_parse(char* jsonInput);
void JSONParse_freeNode(JSONNode* node);
void JSONNode_print(JSONNode* node, int indent);

#endif //JSONPARSE_H
