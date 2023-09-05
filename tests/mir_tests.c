#include "munit.h"
#include "src/mir.h"
#include "src/parse.h"

static MunitResult test_empty_string(const MunitParameter params[], void *fixture)
{
    char *llvm_ir = "testingtesting.\n"
                    "line2testing.";

    ast_t *parsed = malloc(sizeof(ast_t));
    munit_assert_string_equal(lower(parsed)->val, llvm_ir);
    return MUNIT_OK;
}

MunitTest compile_tests[] = {
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
    "/compile-tests",       /* name */
    compile_tests,          /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, const char *argv[])
{
    return munit_suite_main(&suite, NULL, argc, argv);
}