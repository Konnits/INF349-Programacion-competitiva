def delete_leafs(nodes, connections, n_edges):
	
	for connection in connections:
		if connections[connection] == 1:
			for a in nodes[connection]:
				nodes[a].remove(connection)
				if len(nodes[a]) == 0:
					del nodes[a]
				nodes[connection].remove(a)
				if len(nodes[connection]) == 0:
					del nodes[connection]
				connections[a] -= 1
			connections[connection] -= 1
			n_edges -= 1
	return n_edges

def have_one_cycle(nodes, m, visited = [], actual = None):
	if not actual:
		for node in nodes:
			if len(nodes[node]) != 0:
				actual = nodes[node][0]
				break
	for node in nodes[actual]:
		if node not in visited:
			return have_one_cycle(nodes, m, visited + [node], node)
	return len(visited) == m

n, m = map(int, input().split(" "))

nodes = {i : [] for i in range(1, n + 1)}
connections = {i : 0 for i in range(1, n + 1)}

for i in range(m):
	a, b = map(int, input().split(" "))
	
	nodes[a] = nodes.get(a, []) + [b]
	nodes[b] = nodes.get(b, []) + [a]
	
	connections[a] = connections.get(a, 0) + 1
	connections[b] = connections.get(b, 0) + 1

prev_edges = m
edges = delete_leafs(nodes, connections, m)

while prev_edges != edges:
	prev_edges = edges
	edges = delete_leafs(nodes, connections, edges)
if all(list(map(lambda x : len(x) == 2, nodes.values()))) and sum(list(map(lambda x : (x == 2), connections.values()))) >= 3 and have_one_cycle(nodes, sum(list(map(lambda x : len(x) != 0, nodes.values())))):
	print("FHTAGN!")
else:
	print("NO")