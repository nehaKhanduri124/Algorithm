#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int source, dest;
};

class Graph{
public:
	int V, E;
	Edge* edge;
};

Graph* create(int V, int E){
	Graph* graph = new Graph();
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[graph->E * sizeof(Edge)];

	return graph;
}

int find_parent(int parent[], int i){
	if (parent[i] == -1)
		return i;
	return find_parent(parent, parent[i]);
}

void find_union(int parent[], int x, int y){
	parent[x] = y;
}

int detect_Cycle(Graph* graph){
	int* parent = new int[graph->V * sizeof(int)];

	memset(parent, -1, sizeof(int) * graph->V);

	for (int i = 0; i < graph->E; ++i) {
		int x = find_parent(parent, graph->edge[i].source);
		int y = find_parent(parent, graph->edge[i].dest);

		if (x == y)
			return 1;

		find_union(parent, x, y);
	}
	return 0;
}

int main(){
	int V = 5, E = 6;
	Graph* graph = create(V, E);

	graph->edge[0].source = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].source = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].source = 2;
	graph->edge[2].dest = 3;

    graph->edge[3].source = 3;
	graph->edge[3].dest = 4;

	graph->edge[4].source = 4;
	graph->edge[4].dest = 5;

	graph->edge[5].source = 5;
	graph->edge[5].dest = 1;

	if (detect_Cycle(graph))
		cout << " graph contains cycle ";
	else
		cout << " graph doesn't contain cycle";

	return 0;
}
