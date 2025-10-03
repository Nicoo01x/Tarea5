#include "../include/factorial.h"
#include <stdexcept>

// Calcula n! recursivamente. Caso base: 0! = 1. Precondición: n >= 0.
long long factorial(int n) {
    if (n < 0) throw std::invalid_argument("factorial: n debe ser >= 0");
    if (n == 0 || n == 1) return 1;
    return static_cast<long long>(n) * factorial(n - 1);
}

