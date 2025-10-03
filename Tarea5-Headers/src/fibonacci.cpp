#include "../include/fibonacci.h"
#include <stdexcept>

// Fibonacci recursivo. Caso base: F(0)=0, F(1)=1. Precondición: n >= 0.
long long fibonacci(int n) {
    if (n < 0) throw std::invalid_argument("fibonacci: n debe ser >= 0");
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

