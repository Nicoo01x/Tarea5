#include "../include/permutaciones.h"
#include <iostream>

// Auxiliar recursiva para permutar en el rango [l, r].
static void permutar(std::string& s, int l, int r) {
    if (l == r) {
        std::cout << s << std::endl;
        return;
    }
    for (int i = l; i <= r; ++i) {
        std::swap(s[l], s[i]);
        permutar(s, l + 1, r);
        std::swap(s[l], s[i]); // backtrack
    }
}

// Imprime todas las permutaciones de la cadena s. Para s vacía imprime "(vacía)".
void permutaciones(const std::string& s) {
    if (s.empty()) {
        std::cout << "(vacía)" << std::endl;
        return;
    }
    std::string copia = s;
    permutar(copia, 0, static_cast<int>(copia.size()) - 1);
}

