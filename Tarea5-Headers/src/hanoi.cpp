#include "../include/hanoi.h"
#include <iostream>
#include <stdexcept>

// Imprime los movimientos para trasladar n discos de 'origen' a 'destino' usando 'auxiliar'.
void hanoi(int n, char origen, char auxiliar, char destino) {
    if (n <= 0) throw std::invalid_argument("hanoi: n debe ser >= 1");
    if (n == 1) {
        std::cout << origen << " -> " << destino << std::endl;
        return;
    }
    hanoi(n - 1, origen, destino, auxiliar);
    std::cout << origen << " -> " << destino << std::endl;
    hanoi(n - 1, auxiliar, origen, destino);
}

