from typing import List, Set

# Se solicita al usuario el número de nodos y el número de aristas
n, m = map(int, input().split())

# Se crea la lista de adyacencia para el grafo directo
forward_graph = [[] for _ in range(n)]

# Se crea la lista de adyacencia para el grafo inverso
reverse_graph = [[] for _ in range(n)]

# Se itera por cada arista ingresada por el usuario
for _ in range(m):
    a, b = map(int, input().split())
    
    # Se agrega el nodo b a la lista de adyacencia del nodo a en el grafo directo
    forward_graph[a - 1].append(b - 1)
    
    # Se agrega el nodo a a la lista de adyacencia del nodo b en el grafo inverso
    reverse_graph[b - 1].append(a - 1)

# Función para realizar un recorrido DFS de un grafo
def dfs(graph: List[List[int]]) -> Set[int]:
    # Se crea un conjunto con todos los nodos
    unvisited = set(range(1, n))
    # Se agrega el nodo 0 a la pila
    stack = [0]
    while stack:
        # Se saca el último elemento de la pila
        curr = stack.pop()
        # Se recorre cada nodo adyacente al nodo actual
        for adj in graph[curr]:
            if adj in unvisited:
                # Se agrega el nodo adyacente a la pila y se elimina de los no visitados
                stack.append(adj)
                unvisited.remove(adj)

    # Se retorna el conjunto de nodos no visitados
    return unvisited

# Se realizan los recorridos DFS en ambos grafos
unvisited_fwd = dfs(forward_graph)
unvisited_rev = dfs(reverse_graph)

if unvisited_fwd:
    print("NO")
    print(f"1 {unvisited_fwd.pop() + 1}")
elif unvisited_rev:
    print("NO")
    print(f"{unvisited_rev.pop() + 1} 1")
else:
    print("YES")

