#!/usr/bin/python3
"""
Given an n x n 2D matrix, rotate it 90 degrees
"""


def rotate_2d_matrix(matrix):
    """
    Performs a 90 degrees rotation to a matrix in-place
    """
    copy = [ele[:] for ele in matrix]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = copy[len(matrix) - 1 - j][i]
