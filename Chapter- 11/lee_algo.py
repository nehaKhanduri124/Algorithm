from collections import deque

ROW = 5
COL = 9

class points:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

class Queue_Node:
    def __init__(self, pt: points, dist: int):
        self.pt = pt  
        self.dist = dist  


def Cell_isValid(row: int, col: int):
    return (row >= 0) and (row < ROW) and (col >= 0) and (col < COL)

rowNum = [-1, 0, 0, 1]
colNum = [0, -1, 1, 0]

def Lee_BFS(matrix, src: points, dest: points):
    if matrix[src.x][src.y] != 1 or matrix[dest.x][dest.y] != 1:
        return -1

    visited = [[False for i in range(COL)]
               for j in range(ROW)]
    visited[src.x][src.y] = True

    Q = deque()
    s = Queue_Node(src, 0)
    Q.append(s)

    while Q:
        curr = Q.popleft()
        pt = curr.pt
        if pt.x == dest.x and pt.y == dest.y:
            return curr.dist

        for i in range(4):
            row = pt.x + rowNum[i]
            col = pt.y + colNum[i]

            if (Cell_isValid(row, col) and
                    matrix[row][col] == 1 and
                    not visited[row][col]):
                visited[row][col] = True
                Adjcell = Queue_Node(points(row, col),
                                    curr.dist + 1)
                Q.append(Adjcell)

    return -1

def main():
    matrix = [[1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
           [1, 0, 1, 0, 1, 1, 1, 0, 1, 1],
           [1, 1, 1, 0, 1, 1, 0, 1, 0, 1],
           [0, 0, 0, 0, 1, 0, 0, 0, 0, 1],
           [1, 1, 1, 0, 1, 1, 1, 0, 1, 0],
            [1, 0, 1, 1, 1, 1, 0, 1, 0, 0],
            [1, 0, 0, 0, 0, 0, 0, 0, 0, 1],
            [1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
            [1, 1, 0, 0, 0, 0, 1, 0, 0, 1]]

    source = points(0, 0)
    dest = points(4,4)

    dist = Lee_BFS(matrix, source, dest)

    if dist != -1:
        print("Shortest Path is : ", dist)
    else:
        print("Shortest Path doesn't exist")

main()