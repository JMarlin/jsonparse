#ifndef JSONPARSE_H
#define JSONPARSE_H

typedef enum {
	Error,
	String
} JSONNodeType;

typedef struct {
	JSONNodeType type;
} JSONNode;

typedef struct {
	JSONNodeType type;
	char* message;
} JSONErrorNode;

typedef struct {
	JSONNodeType type;
	char* value;
} JSONStringNode;

JSONNode* JSONParse_parse(char* jsonInput);
void JSONParse_freeNode(JSONNode* node);

#endif //JSONPARSE_H
