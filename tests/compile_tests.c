#include "munit.h"
#include "src/compile.h"

MunitTest compile_tests[] = {
    /* Mark the end of the array with an entry where the test
     * function is NULL */
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

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