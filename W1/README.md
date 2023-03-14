# Semana 1

Se realizaron principalmente algunos de los ejercicios introductorios de la página [CSES](https://cses.fi/problemset/).

## [Weird Algorithm](https://cses.fi/problemset/task/1068)
Consideremos un algoritmo que toma como input un entero *n*. Si *n* es un número par, el algoritmo lo divide por dos y si es impar lo multiplica por tres y le agrega uno. Esta algoritmo se repite hasta que el valor es uno. Por ejemplo, la sucesión para $n = 3$ es como sigue:

<p align="center">
  $3 \rightarrow 10 \rightarrow 5 \rightarrow 16 \rightarrow 8 \rightarrow 4 \rightarrow 2 \rightarrow 1$
</p>

La tarea es simular la ejecución de este algoritmo para un valor **n**.
**Input**
El único input que debe recibir el programa es un entero **n**.

**Output**
Mostrar por pantalla un línea que contenga todos los valores de **n** durante el algoritmo.

## [Gray Code](https://cses.fi/problemset/task/2205)

Un *Gray Code* es una lista de todas los posibles strings de largo **n**, donde cada par de strings sucesivos difieren exactamente en un solo bit (En otras palabras la distancia de Hamming es exactamente uno).

**Input**
El único input que debe recibir el programa es un entero **n**.

**Output**
Mostrar por pantalla las $2^n$ línas que describen el *Gray Code*. Se admite cualquier solución válida.
