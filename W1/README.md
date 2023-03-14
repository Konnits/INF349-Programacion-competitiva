# Semana 1

Se realizaron principalmente algunos de los ejercicios introductorios de la página [CSES](https://cses.fi/problemset/).

## [Weird Algorithm](https://cses.fi/problemset/task/1068)
Consideremos un algoritmo que toma como input un entero *n*. Si *n* es un número par, el algoritmo lo divide por dos y si es impar lo multiplica por tres y le agrega uno. Esta algoritmo se repite hasta que el valor es uno. Por ejemplo, la sucesión para $n = 3$ es como sigue:

<p align="center">
  $3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$
</p>

La tarea es simular la ejecución de este algoritmo para un valor **n**.
### Input
El único input que debe recibir el programa es un entero **n**.

### Output
Mostrar por pantalla un línea que contenga todos los valores de **n** durante el algoritmo.

## [Number Spiral](https://cses.fi/problemset/task/1071)
Un número espiral es una grilla infinita, cuyo elemento en la esquina izquierda superior es el número 1. A continuación se muestran las primeras 5 capas:

<p align="center">
| Attempt | #1    | #2    |
| :---:   | :---: | :---: |
| Seconds | 301   | 283   |
</p>

## [Missing Number](https://cses.fi/problemset/task/1083)
Tendremos todos los números entre $1,2, ..., n$; con exepción de uno. La tarea es encontrar el número faltante.

### Input
Tendremos dos líneas de inputs, la primera es un entero **n**.

La segunda línea de input contendrá $n-1$ números, cada uno separado por un espacio. Cada uno será distinto y además estarán entre **1** y **n**, inclusive.

### Output
Mostrar por pantalla el número faltante.

## [Repetitions](https://cses.fi/problemset/task/1069)
Tendremos una secuencia de **ADN**, es decir, un string que contiene una sucesión de los caracteres A, C, G y T. La tarea es encontrar la repetición más larga y continua de un mismo carácter.

### Input
Una secuencia de **ADN**.

### Output
Mostrar por pantalla el entero que representa el largo de la cadena más larga, mencionada anteriormente.

## [Increasing Array](https://cses.fi/problemset/task/1094)
Tendremos un arreglo de **n** enteros. La tarea es modificar el arreglo de tal forma que este sea creciente, es decir, cada elemento es más grande o igual que el anterior.

Para lograr la tarea, se poseen movimientos, aumentar en una unidad un elemento del arreglo, ¿Cuál es el mínimo número de movimientos requeridos?

### Input
La primera línea de input será un entero **n**.

La segunda línea será una secuencia de **n** enteros que conforman el arreglo.

### Output
Mostrar por pantalla el número mínimo de elementos para hacer que el arreglo sea creciente.

## [Permutations](https://cses.fi/problemset/task/1070)
Una permutación se enteros $1, ..., n$ se dice que es **beautiful** o en español **hermosa** si no existe ningún par de elementos adyacentes que difieran en una unidad.

Dado un entero **n**, el objetivo es construir una permutación hermosa, si existe.

### Input
El único input del programa es un entero **n**.

### Output
Mostrar por pantalla una permutación hermosa de $1, ..., n$ enteros. Si es que existe la permutación, se puede imprimir cualquiera de las posibles. Si no existe tiene que imprimir "NO SOLUTION".

## [Gray Code](https://cses.fi/problemset/task/2205)

Un *Gray Code* es una lista de todas los posibles strings de largo **n**, donde cada par de strings sucesivos difieren exactamente en un solo bit (En otras palabras la distancia de Hamming es exactamente uno).

### Input
El único input que debe recibir el programa es un entero **n**.

### Output
Mostrar por pantalla las $2^n$ línas que describen el *Gray Code*. Se admite cualquier solución válida.
