#include "../include/potencia.h"
#include <stdexcept>

// Potencia recursiva por exponenciación rápida. Caso base: e==0 -> 1. Precondición: e >= 0.
long long potencia(long long base, int exponente) {
    if (exponente < 0) throw std::invalid_argument("potencia: exponente debe ser >= 0");
    if (exponente == 0) return 1;
    if (exponente % 2 == 0) {
        long long mitad = potencia(base, exponente / 2);
        return mitad * mitad;
    }
    return base * potencia(base, exponente - 1);
}

