#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/lex.h"

#define PROJECT_NAME "sunflower"

int main(int argc, char **argv)
{
    char *input = (char *)malloc(8 * sizeof(char));
    node_t *lexed;
    node_t *next;

    if (argc != 1)
    {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);

    strcpy(input, "example");

    lexed = lex(input);
    free(input);
    // while (lexed)
    // {
    //     next = lexed->next;
    //     free(lexed);
    //     lexed = next;
    // }

    return 0;
}
