import copy
import functions
import itertools
import math
from typing import List

from test_framework import generic_test
from test_framework.test_failure import TestFailure
from test_framework.test_utils import enable_executor_hook

def solve_sudoku(partial_assignment: List[List[int]])->bool:
    def solve_partial_sudoku(i,j):
        if i == len(partial_assignment):
            i = 0
            j+=1
            if j == len (partial_assignment[i]):
                return True

        if partial_assignment[i][j] != empty_entry:
            return solve_partial_sudoku(i+1,j)

        def valid_to_add(i,j,val):
            if any(val == partial_assignment[k][j]
                   for k in range(len(partial_assignment))):
                return False

            region_size = int(math.sqrt(len(partial_assignment)))
            I = i //region_size
            J = j //region_size
            return not any(
                val == partial_assignment[region_size*I + a][region_size*J + b]
                for a,b in itertools.product(range(region_size),repeat=2)
            )

        for val in range(1,len(partial_assignment)+1):
            if valid_to_add(i,j,val):
                partial_assignment[i][j]=val
                if solve_partial_sudoku(i+1,j):
                    return True

        partial_assignment[i][j] = empty_entry
        return False

    empty_entry = 0

    return solve_partial_sudoku(0, 0)

def assert_unique_seq(seq):
    seen = set()
    for x in seq:
        if x == 0: