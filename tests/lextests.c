#include "munit.h"
#include "../src/lex.h"

static void*
test_setup(const MunitParameter params[], void* user_data) {
  return strdup("Hello, world!");
}

static void
test_tear_down(void* fixture) {
  free(fixture);
}

static MunitResult test(const MunitParameter params[], void* fixture) {
  char* str = (char*) fixture;
  munit_assert_string_equal(str, "Hello, world!");
  return MUNIT_OK;
}

static MunitResult test_empty_string(const MunitParameter params[], void* fixture) {
  munit_assert_string_equal(lex(""), "");
  return MUNIT_OK;
}

MunitTest tests[] = {
  {
    "/my-test", /* name */
    test, /* test */
    test_setup, /* setup */
    test_tear_down, /* tear_down */
    MUNIT_TEST_OPTION_NONE, /* options */
    NULL /* parameters */
  },
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