#include<iostream>
#include<list>

using namespace std;

class Graph {
  int V;                         //no. of vertices
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void bfs(int startVertex);
};

Graph::Graph(int vertices) {
  V = vertices;
  adjLists = new list<int>[vertices];
}

void Graph::add_Edge(int src, int dest) {
  adjLists[src].pushBack(dest);
  adjLists[dest].pushBack(src);
}

void Graph::bfs(int startVertex) {
  visited = new bool[V];
  for (int i = 0; i < V; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.pushBack(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.pushBack(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.bfs(3);

  return 0;
}
