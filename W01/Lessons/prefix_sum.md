# Prefix sum: sumas de prefijos

En este tutorial estudiaremos la técnica de suma de prefijos, que usando un pre cálculo de una operación conmutativa permite calcular resultados intermedios de forma eficiente.

## Descripción de la técnica

Asumamos que tenemos una matriz de enteros indexada  $\texttt{arr}$  de tamaño $N$ y queremos calcular el valor de la suma entre dos índices $a$ y $b$:

$$\texttt{arr}[a]+\texttt{arr}[a+1]+\cdots+\texttt{arr}[b]$$

Usaremos el siguiente ejemplo con $N = 6$:

|   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|
|Índice |1 | 2 | 3 | 4 | 5 | 6 |
| arr| 1 | 6 | 4 | 2 | 5 | 3 |

De forma ingénua, para cada consulta podemos iterar a través de todas las entradas del índice $a$ al índice $b$ para sumarlos. El problema es que tenemos $Q$ consultas y cada consulta requiere un máximo de $\mathcal{O}(N)$ operaciones para calcular la suma, siendo nuestra complejidad de tiempo total $\mathcal{O}(NQ)$. Para la mayoría de los problemas de esta naturaleza, las restricciones serán $N, Q \leq 10^5$, entonces $NQ$ esta a la orden de $10^{10}$. Esto no es aceptable; es casi seguro que excederá el límite de tiempo.

En su lugar, podemos usar sumas de prefijos para procesar estas consultas de suma de matriz. Usamos una matriz de suma de prefijos $\texttt{prefix}$. Primero, debido a que estamos indexando en 1 la matriz, hay que establecer $\texttt{prefix}[0]=0$, entonces para índices $k$ tal que $1 \leq k \leq N$, hay que definir la matriz de suma de prefijos de la siguiente forma:

$$\texttt{prefix}[k]=\sum_{i=1}^{k} \texttt{arr}[i]$$

Básicamente, lo que esto significa es que el elemento en el índice $k$ de la matriz de suma de prefijos almacena la suma de todos los elementos en la matriz original del índice $1$ hasta $k$. Esto se puede calcular fácilmente en $\mathcal{O}(N)$ por la siguiente fórmula para cada $1\le k\le N$:

$$\texttt{prefix}[k]=\texttt{prefix}[k-1]+\texttt{arr}[k]$$

Para el caso de ejemplo, nuestra matriz de suma de prefijos se ve así:

|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|Índice | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| prefix| 0 | 1 | 7 | 11 | 13 | 18 | 21 |


Ahora, cuando queremos consultar la suma de los elementos de $\texttt{arr}$ entre índices (1-indexados) $a$ y $b$ inclusive, podemos usar la siguiente fórmula:

$$\sum_{i=L}^{R} \texttt{arr}[i] = \sum_{i=1}^{R} \texttt{arr}[i] - \sum_{i=1}^{L-1} \texttt{arr}[i]$$

Usando nuestra definición de los elementos en la matriz de suma de prefijos, tenemos

$$\sum_{i=L}^{R} \texttt{arr}[i]= \texttt{prefix}[R]-\texttt{prefix}[L-1]$$

Dado que solo estamos consultando dos elementos en la matriz de suma de prefijos, podemos calcular sumas de subarreglo en $\mathcal{O}(1)$ por consulta, que es mucho mejor que el $\mathcal{O}(N)$ por consulta que teníamos antes. Ahora, después de un $\mathcal{O}(N)$ preprocesamiento para calcular la matriz de suma de prefijos, cada uno de los $Q$ consultas toma $\mathcal{O}(1)$ tiempo. Por lo tanto, nuestra complejidad de tiempo total es $\mathcal{O}(N+Q)$, que ahora debería pasar el límite de tiempo.

Hagamos una consulta de ejemplo y encontremos la suma de subarreglo entre índices $a = 2$y $b = 5$, inclusive, en el índice 1 $\texttt{arr}$. Al observar la matriz original, vemos que esto es

$$\sum_{i=2}^{5} \texttt{arr}[i] = 6 + 4 + 2 + 5 = 17.$$

|   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|
|Índice |1 | 2 | 3 | 4 | 5 | 6 |
| arr| 1 | **6** | **4** | **2** | **5** | 3 |


Usando sumas de prefijos:

$$\texttt{prefix}[5] - \texttt{prefix}[1] = 18 - 1 = 17.$$

|   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|
|Índice | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| arr| 0 | 1 | **7** | **11** | **13** | **18** | 21 |


Estos también se conocen como sumas parciales .


## Código
```python
def psum(a):
	psum = [0]
	for i in a:
		psum.append(psum[-1] + i)  # psum[-1] is the last element in the list
	return psum


N, Q = map(int, input().split())
a = list(map(int, input().split()))
p = psum(a)

for i in range(Q):
	l, r = map(int, input().split())
	print(p[r] - p[l])
```


