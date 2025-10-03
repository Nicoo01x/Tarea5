#include "../include/conteo.h"
#include <iostream>

// Imprime n, n-1, ..., 1. Caso base: n <= 0 -> no imprime.
void conteo(int n) {
    if (n <= 0) return;
    std::cout << n;
    if (n > 1) std::cout << " ";
    conteo(n - 1);
}

