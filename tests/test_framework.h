#ifndef TESTFRAMEWORK_H
#define TESTFRAMEWORK_H

#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <math.h>

typedef bool (*test_func_t)(void);

typedef struct
{
    const char *name;
    test_func_t func;
} test_case_t;

#define MAX_TESTS 1000

extern test_case_t tests[MAX_TESTS];
extern int test_count;

#define TEST(testname)                                                 \
    bool testname(void);                                               \
    static void __attribute__((constructor)) register_##testname(void) \
    {                                                                  \
        tests[test_count].name = #testname;                            \
        tests[test_count].func = testname;                             \
        test_count++;                                                  \
    }                                                                  \
    bool testname(void)

#define ASSERT_EQ(expected, actual)                                                                                           \
    if ((expected) != (actual))                                                                                               \
    {                                                                                                                         \
        std::cout << "\033[31mFAILED:\033[0m " << __FILE__ << ":" << __LINE__ << " " << __func__ << ":                        \
        expected " << (expected) << ", got " << (actual) << std::endl;                                                        \
        return false;                                                                                                         \
    }

#define ASSERT_FLOAT_EQ(expected, actual)                                                                                     \
    if (fabs((expected) - (actual)) > 1e-6)                                                                                   \
    {                                                                                                                         \
        printf("\033[31mFAILED:\033[0m %s:%d %s: expected %f, got %f\n", __FILE__, __LINE__, __func__, (expected), (actual)); \
        return false;                                                                                                         \
    }

#define ASSERT_TRUE(expr)                                                                                    \
    if (!(expr))                                                                                             \
    {                                                                                                        \
        printf("\033[31mFAILED:\033[0m %s:%d %s: expected true, got false\n", __FILE__, __LINE__, __func__); \
        return false;                                                                                        \
    }

#define ASSERT_FALSE(expr)                                                                                   \
    if (expr)                                                                                                \
    {                                                                                                        \
        printf("\033[31mFAILED:\033[0m %s:%d %s: expected false, got true\n", __FILE__, __LINE__, __func__); \
        return false;                                                                                        \
    }

#endif