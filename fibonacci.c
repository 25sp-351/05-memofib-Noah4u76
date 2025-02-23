#include "fibonacci.h"

long long fibonacci(int n)
{
    // fib(0) = 0, fib(1) = 1
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
