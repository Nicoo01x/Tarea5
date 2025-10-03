#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>

#include "include/factorial.h"
#include "include/sumatoria.h"
#include "include/fibonacci.h"
#include "include/potencia.h"
#include "include/conteo.h"
#include "include/suma_arreglo.h"
#include "include/hanoi.h"
#include "include/permutaciones.h"

using namespace std;

static void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

static int leerEntero(const string& prompt) {
    while (true) {
        cout << prompt;
        int v;
        if (cin >> v) return v;
        cout << "Entrada invalida. Intenta de nuevo.\n";
        limpiarEntrada();
    }
}

static long long leerLongLong(const string& prompt) {
    while (true) {
        cout << prompt;
        long long v;
        if (cin >> v) return v;
        cout << "Entrada invalida. Intenta de nuevo.\n";
        limpiarEntrada();
    }
}

static string leerLinea(const string& prompt) {
    cout << prompt;
    string s;
    getline(cin >> ws, s);
    return s;
}

static void mostrarMenu() {
    cout << "\n== Menu de Operaciones Recursivas ==\n";
    cout << "1) Calcular factorial de un numero (n!)\n";
    cout << "2) Calcular sumatoria de 1 a n\n";
    cout << "3) Obtener el n-esimo numero de Fibonacci\n";
    cout << "4) Calcular potencia: base^exponente\n";
    cout << "5) Conteo regresivo desde n hasta 1\n";
    cout << "6) Sumar elementos de un arreglo (recursivo)\n";
    cout << "7) Resolver Torres de Hanoi\n";
    cout << "8) Listar permutaciones de una cadena\n";
    cout << "0) Salir\n";
}

int main() {
    while (true) {
        mostrarMenu();
        int op = leerEntero("Elige una opcion: ");
        try {
            switch (op) {
                case 1: {
                    int n = leerEntero("n (>=0): ");
                    cout << "factorial(" << n << ") = " << factorial(n) << "\n";
                    break;
                }
                case 2: {
                    int n = leerEntero("n (>=0): ");
                    cout << "sumatoria(" << n << ") = " << sumatoria(n) << "\n";
                    break;
                }
                case 3: {
                    int n = leerEntero("n (>=0, cuidado: puede ser lento): ");
                    cout << "fibonacci(" << n << ") = " << fibonacci(n) << "\n";
                    break;
                }
                case 4: {
                    long long base = leerLongLong("base: ");
                    int exp = leerEntero("exponente (>=0): ");
                    cout << "potencia(" << base << ", " << exp << ") = " << potencia(base, exp) << "\n";
                    break;
                }
                case 5: {
                    int n = leerEntero("n (>=1 recomendado): ");
                    cout << "conteo(" << n << "): ";
                    conteo(n);
                    cout << "\n";
                    break;
                }
                case 6: {
                    int n = leerEntero("tamano del arreglo (>=0): ");
                    if (n < 0) {
                        cout << "Error: n debe ser >= 0\n";
                        break;
                    }
                    if (n == 0) {
                        cout << "suma_arreglo([]) = " << suma_arreglo(nullptr, 0) << "\n";
                    } else {
                        vector<int> arr(n);
                        cout << "Ingresa " << n << " enteros separados por espacio: ";
                        for (int i = 0; i < n; ++i) {
                            while (!(cin >> arr[i])) {
                                cout << "Entrada invalida. Reingresa valor para Indice " << i << ": ";
                                limpiarEntrada();
                            }
                        }
                        cout << "suma_arreglo = " << suma_arreglo(arr.data(), n) << "\n";
                    }
                    break;
                }
                case 7: {
                    int n = leerEntero("n discos (>=1): ");
                    cout << "Movimientos (A -> C usando B):\n";
                    hanoi(n, 'A', 'B', 'C');
                    break;
                }
                case 8: {
                    string s = leerLinea("cadena: ");
                    cout << "Permutaciones de \"" << s << "\":\n";
                    permutaciones(s);
                    break;
                }
                case 0:
                    cout << "Saliendo...\n";
                    return 0;
                default:
                    cout << "Opcion invalida. Intenta de nuevo.\n";
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
            limpiarEntrada();
        }
    }
}
