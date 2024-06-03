#include <stdio.h>
#include <stdlib.h>

#include "test_framework.h"

test_case_t tests[MAX_TESTS];
int test_count = 0;

void run_all_tests()
{
    bool result;

    for (int i = 0; i < test_count; ++i)
    {
        result = tests[i].func();

        if (!result)
        {
            printf("\033[32mPASSED:\033[0m %s\n", tests[i].name);
        }
    }
}

int main(int argc, char **argv)
{
    run_all_tests();

    printf("All %d tests completed.\n", test_count);

    return 0;
}
