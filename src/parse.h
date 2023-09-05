#ifndef PARSE_H_
#define PARSE_H_

#include "lex.h"

typedef struct ast
{
    char *val;
    struct ast *node;
} ast_t;

ast_t *parse(node_t *lexed);

#endif