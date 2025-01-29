def bfs_search(graph, starting_node, goal_node):
    visited = set()
    queue = []

    if starting_node == goal_node:
        return [starting_node]

    visited.add(starting_node)
    queue.append(starting_node)

    while queue:
        path = queue.pop(0)

        print(path, end='->' if path != f'{goal_node}' else '')
        if path == goal_node:
            return path

        for neighbour in graph[path]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)

    print('None')
    return None


graph = {
    '1': ['2', '3', '4'],
    '2': ['5', '6'],
    '3': [],
    '4': ['7', '8'],
    '5': ['9', '10'],
    '6': [],
    '7': ['11', '12'],
    '8': [],
    '9': [],
    '10': [],
    '11': [],
    '12': []
}

starting_node = '1'
goal_node = '6'
bfs_search(graph, starting_node, goal_node)
