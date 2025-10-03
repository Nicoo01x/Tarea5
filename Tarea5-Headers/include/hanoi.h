#pragma once

// Resuelve Torres de Hanoi e imprime movimientos "X -> Y".
// Caso base: n == 1 -> mover un disco.
// Precondición: n >= 1.
void hanoi(int n, char origen, char auxiliar, char destino);

