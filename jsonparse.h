#ifndef JSONPARSE_H
#define JSONPARSE_H

typedef enum {
	Error
} JSONResultType;

typedef struct {
	JSONResultType type;
	char* message;
} JSONResult;

JSONResult JSONParse_parse(char* jsonString);

#endif //JSONPARSE_H
