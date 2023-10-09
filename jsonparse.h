#ifndef JSONPARSE_H
#define JSONPARSE_H

typedef enum {
	Error,
	String,
	Null,
	Bool
} JSONNodeType;

typedef struct {
	JSONNodeType type;
} JSONNode;

typedef struct {
	JSONNode* node;
	char* currentPosition;
} JSONNodeParseResult;

typedef JSONNodeParseResult (*JSONParseFunction)(char*);

JSONNode* JSONParse_parse(char* jsonInput);
void JSONParse_freeNode(JSONNode* node);
void JSONNode_print(JSONNode* node, int indent);
JSONNodeParseResult JSONParse_tryMultiple(char*, JSONParseFunction[]);

#endif //JSONPARSE_H
