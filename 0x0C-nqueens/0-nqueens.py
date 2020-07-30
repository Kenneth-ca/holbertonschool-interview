#!/usr/bin/python3
"""
A program that solves the N queens problem
"""
import sys


def printBoard(board):
    """
    Prints the board
    :param board: the board with N dimensions
    :return: nothing
    """
    result = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                result.append([i, j])
    print(result)


def check_position(board, row, col):
    """
    Checks if a queen could kill another before set
    :param board: the board with N dimensions
    :param row: row position
    :param col: column position
    :return: True or false if the position is safe
    """
    for i in range(col):
        if board[row][i]:
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1
    i = row
    j = col
    while j >= 0 and i < N:
        if board[i][j]:
            return False
        i = i + 1
        j = j - 1
    return True


def backtrack(board, col):
    """
    Perform backtrack to set queens positions
    :param board: the board with N dimensions
    :param col: column position
    """
    if col == N:
        printBoard(board)
        return True
    res = False
    for i in range(N):
        if check_position(board, i, col):
            board[i][col] = 1
            res = backtrack(board, col + 1) or res
            board[i][col] = 0
    return res


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not sys.argv[1].isnumeric():
        print("N must be a number")
        sys.exit(1)

    N = int(sys.argv[1])

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for j in range(N)] for i in range(N)]
    sol = backtrack(board, 0)
