#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5

struct Cell
{
	int x;
	int y;
};

struct queue_Node
{
	Cell pt;
	int dist;
};

bool check_cellValid(int row, int col)
{
	return ((row >= 0) && (row < ROW) &&	(col >= 0) && (col < COL));
}

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

int Lee_algo(int matrix[][COL], Cell src, Cell dest)
{
	if (!matrix[src.x][src.y] || !matrix[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);

	visited[src.x][src.y] = true;

	queue<queue_Node> q;


	queue_Node s = {src, 0};
	q.push(s);

	while (!q.empty())
	{
		queue_Node curr = q.front();
		Cell pt = curr.pt;

		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];


			if (check_cellValid(row, col) && matrix[row][col] &&
			!visited[row][col])
			{

				visited[row][col] = true;
				queue_Node adj_Cell = { {row, col},
									curr.dist + 1 };
				q.push(adj_Cell);
			}
		}
	}

	return -1;
}

int main()
{
	int matrix[ROW][COL] =
	{
		{ 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1 }};

	Cell source = {0, 0};
	Cell dest = {2, 1};

	int dist = Lee_algo(matrix, source, dest);

	if (dist != -1)
		cout<< "Shortest Path is : "<<dist ;
	else
		cout<< "Shortest Path doesn't exist ";

	return 0;
}
