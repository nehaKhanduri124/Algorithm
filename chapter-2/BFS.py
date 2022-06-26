import collections

def BFS_algo(graph, root):
    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:
        vrtx = queue.popleft()
        print(str(vrtx) + " ", end="")

        for neighbour in graph[vrtx]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    graph = {0: [1, 2], 1: [2], 2: [0, 3], 3: [3]}
    print(" Breadth First Search  : ")
    BFS_algo(graph, 1)