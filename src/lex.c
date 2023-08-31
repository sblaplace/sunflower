#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

node_t *lex(char *unit_stream)
{
    node_t *head = NULL;
    node_t *current = NULL;
    char *val;

    head = (node_t *)malloc(sizeof(node_t));
    current = (node_t *)malloc(sizeof(node_t));
    val = malloc(sizeof(char) * 6);
    strcpy(val, "START");
    current = &(node_t){.val = val, .next = NULL};
    head = current;

    while (*unit_stream != '\0')
    {
        switch (*unit_stream)
        {
        case ';':
            val = malloc(sizeof(char) * 5);
            strcpy(val, "ENDL");
            current->next = &(node_t){.val = val, .next = NULL};
            current = current->next;
            break;
        default:
            break;
        }

        unit_stream++;
    }

    val = malloc(sizeof(char) * 1);
    strcpy(val, "");
    current->next = &(node_t){.val = val, .next = NULL};
    current = current->next;

    printf("%p\n", head);
    printf("%s\n", head->val);
    printf("%s\n", head->next->val);

    return head;
}