#pragma once

// Calcula base^exponente de forma recursiva (exponente entero >= 0).
// Caso base: exponente == 0 -> 1.
// Precondición: exponente >= 0. Puede desbordar.
long long potencia(long long base, int exponente);

