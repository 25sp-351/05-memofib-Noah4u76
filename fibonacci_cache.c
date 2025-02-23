#include "fibonacci_cache.h"
#include <stdio.h>

// Cache array 0 .. FIB_MAX (91)
static long long memoizedResults[FIB_MAX + 1] = { [0 ... FIB_MAX] = NOT_PRESENT };

long long cache_fibonacci(int term)
{
    if (term < 0 || term > FIB_MAX)
        return 0;

    if (term < 2) {
        printf("[Base] fib(%d) = %d\n", term, term);
        memoizedResults[term] = term;
        return term;
    }

    // computed before, return the cached
    if (memoizedResults[term] != NOT_PRESENT) {
        printf("[Cache] fib(%d) = %lld\n", term, memoizedResults[term]);
        return memoizedResults[term];
    }

    // Otherwise, compute recursively.
    printf("[Compute] fib(%d) = fib(%d) + fib(%d)\n", term, term - 1, term - 2);
    long long previousTerm = cache_fibonacci(term - 1);
    long long beforePreviousTerm = cache_fibonacci(term - 2);
    memoizedResults[term] = previousTerm + beforePreviousTerm;

    printf("[Result] fib(%d) = %lld  (%lld + %lld)\n", term, memoizedResults[term], previousTerm, beforePreviousTerm);
    return memoizedResults[term];
}

void clear_cache(void)
{
    for (int index = 0; index <= FIB_MAX; index++) {
        memoizedResults[index] = NOT_PRESENT;
    }
}
