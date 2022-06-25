num_V = 4
INF = 999

def Floyd_warshall(g):
    dist = list(map(lambda i: list(map(lambda j: j, i)), g))

    for k in range(num_V):
        for i in range(num_V):
            for j in range(num_V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    Display(dist)


def Display(dist):
    for i in range(num_V):
        for j in range(num_V):
            if(dist[i][j] == INF):
                print("INF", end=" ")
            else:
                print(dist[i][j], end="  ")
        print(" ")


g = [[0, 5, INF, 10],
         [INF, 0, 3, INF],
         [INF, INF, 0, 1],
         [INF, INF, INF, 0]]
Floyd_warshall(g)