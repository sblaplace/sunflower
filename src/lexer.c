#include <string.h>
#include <stdlib.h>
#include "lexer.h"

node_t *lex(char *unit_stream)
{
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));

    while (*unit_stream != 0)
    {

        *unit_stream++;
    }

    return head;
}