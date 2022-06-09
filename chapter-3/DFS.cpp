#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
	map<int, bool> Visited;
	map<int, list<int> > adj;

	void addEdge(int v, int w);

	void Dfs(int v);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::Dfs(int v){
	Visited[v] = true;
	cout << v << " ";
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!Visited[*i])
			Dfs(*i);
}

int main(){
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 4);
	g.addEdge(3, 3);
	g.addEdge(4, 4);

	cout << "Depth First Traversal(starting from vertex 0)"<<endl;
	g.Dfs(0);

	return 0;
}


