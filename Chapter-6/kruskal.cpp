#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph1 {
    private:
    vector<pair<int, edge> > G;
    vector<pair<int, edge> > T;
    int *parent;
    int Vertex;
     public:
    Graph1(int Vertex);
    void Kruskal_MST(int u, int v, int w);
    int find_set(int i);
    void Union_set(int u, int v);
    void Kruskal();
    void print();
};

Graph1::Graph1(int Vertex) {
    parent = new int[Vertex];

    for(int i = 0; i < Vertex; i++)
        parent[i] = i;

    G.clear();
    T.clear();
}

void Graph1::Kruskal_MST(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph1::find_set(int i) {
    if (i == parent[i])
        return i;
    else
        return find_set(parent[i]);
}

void Graph1::Union_set(int u, int v) {
    parent[u] = parent[v];
}

void Graph1::Kruskal() {
    int i, uRep, vRep;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]);
            Union_set(uRep, vRep);
        }
    }
}

void Graph1::print() {
    cout << "Edge(source  - destination) :"<< " Weight" << endl;
    for (int i = 0; i < T.size(); i++) {
        cout <<"      "<<T[i].second.first << "            -     " << T[i].second.second << "        : "<< T[i].first;
        cout << endl;
    }
}

int main() {
  Graph1 graph(7);
  graph.Kruskal_MST(1, 2, 7);
  graph.Kruskal_MST(1, 3, 8);
  graph.Kruskal_MST(2, 3, 3);
  graph.Kruskal_MST(2, 6, 5);
  graph.Kruskal_MST(2, 4, 6);
  graph.Kruskal_MST(4, 3, 4);
  graph.Kruskal_MST(4, 2, 6);
  graph.Kruskal_MST(4, 6, 2);
  graph.Kruskal_MST(5, 4, 5);
  graph.Kruskal_MST(5, 6, 2);
  graph.Kruskal_MST(6, 3, 3);
  graph.Kruskal_MST(6, 2, 5);
  graph.Kruskal_MST(6, 4, 2);
  graph.Kruskal_MST(5, 2, 2);
  graph.Kruskal_MST(5, 4, 3);
  graph.Kruskal();
  graph.print();
  return 0;
}
