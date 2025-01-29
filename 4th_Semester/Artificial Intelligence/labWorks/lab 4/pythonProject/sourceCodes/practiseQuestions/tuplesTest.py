capacity1 = 1
capacity2 = 2
jug1 = 1
jug2 = 2

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

print(actions.__getitem__(slice(0,3)))