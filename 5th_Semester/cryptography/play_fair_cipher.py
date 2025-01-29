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


def find_position(matrix, element):
    for row_index, row in enumerate(matrix):
        for col_index, value in enumerate(row):
            if value == element:
                return row_index, col_index
    return None


def playfair(plain_text, key, choice):
    matrix = []
    row = []
    alphabets = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    matrix_alphabets = ""
    count = 0

    for char in key:
        if count > 4:
            matrix.append(row)
            row = []
            count = 0
        if char not in matrix_alphabets:
            matrix_alphabets += char
            row.append(char)
            count += 1

    for char in alphabets:
        if char not in matrix_alphabets:
            if count > 4:
                matrix.append(row)
                row = []
                count = 0
            row.append(char)
            count += 1

    if row:
        matrix.append(row)

    print("Playfair Cipher Matrix:")
    for r in matrix:
        print(" ".join(r))

    pairs = []
    x = ""
    y = ""
    for char in plain_text:
        if not x:
            x = char
        elif not y:
            if x == char:
                y = "X"
                pairs.append((x, y))
                x = char
                y = ""
            else:
                y = char

        if x and y:
            pairs.append((x, y))
            x = ""
            y = ""

    if x:
        pairs.append((x, "X"))

    print("Pairs:", pairs)

    result = ""
    for pair in pairs:
        x_pos = find_position(matrix, pair[0])
        y_pos = find_position(matrix, pair[1])

        if x_pos and y_pos:
            x_row, x_col = x_pos
            y_row, y_col = y_pos

            if x_row == y_row:  # Same row
                if choice:
                    result += matrix[x_row][(x_col + 1) % 5]
                    result += matrix[y_row][(y_col + 1) % 5]
                else:
                    result += matrix[x_row][(x_col - 1) % 5]
                    result += matrix[y_row][(y_col - 1) % 5]
            elif x_col == y_col:  # Same column
                if choice:
                    result += matrix[(x_row + 1) % 5][x_col]
                    result += matrix[(y_row + 1) % 5][y_col]
                else:
                    result += matrix[(x_row - 1) % 5][x_col]
                    result += matrix[(y_row - 1) % 5][y_col]
            else:  # Rectangle rule
                result += matrix[x_row][y_col]
                result += matrix[y_row][x_col]

    return result


def main():
    plain_text = input("Enter text: ").upper().replace("J", "I")
    key = input("Enter key: ").upper().replace("J", "I")
    choice = operation()

    if choice:
        print("Encrypted text: ", playfair(plain_text, key, choice))
    else:
        print("Decrypted text:", playfair(plain_text, key, choice))


main()
