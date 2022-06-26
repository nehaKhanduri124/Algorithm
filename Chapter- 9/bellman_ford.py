class Graph1:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def Add_edge(self, s, d, w):
        self.graph.append([s, d, w])

    def Display(self, dist):
        print("(Vertex)  (Distance from Source)")
        for i in range(self.V):
            print("{0}\t\t\t{1}".format(i, dist[i]))

    def Bellman_Ford(self, src):
        dist = [float("Inf")] * self.V
        dist[src] = 0

        for _ in range(self.V - 1):
            for s, d, w in self.graph:
                if dist[s] != float("Inf") and dist[s] + w < dist[d]:
                    dist[d] = dist[s] + w

        for s, d, w in self.graph:
            if dist[s] != float("Inf") and dist[s] + w < dist[d]:
                print("Graph contains negative weight cycle")
                return

        self.Display(dist)

G = Graph1(8)
G.Add_edge(0, 1, -8)
G.Add_edge(0, 2, 3)
G.Add_edge(1, 2, 7)
G.Add_edge(1, 3, 5)
G.Add_edge(1, 4, 12)
G.Add_edge(3, 1, 12)
G.Add_edge(3, 3, 5)
G.Add_edge(4, 3, -1)


G.Bellman_Ford(0)