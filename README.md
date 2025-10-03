# Tarea 5 - De funciones sueltas a headers reutilizables

## Objetivo
- Pasar funciones sueltas a un esquema reusable por headers + fuentes.
- Mantener el enfoque recursivo de T4. Puedes agregar funciones auxiliares si lo necesitas.

## Estructura del Proyecto 
```
/Tarea5-Headers
  /include
    factorial.h        # factorial(n)
    sumatoria.h        # suma 1..n
    fibonacci.h        # F(n)
    potencia.h         # base^exponente
    conteo.h           # regresivo n..1
    suma_arreglo.h     # suma recursiva arreglo
    hanoi.h            # Torres de Hanoi
    permutaciones.h    # permutaciones de cadena
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

## Mapa Modulo -> Ejercicio T4
| Modulo             | Ejercicio de T4 que implementa |
|--------------------|---------------------------------|
| `factorial`        | Factorial recursivo             |
| `sumatoria`        | Suma 1..n recursiva             |
| `fibonacci`        | Fibonacci recursivo (sin memoizacion) |
| `potencia`         | Potencia recursiva (exponente >= 0) |
| `conteo`           | Conteo regresivo n..1           |
| `suma_arreglo`     | Suma recursiva de arreglo       |
| `hanoi`            | Torres de Hanoi                 |
| `permutaciones`    | Permutaciones de una cadena (backtracking) |

## Decisiones de Diseno
- Separacion `.h/.cpp`: headers solo con declaraciones; definiciones en `src/`.
- Casos base por modulo:
  - `factorial`: `0! = 1` y `1! = 1`.
  - `sumatoria`: `sumatoria(0) = 0`.
  - `fibonacci`: `F(0) = 0`, `F(1) = 1`.
  - `potencia`: `exponente == 0 -> 1` (se usa exponenciacion rapida cuando `exponente` es par).
  - `conteo`: `n <= 0` no imprime (termina).
  - `suma_arreglo`: `n == 0 -> 0`.
  - `hanoi`: `n == 1` mueve un disco y termina.
  - `permutaciones`: auxiliar interna `permutar(s, l, r)` con base `l == r` imprime.
- Auxiliares usadas: `permutaciones` usa una funcion estatica auxiliar para backtracking; el resto trabaja directo.
- E/S: `conteo`, `hanoi` y `permutaciones` imprimen a `std::cout`; las demas funciones retornan valores.

## Mejoras
- Implementadas en el proyecto:
  - Control de errores con `std::invalid_argument` en entradas invalidas (`factorial`, `sumatoria`, `fibonacci`, `potencia`, `suma_arreglo`, `hanoi`).
  - Lectura robusta en `main.cpp` con validacion y limpieza de entrada.
  - `potencia` usa exponenciacion rapida (mejor complejidad vs. recursion lineal).
  - `suma_arreglo` valida `arr != nullptr` cuando `n > 0`.
- Opcionales (no implementadas aun):
  - Memoizacion en `fibonacci` para reducir complejidad a O(n).
  - Version iterativa alternativa para `fibonacci`/`factorial` para comparacion de rendimiento.
  - Manejo de enteros grandes (bibliotecas de big integers) para evitar overflow en `long long`.
  - Variantes que no impriman en `conteo/hanoi/permutaciones` sino que devuelvan estructuras (p. ej., vector de pasos).


## Como compilar
- Visual Studio 2022
  - Abre `Tarea5-Headers/Tarea5-Headers.sln`.
  - Configuracion: `Debug|x64` (o `Release|x64`).
  - Build -> Build Solution.
- Consola (g++)
  - Ubicate en `Tarea5-Headers/` y ejecuta:
    - Windows: `g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o tarea5.exe`
    - Linux/macOS: `g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o tarea5 && ./tarea5`

## Notas
- Posibles desbordes en `long long` para entradas grandes.
- `fibonacci(n)` sin memoizacion es costoso para `n` grandes.
- Recomendado tener `.gitignore` para ignorar `.vs/`, `bin/`, `obj/` y archivos temporales.

