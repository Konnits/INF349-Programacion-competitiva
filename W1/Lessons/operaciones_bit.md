# Operaciones de bit para Programación Competitiva

Las operaciones de bit son operaciones que se ejecutan sobre bits en tiempo constante (O(1)). Esto hace que sean muy rápidas y por lo tanto útiles para resolver problemas con un tiempo límite muy ajustado. Los requisitos para poder utilizar este tipo de operaciones es conocer los fundamentos del [sistema binario](https://es.wikipedia.org/wiki/Sistema_binario) (17 = 16 * 1 + 0 * 8 + 0 * 4 + 0 * 2 + 1 * 1 = 10001) y sus operaciones AND, OR y XOR entre otras.

## Operaciones AND, OR y XOR 

Estas operaciones son las habituales:

 - `1001 & 1000 = 1000` 
 - `1001 | 1010 = 1011` 
 - `1001 ^ 1000 = 0001` (XOR corresponde al operador != en bits, utilizado frecuentemente para invertir bits en un array/vector)

## Desplazamiento de bits (shift)

Los operadores `<<` y `>>` desplazan los bits en una variable a la izquierda y a la derecha respectivamente (añadiendo 0s en el lado contrario del desplazamiento). Es posible indicar cuántos bits desplazamos de la siguiente forma `17 << 2`, donde desplazamos el número 17 dos bits a la izquierda. Esa operación retorna `17^2` y en general retorna `x^b` siendo `x` la variable a desplazar y `b` la cantidad de bits que desplazamos. De forma similar la operación `>>` desplaza bits a la derecha y en lugar de ejecutar la potencia ejecuta la operación `x/2^b`.

## Operaciones

### Multiplicación y división (<< y >>)

```
N = 34 (base 10) = 100010 (base 2)
N = N<<1 = N*2 = 68 (base 10) = 1000100 (base 2) 
N = N >> 2= N/4 = 17 (base10) = 10001(base2)
N= N >> 1 = N/2= 8 (base10)= 1000 (base 2) <- Desaparece el bit menos significativo
```

### Activar el elemento i-ésimo: N |= (1 << i)

```
N = 34 (base 10) = 100010 (base 2)
j = 3, 1 << i =    001000 <- el bit ‘1’ se mueve a la izquierda 3 veces
                 -------- OR  (cierto si cualquiera de los bits lo 
N = 42 (base 10) = 101010 (base 2) 
```


### Comprobar si el elemento i-ésimo está activado: AND M = N & (1 << i)

```
N = 42 (base 10) = 101010 (base 2)
i = 3, 1 << j =    001000 <- el bit ‘1’ se mueve a la izquierda 3 veces
                  -------- AND          (cierto si los dos bits lo son)
M = 8 (base 10)  = 001000 (base 2) -> no es 0, tercer elemento activado

N = 42 (base 10) = 101010 (base 2)
i = 2, 1 << i =    000100 <- el bit ‘1’ se mueve a la izquierda 2 veces
                 -------- AND
N = 0 (base 10)  = 000000 (base 2) ->   0, segundo elemento desactivado
```

### Desactivar el elemento i-ésimo: AND N &= ∼ (1 << i)

```
N = 42 (base 10) = 101010 (base 2)
i = 1, ~(1<<i)   = 111101 <- ‘~’ es el operador de bits NOT
                 -------- AND
N = 40 (base 10) = 101000 (base 2) // actualiza S al nuevo valor 40
```

### Invertir el estado) el elemento i-ésimo del conjunto: XOR N ∧= (1 << i)

```
N = 40 (base 10) = 101000 (base 2)
i = 2, (1<<i)    = 000100 <- el bit ‘1’ se mueve a la izquierda 2 veces
                 -------- XOR <- cierto si ambos bits son diferentes
N = 44 (base 10) = 101100 (base 2) // actualiza N al nuevo valor 44
N = 40 (base 10) = 101000 (base 2)
i = 3, (1<<i)    = 001000 <- el bit ‘1’ se mueve a la izquierda 3 veces
                 -------- XOR <- cierto si ambos bits son diferentes
N = 32 (base 10) = 100000 (base 2) // actualiza N al nuevo valor 32
```

### Obtener el valor del bit menos significativo de N que está activado M = (N & (-N))

```
 N   =  40 (base 10) =  000...000101000 (32 bits, base 2)
-N   = -40 (base 10) =  111...111011000 (complemento de dos)
                           ----------------- AND
 M   =   8 (base 10) =  000...000001000 (el tercer bit está activado)
 ```
 
 
### Activar todos los bits en un conjunto de tamaño 𝑛,  N = (1 << n) - 

```
N+1 = 8 (base 10) = 1000 <- el bit ‘1’ se mueve a la izquierda 3 veces
                       1 
                  ------ -
N = 7 (base10) =    1111 (base2)
```

### Contar cuántos bits están activados en S

```c++
__builtin_popcount(S)
```
     
## ¿Y qué?

¿Qué podemos hacer con todo esto que hemos visto hasta el momento?
 - Poner a 0 todos los bits excepto uno (o más):
  ```cpp
mask = ~((1 << i+1 ) - 1);
x &= mask;
```
 - Verificar si hay algún bit a 1 en alguna posición de un array/vector: 
  ```cpp
 for(int i = 0; i < 30; i++) {
     if((x & (1 << i)) != 0) cout << i << " ";
 }
 ```
 - O una combinación de las anteriores ([referencia](https://codeforces.com/blog/entry/73490)):
```cpp
for(int mask = 0; mask < (1 << n); mask++) {
	long long sum_of_this_subset = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			sum_of_this_subset += a[i];
		}
	}
	if(sum_of_this_subset == S) {
		puts("YES");
		return 0;
	}
}
puts("NO");
```

### Ejemplo

Por ejemplo, si nos dan 𝑁≤20 números, cada uno hasta 109. ¿Hay algún subconjunto cuya suma sea igual a un número objetivo 𝑆?

Esto es posible resolverlo por fuerza bruta (probando todas las combonaciones), de forma recursiva o con máscaras de bits y fuerza bruta. 

## Bitsets

En lugar de utilizar arrays de booleanos que ocupan relativamente bastante espacio es posible utilizar bitsets. Además, permite realizar operaciones de forma eficiente sobre esos Bitsets:
```cpp
bitset<MAX_D> x[MAX_N];
int interseccion(int i, int j) {
	return (x[i] & x[j]).count();
}
```