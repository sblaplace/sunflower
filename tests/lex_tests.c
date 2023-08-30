#include "munit.h"
#include "src/lexer.h"

static MunitResult test_empty_string(const MunitParameter params[], void *fixture)
{
  munit_assert_string_equal(lex("")->val, "");
  return MUNIT_OK;
}

static MunitResult test_single_line(const MunitParameter params[], void *fixture)
{
  node_t *res = lex("var a = 1 + 1;");
  munit_assert_string_equal(res->next->val, "a");
  return MUNIT_OK;
}

static MunitResult test_line_end(const MunitParameter params[], void *fixture)
{
  node_t *res = lex("\"a\";");
  munit_assert_string_equal(res->next->val, "ENDL");
  return MUNIT_OK;
}

MunitTest tests[] = {
    {
        "/empty-string",        /* name */
        test_empty_string,      /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    {
        "/single-line",         /* name */
        test_single_line,       /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    {
        "/line-end",            /* name */
        test_line_end,          /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    /* Mark the end of the array with an entry where the test
     * function is NULL */
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

static const MunitSuite suite = {
    "/tests",               /* name */
    tests,                  /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, const char *argv[])
{
  return munit_suite_main(&suite, NULL, argc, argv);
}