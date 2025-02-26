#ifndef FIBONACCI_CACHE_H
#define FIBONACCI_CACHE_H

#include "fibonacci.h"

// Sentinel value indicating that a Fibonacci number is not yet cached.
#define NOT_PRESENT (-1LL)

// Max
#define FIB_MAX 91

long long cache_fibonacci(int term);

// clear the memoization cache.
void clear_cache(void);

#endif
