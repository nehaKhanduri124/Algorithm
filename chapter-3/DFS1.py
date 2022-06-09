from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFS_IMP(self, v, visited):
        visited[v]=True
        print(v, end=' ')
        for neighbour in self.graph[v]:
         # if neighbour not in visited:
            if visited[neighbour]  == False:
                self.DFS_IMP(neighbour, visited)

    def DFS(self, v):
        visited = [False] *(v)
        for i in range(v):
            if visited[i]  == False:
                self.DFS_IMP(i, visited)


g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(0, 3)
g.addEdge(1, 2)
g.addEdge(2, 4)
g.addEdge(3, 3)
g.addEdge(3, 5)
g.addEdge(4, 4)

print("DFS(starting from vertex 0)")
g.DFS(6)
