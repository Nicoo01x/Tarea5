#include "../include/suma_arreglo.h"
#include <stdexcept>

// Suma recursivamente los n primeros elementos. Caso base: n==0 -> 0.
long long suma_arreglo(const int* arr, int n) {
    if (n < 0) throw std::invalid_argument("suma_arreglo: n debe ser >= 0");
    if (n == 0) return 0;
    if (arr == nullptr) throw std::invalid_argument("suma_arreglo: arr no debe ser nullptr cuando n > 0");
    return arr[n - 1] + suma_arreglo(arr, n - 1);
}

