#include <iostream>
using namespace std;

#define nV 4
#define INF 999

void print_Matrix(int matrix[][nV]);

void floyd_Warshall(int graph[][nV]){
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  print_Matrix(matrix);
}

void print_Matrix(int matrix[][nV]) {
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV] = {{0, 7, INF, 11},
             {INF, 0, 3, INF},
             {INF, INF, 9, 1},
             {INF, 4, INF, 0}};
  floyd_Warshall(graph);
}
