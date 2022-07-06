from collections import defaultdict

class Graph:

    def __init__(self, vertex):
        self.V = vertex
        self.graph = defaultdict(list)

    def Add_edge(self, u, v):
        self.graph[u].append(v)

    def parent(self, parent, i):
        if parent[i] == -1:
            return i
        if parent[i] != -1:

            return self.parent(parent, parent[i])

    def union(self, parent, x, y):
        parent[x] = y

    def Check_cyclic(self):

        parent = [-1] * self.V

        for i in self.graph:
            for j in self.graph[i]:
                x = self.parent(parent, i)
                y = self.parent(parent, j)
                if x == y:
                    return True
                self.union(parent, x, y)


G = Graph(5)
G.Add_edge(0, 1)
G.Add_edge(0, 2)
G.Add_edge(1, 2)
G.Add_edge(2, 3)
G.Add_edge(3, 4)
G.Add_edge(4, 5)
G.Add_edge(5, 1)

if G.Check_cyclic():
    print(" graph contains cycle")
else:
    print(" graph doesn't contain cycle ")