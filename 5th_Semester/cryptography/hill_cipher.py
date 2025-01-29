def make_matrix(matrix):
    dimension_i = int(input("Enter ith dimension of matrix: "))
    dimension_j = int(input("Enter jth dimension of matrix: "))
    user_inp = 0
    temp_row = []

    for i in range(dimension_i):
        # resetting the temporary row
        temp_row = []
        for j in range(dimension_j):
            user_inp = int(input(f"Enter {i} {j} of matrix: "))
            temp_row.append(user_inp)
        matrix.append(temp_row)

    return matrix


def main():
    my_matrix = []
    my_matrix = make_matrix(my_matrix)

    

main()
