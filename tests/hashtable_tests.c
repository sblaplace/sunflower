#include "munit.h"
#include "src/hashtable.h"

static MunitResult test_get(const MunitParameter params[], void *fixture)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    return MUNIT_OK;
}

static MunitResult test_set(const MunitParameter params[], void *fixture)
{
    return MUNIT_OK;
}

static MunitResult test_hash(const MunitParameter params[], void *fixture)
{
    munit_assert_string_equal(hash("a"), 0);
    return MUNIT_OK;
}

MunitTest hashtable_tests[] = {
    /* Mark the end of the array with an entry where the test
     * function is NULL */
    {
        "/get",                 /* name */
        test_get,               /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    {
        "/set",                 /* name */
        test_set,               /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
    {
        "/hash",                /* name */
        test_hash,              /* test */
        NULL,                   /* setup */
        NULL,                   /* tear_down */
        MUNIT_TEST_OPTION_NONE, /* options */
        NULL                    /* parameters */
    },
};

static const MunitSuite suite = {
    "/hashtable-tests",     /* name */
    hashtable_tests,        /* tests */
    NULL,                   /* suites */
    1,                      /* iterations */
    MUNIT_SUITE_OPTION_NONE /* options */
};

int main(int argc, const char *argv[])
{
    return munit_suite_main(&suite, NULL, argc, argv);
}