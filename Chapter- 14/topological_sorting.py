from collections import defaultdict

class Graph:
    def __init__(self, vert):
        self.graph = defaultdict(list)
        self.V = vert

    def add_Edge(self, u, v):
        self.graph[u].append(v)

    def Topological(self, v, visit, stack):

        visit[v] = True

        for i in self.graph[v]:
            if visit[i] == False:
                self.Topological(i, visit, stack)

        stack.append(v)

    def topological_Sort(self):
        visit = [False] * self.V
        stack = []

        for i in range(self.V):
            if visit[i] == False:
                self.Topological(i, visit, stack)
        print(stack[::-1])


gr = Graph(4)
gr.add_Edge(3, 2)
gr.add_Edge(3, 0)
gr.add_Edge(2, 0)
gr.add_Edge(2, 1)
gr.add_Edge(0, 3)
gr.add_Edge(1, 1)

print("Topological Sort is : ")

gr.topological_Sort()