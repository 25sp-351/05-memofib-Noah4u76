#include <stdio.h>
#include "fibonacci.h"       
#include "fibonacci_cache.h" 

long_long_func_ptr fibonacci_pointer = NULL;

typedef struct {
    int term;           // Position in the Fibonacci sequence.
    long long expected; 
} TestCase;

void run_tests(void) {
    // test cases
    TestCase tests[] = {
        {0, 0},
        {1, 1},
        {2, 1},
        {3, 2},
        {4, 3},
        {5, 5},
        {6, 8},
        {10, 55},
        {20, 6765},
        {30, 832040},
        {50, 12586269025LL},
        {91, 4660046610375530309LL}
    };

    int numTests = sizeof(tests) / sizeof(tests[0]);
    int allPassed = 1;

    for (int i = 0; i < numTests; i++) {
        clear_cache();
        printf("\n--- Computing fib(%d) ---\n", tests[i].term);
        long long result = fibonacci_pointer(tests[i].term);
        if (result != tests[i].expected) {
            printf("Test failed for term %d: expected %lld, got %lld\n",
                   tests[i].term, tests[i].expected, result);
            allPassed = 0;
        } else {
            printf("Test passed for term %d: %lld\n", tests[i].term, result);
        }
    }

    if (allPassed)
        printf("\nAll tests passed.\n");
    else
        printf("\nSome tests failed.\n");
}

int main(void)
{
    // Use the memoized Fibonacci
    fibonacci_pointer = cache_fibonacci;

    run_tests();

    return 0;
}

