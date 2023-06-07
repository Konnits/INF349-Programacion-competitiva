# Disjoint sets union (DSU) o union find

En este tutorial estudiaremos la estructura de datos Union Find, que permite encontrar elementos que pertenecen o no a un conjunto determinado. Las aplicaciones de esta estructura son múltiples, variando desde encontrar elementos que pertenecen a un conjunto a conectividad de redes. Como os imaginaréis hay dos operaciones principales, la unión de conjuntos y la búsqueda de elementos.


## Definición de Union find

DSU se almacena conceptualmente utilizando árboles, cuya implementación será en nuestro caso un array o vector. Inicialmente tendremos los elementos separados y a través de la operación `union_set(e1, e2)`, donde `e1` y `e2` son dos objetos, iremos creando la estructura. Por ejemplo, tenemos el siguiente vector con objetos:

| 1    | 3    | 2    | 6    | 9    | 4    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |

Podemos generar los siguientes conjuntos disjuntos: {1,3}, 2, 6, {9,4,3,5}. Estos conjuntos disjuntos pueden representar las conexiones de una red por ejemplo: los router 1 y 3 están conectados o sirven a X subred, los nodos 9, 4, 3 y 5 lo mismo. Con DSU es muy sencillo encontrar qué nodos están conectados entre sí, a cuáles afecta una política X, o incluso averiguar si hay ciclos en una red. Inicialmente todos los elementos del vector están en su propio set:

| 1    | 3    | 2    | 6    | 9    | 4    | 7    | 5    |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |

Para ir uniendo los elementos del vector realziamos la operación `union_set(e1, e2)` y asignamos un índice común a ambos elementos. Por ejemplo, vamos a ejecutar `union_set(2, 4)` y cambiamos el índice del elemento 4 por un 3 (antes era el 6). Se elige un índice de forma aleatoria.

| 1    | 3    | 2     | 6    | 9    | 4     | 7    | 5    |
| ---- | ---- | ----- | ---- | ---- | ----- | ---- | ---- |
| 1    | 2    | **3** | 4    | 5    | **3** | 7    | 8    |

En este punto es posible realizar ciertas optimizaciones para mejorar la eficiencia al unir varios conjuntos (o elementos que pertenecen a conjuntos distintos), pero eso lo veremos más adelante (path compression).

### Implementación Naïve (ingenua)

En esta implementación inicial tenemos que implementar las operaciones `make_set(int v)` (crea un conjunto cuya raíz será v), `find_set(int v)`(encuentra el set al que pertenece v) y `union_set(in a, int b)`(realiza la unión de a y b en el mismo set).



```C++
void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}
```



Como intuíamos anteriormente, la operación `find_set(v)` es ineficiente ya que en el peor de los casos puede necesitar tiempo *O(n)* ya que ha de recorrer todos los índices que apuntan al padre. Para optimizarlo se puede utilizar una optimización bastante simple que consiste en *comprimir* el camino que lleva al identificador del conjunto. Esta compresión se realiza poniendo siempre como identificador al mismo elemento (al realizar el find del representante del conjunto). De aquí nos surge otra duda: ¿cómo identificamos que elemento es el representante del conjunto? Para poder identificarlo crearemos una estructura (o un vector) para los nodos en la cual almacenaremos un ranking que representará la cantidad de elementos que dependen de ese nodo (rank). 



### Optimización *path compression*

La optimización utilizando path compression modifica el método `find_set` quedando de la siguiente forma:

```c++
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
```

Simplemente busca al representante del conjunto y mientras retorna de la función recursiva asigna el mismo representante a todos los elementos que ha ido visitando esa función. La complejidad de búsqueda se reduce a *O*(log*n*). 

### Optimización a través de rango

Como observábamos con anterioridad debemos identificar al padre de alguna forma y para ello tenemos que añadir un atributo a los elementos y también cambiar el método `union_set`:

```c++
void make_set(int v) {
    parent[v] = v;
    // usamos un vector para almacenar el rango del nodo representante
    size[v] = 1;
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
```



La complejidad de la operación amortizada es *O(α(n))*, donde *α*(*n*) es el inverso de la función Ackermann (amortizado significa aquí el tiempo total por operación evaluado en un conjunto continuado de múltiples operaciones).

En general, DSU con compresión y ranking funciona en tiempo *O(log(n))* por consulta.

