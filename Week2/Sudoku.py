#PYTHON 
def is_valid(board, row, col, num):
    # Check if the number is not in the same row or column
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False

    # Check if the number is not in the same 3x3 subgrid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False

    return True

def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            board[row][col] = 0  # Backtrack
                        else:
                            return False
                return False
    return True

def count_sudoku_solutions(board):
    count = [0]  # Using a list to store the count so it can be modified within the recursion

    def count_helper(board, count):
        for row in range(9):
            for col in range(9):
                if board[row][col] == 0:
                    for num in range(1, 10):
                        if is_valid(board, row, col, num):
                            board[row][col] = num
                            count_helper(board, count)
                            board[row][col] = 0  # Backtrack
                    return
        count[0] += 1  # If all cells are filled, increment the count

    count_helper(board, count)
    return count[0]

# Read input
sudoku_board = []
for _ in range(9):
    row = list(map(int, input().split()))
    sudoku_board.append(row)

# Calculate and print the number of solutions
solutions = count_sudoku_solutions(sudoku_board)
print(solutions)
