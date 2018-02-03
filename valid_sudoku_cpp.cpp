// LeetCode Problem 36 Valid Sudoku C++ Solution
// Same algorithm as the Python solution, but using C++ makes the program much faster
// [Tested on 501 cases: C++ 9ms, Python 90+ms]

// Determine if a Sudoku is valid
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
// A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

static vector<vector<char>> board =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<vector<char>>{};
}();

class Solution {
public:
    bool notInArray(char arr[], char target)
    {
        for (int k = 0; k < 9; k++)
        {
            if(target == arr[k])
            {
                return false;
            }
            if(arr[k] == '0' || arr[k] == NULL)
            {
                arr[k] = target;
                return true;
            }
        }
    } 
    bool isValidSudoku(vector<vector<char>>& board) {
        char row_int[9][9] = {};
        char col_int[9][9] = {};
        char area_int[9][9] = {};
        
        for (int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char current = board[i][j];
                if(current != '.')
                {
                    int area_num = i/3 + 1 + (j/3) *3 - 1;
                    if(!notInArray(row_int[i], current) || !notInArray(col_int[j],current) || !notInArray(area_int[area_num],current))\
                        return false;
                }
            }
        }
        return true;
    }
};
