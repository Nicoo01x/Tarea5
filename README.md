# Tarea 5 — De funciones sueltas a headers reutilizables 

## Objetivo
- Pasar funciones sueltas a un esquema reusable por headers + fuentes.
- Mantener el enfoque recursivo de T4. Podés agregar funciones auxiliares si lo necesitás.

## Estructura del Proyecto 
```
/Tarea5-Headers
  /include
    factorial.h
    sumatoria.h       # suma 1..n
    fibonacci.h
    potencia.h
    conteo.h          # regresivo n..1
    suma_arreglo.h
    hanoi.h
    permutaciones.h
  /src
    factorial.cpp
    sumatoria.cpp
    fibonacci.cpp
    potencia.cpp
    conteo.cpp
    suma_arreglo.cpp
    hanoi.cpp
    permutaciones.cpp
  main.cpp
  Tarea5-Headers.sln

```


## Módulos (interfaz y comportamiento)
- `factorial.h/.cpp`
  - Firma: `long long factorial(int n);`
  - Recursivo. Casos base: `0! = 1`, `1! = 1`. Precondición: `n >= 0`.
- `sumatoria.h/.cpp` (suma 1..n)
  - Firma: `long long sumatoria(int n);`
  - Recursivo. Caso base: `sumatoria(0) = 0`. Precondición: `n >= 0`.
- `fibonacci.h/.cpp`
  - Firma: `long long fibonacci(int n);`
  - Recursivo simple. Casos base: `F(0)=0`, `F(1)=1`. Precondición: `n >= 0`.
- `potencia.h/.cpp`
  - Firma: `long long potencia(long long base, int exponente);`
  - Recursivo con exponenciación rápida. Caso base: `e=0 → 1`. Precondición: `e >= 0`.
- `conteo.h/.cpp` (regresivo n..1)
  - Firma: `void conteo(int n);`
  - Imprime `n, n-1, ..., 1`. Caso base: `n <= 0` no imprime.
- `suma_arreglo.h/.cpp`
  - Firma: `long long suma_arreglo(const int* arr, int n);`
  - Recursivo. Caso base: `n==0 → 0`. Precondiciones: `n >= 0`; si `n>0`, `arr != nullptr`.
- `hanoi.h/.cpp`
  - Firma: `void hanoi(int n, char origen, char auxiliar, char destino);`
  - Imprime movimientos para trasladar `n` discos. Precondición: `n >= 1`.
- `permutaciones.h/.cpp`
  - Firma: `void permutaciones(const std::string& s);`
  - Backtracking recursivo (usa auxiliar interna). Para cadena vacía imprime "(vacía)".

## Decisiones de diseño
- Separación clara `.h/.cpp`: headers solo con declaraciones, definiciones en `src/`.
- Validaciones: se lanzan `std::invalid_argument` en entradas inválidas.
- E/S: `conteo`, `hanoi` y `permutaciones` imprimen a `std::cout`; el resto retorna valores (`long long`).
- Complejidad: `fibonacci` es exponencial por mantener el enfoque T4; `potencia` usa exponenciación rápida.

## Requisitos
- C++17 o superior.
- Visual Studio 2022 (v143) o g++/clang++ en consola.

## Cómo compilar
- Visual Studio 2022
  - Abrí `Tarea5-Headers/Tarea5-Headers.sln`.
  - Configuración: `Debug|x64` (o `Release|x64`).
  - Build → Build Solution.
- Consola (g++)
  - Ubicate en `Tarea5-Headers/` y ejecutá:
    - Windows: `g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o tarea5.exe`
    - Linux/macOS: `g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o tarea5 && ./tarea5`

## Uso y pruebas
- `main.cpp` ofrece un menú interactivo que ejercita todas las funciones, incluyendo casos base y de borde.

## Notas
- Posibles desbordes en `long long` para entradas grandes (no se controla a propósito).
- `fibonacci(n)` sin memoización es costoso para `n` grandes.
- Recomendado tener `.gitignore` para ignorar `.vs/`, `bin/`, `obj/`, y archivos temporales.
