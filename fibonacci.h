#ifndef FIBONACCI_H
#define FIBONACCI_H

// "term" (the position in the sequence)
typedef long long (*long_long_func_ptr)(int term);

long long fibonacci(int term);

// Global pointer that can point to either the plain or memoized Fibonacci function.
extern long_long_func_ptr fibonacci_pointer;

#endif
