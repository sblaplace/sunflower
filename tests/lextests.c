#include "munit.h"
#include "../src/lex.h"

static MunitResult test_empty_string(const MunitParameter params[], void* fixture) {
  munit_assert_string_equal(lex(""), "");
  return MUNIT_OK;
}

static MunitResult test_fn(const MunitParameter params[], void* fixture) {
  munit_assert_string_equal(lex("fn"), "");
  return MUNIT_OK;
}


MunitTest tests[] = {
    {
    "/lex-empty-string", /* name */
    test_empty_string, /* test */
    NULL, /* setup */
    NULL, /* tear_down */
    MUNIT_TEST_OPTION_NONE, /* options */
    NULL /* parameters */
  },
  /* Mark the end of the array with an entry where the test
   * function is NULL */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/lex-tests", /* name */
  tests, /* tests */
  NULL, /* suites */
  1, /* iterations */
  MUNIT_SUITE_OPTION_NONE /* options */
};

int main (int argc, const char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}