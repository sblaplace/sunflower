#ifndef LEX_H_
#define LEX_H_

typedef struct node
{
    char *val;
    struct node *next;
} node_t;

node_t *lex(char *unit_stream);

#endif