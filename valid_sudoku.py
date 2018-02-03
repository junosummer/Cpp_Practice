// Leetcode Problem 36 Valid Sudoku

// Solution in C++ may be uploaded later.

// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

class Solution:
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        
        row_int = [[],[],[],[],[],[],[],[],[]]
        col_int = [[],[],[],[],[],[],[],[],[]]
        area_int = [[],[],[],[],[],[],[],[],[]]
        
        for i in range(9):
            for j in range(9):
                current = board[i][j]
                if (current != '.'):
                    area_num = i//3+1 + (j//3)*3 - 1
                    if (current in row_int[i] or current in col_int[j] or current in area_int[area_num]):
                        return False
                    else:
                        row_int[i].append(current)
                        col_int[j].append(current)
                        area_int[area_num].append(current)
        
        return True
