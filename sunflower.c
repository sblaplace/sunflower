#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "src/lexer.h"

#define PROJECT_NAME "sunflower"

int main(int argc, char **argv)
{
    char *input = (char *)malloc(8 * sizeof(char));
    node_t *lexed;

    if (argc != 1)
    {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);

    strcpy("example", input);

    lexed = lex(input);
    free(input);

    return 0;
}
