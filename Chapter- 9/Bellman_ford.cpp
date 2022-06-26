#include <bits/stdc++.h>

struct Edge {
	int source, destination, weight;
};

struct Graph {
	int V, E;
	struct Edge* edge;
};

struct Graph* Create(int V, int E){
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}

void print_Array(int dist[], int n){
	printf("(Vertex)  (Distance from Source)\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

void Bellman_Ford(struct Graph* graph, int source){
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].source;
			int v = graph->edge[j].destination;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].source;
		int v = graph->edge[i].destination;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return;
		}
	}

	print_Array(dist, V);

	return;
}

int main(){
	int Vrtx = 5;
	int E = 8;
	struct Graph* graph = Create(Vrtx, E);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 4;
    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 8;
    graph->edge[2].source = 1;
    graph->edge[2].destination = 2;
    graph->edge[2].weight = -1;
    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 5;
    graph->edge[4].source = 1;
    graph->edge[4].destination = 4;
    graph->edge[4].weight = 2;
    graph->edge[5].source = 3;
    graph->edge[5].destination = 2;
    graph->edge[5].weight = -4;
    graph->edge[6].source = 3;
    graph->edge[6].destination = 1;
    graph->edge[6].weight = 1;
    graph->edge[7].source = 4;
    graph->edge[7].destination = 3;
    graph->edge[7].weight = 10;

    Bellman_Ford(graph, 0);
    return 0;
}
