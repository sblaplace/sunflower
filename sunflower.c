#include <stdio.h>

#define PROJECT_NAME "sunflower"

void lex(char* program_str) {
    while (*program_str) {
        switch (program_str[0]) {

        }
        *(program_str++) = '0';
    }
}

void parse() {}

void eval() {}

int main(int argc, char **argv) {
    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);
    return 0;
}
