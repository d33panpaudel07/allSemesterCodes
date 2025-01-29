def water_jug_problem(capacity1, capacity2, target):
    def dfs(jug1, jug2, path):
        # Check if we have reached the target
        if jug1 == target or jug2 == target:
            print("It is possible to measure the target amount. Steps:")
            for step in path:
                print(step)
            return True

        # If the state has already been visited, return False
        if (jug1, jug2) in visited:
            return False

        # Mark the state as visited
        visited.add((jug1, jug2))

        # Try all possible actions
        actions = [
            (capacity1, jug2, f"Fill jug1: ({capacity1}, {jug2})"),
            (jug1, capacity2, f"Fill jug2: ({jug1}, {capacity2})"),
            (0, jug2, f"Empty jug1: (0, {jug2})"),
            (jug1, 0, f"Empty jug2: ({jug1}, 0)"),
            (jug1 - min(jug1, capacity2 - jug2), jug2 + min(jug1, capacity2 - jug2), 
             f"Pour jug1 to jug2: ({jug1 - min(jug1, capacity2 - jug2)}, {jug2 + min(jug1, capacity2 - jug2)})"),
            (jug1 + min(jug2, capacity1 - jug1), jug2 - min(jug2, capacity1 - jug1), 
             f"Pour jug2 to jug1: ({jug1 + min(jug2, capacity1 - jug1)}, {jug2 - min(jug2, capacity1 - jug1)})")
        ]

        # Recursively explore each action
        for new_jug1, new_jug2, action in actions:
            if dfs(new_jug1, new_jug2, path + [action]):
                return True

        return False

    visited = set()
    if dfs(0, 0, []):
        return True
    else:
        print("It is not possible to measure the target amount.")
        return False

# Example usage
capacity1 = 4  # Capacity of jug 1
capacity2 = 3  # Capacity of jug 2
target = 2     # Target amount of water

water_jug_problem(capacity1, capacity2, target)