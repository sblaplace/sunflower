#include "munit.h"
#include "src/parse.h"
#include "src/lex.h"

static MunitResult test_empty_string(const MunitParameter params[], void *fixture)
{
    char *valstart = malloc(sizeof(char) * 6);
    char *valend = malloc(sizeof(char) * 1);
    strcpy(valstart, "START");
    strcpy(valend, "");
    node_t *end = malloc(sizeof(node_t));
    node_t *lexed = malloc(sizeof(node_t));
    end->val = valend;
    end->next = NULL;
    lexed->val = valstart;
    lexed->next = end;
    munit_assert_string_equal(parse(lexed)->val, "");
    return MUNIT_OK;
}

MunitTest parse_tests[] = {
    /* Mark the end of the array with an entry where the test
     * function is NULL */
    {
        "/empty-string",        /* name */
        test_empty_string,      /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
};

static const MunitSuite suite = {
    "/parse-tests",         /* name */
    parse_tests,            /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, const char *argv[])
{
    return munit_suite_main(&suite, NULL, argc, argv);
}