class Graph1:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_Edge(self, u, v, w):
        self.graph.append([u, v, w])


    def Find_set(self, parent, i):
        if parent[i] == i:
            return i
        return self.Find_set(parent, parent[i])

    def apply_Union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def Kruskal(self):
        result = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.apply_Union(parent, rank, x, y)
        for u, v, weight in result:
            print("%d - %d: %d" % (u, v, weight))


G = Graph1(6)
G.add_Edge(0, 1, 4)
G.add_Edge(0, 2, 4)
G.add_Edge(1, 2, 2)
G.add_Edge(1, 0, 4)
G.add_Edge(2, 0, 4)
G.add_Edge(2, 1, 2)
G.add_Edge(2, 3, 3)
G.add_Edge(2, 5, 2)
G.add_Edge(2, 4, 4)
G.add_Edge(3, 2, 3)
G.add_Edge(3, 4, 3)
G.add_Edge(4, 2, 4)
G.add_Edge(4, 3, 3)
G.add_Edge(5, 2, 2)
G.add_Edge(5, 4, 3)
G.Kruskal()