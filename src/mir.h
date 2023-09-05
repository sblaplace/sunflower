#ifndef MIR_H_
#define MIR_H_

#include "parse.h"

typedef struct mir
{
    char *val;
    struct node *next;
} mir_t;

mir_t *lower(ast_t *parsed);

#endif