def operation():
    while True:
        operation = input(
            "What do you want to perform, Encryption / Decryption? (E/D) : "
        ).upper()
        if operation == "E":
            return True
        elif operation == "D":
            return False
        else:
            print(
                "Invalid operation. Please enter 'E' for Encryption or 'D' for Decryption."
            )


def display_matrix(matrix):
    for row in matrix:
        print(" ".join([str(cell) if cell is not None else "." for cell in row]))


def rail_fence(plain_text, key, choice):
    matrix = [[None for _ in range(len(plain_text))] for _ in range(key)]
    row = 0
    col = 0
    move = True
    position = []

    for char in plain_text:
        position.append((row, col))
        col = col + 1
        if row == 0:
            move = True
        elif row == key - 1:
            move = False

        if move:
            row += 1
        else:
            row -= 1

    result = ""
    if choice:
        for i in range(len(plain_text)):
            for pos in position:
                x = pos[0]
                y = pos[1]
                if y == i:
                    matrix[x][y] = plain_text[i]

        display_matrix(matrix)

        for i in range(len(plain_text)):
            for pos in position:
                x = pos[0]
                y = pos[1]
                if x == i:
                    result += matrix[x][y]
    else:
        count = 0
        for i in range(len(plain_text)):
            for pos in position:
                x = pos[0]
                y = pos[1]
                if x == i:
                    matrix[x][y] = plain_text[count]
                    count = count + 1

        display_matrix(matrix)

        for i in range(len(plain_text)):
            for pos in position:
                x = pos[0]
                y = pos[1]
                if y == i:
                    result += matrix[x][y]
    return result


def main():
    plain_text = input("Enter text: ").upper()
    key = int(input("Enter key: "))
    choice = operation()

    if choice:
        print("Encrypted text: ", rail_fence(plain_text, key, choice))
    else:
        print("Decrypted text:", rail_fence(plain_text, key, choice))

main()
