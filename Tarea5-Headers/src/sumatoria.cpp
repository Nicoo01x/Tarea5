#include "../include/sumatoria.h"
#include <stdexcept>

// Suma 1..n recursivamente. Caso base: sumatoria(0) = 0. Precondición: n >= 0.
long long sumatoria(int n) {
    if (n < 0) throw std::invalid_argument("sumatoria: n debe ser >= 0");
    if (n == 0) return 0;
    return n + sumatoria(n - 1);
}

