// LeetCode Problem 22 Generate Parenthese
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Recursion

class Solution {
public:
    void generate_recursion(int left_num, int right_num, string s, vector<string> &ret)  
    {  
        if(left_num == 0 && right_num == 0)  
        {  
            ret.push_back(s);  
        }  
        if(left_num > 0)  
        {  
            // if there is left bracket, we can directly add it to the end of the string. 
            generate_recursion(left_num - 1, right_num, s+'(', ret);  
        }  
        if(right_num > 0 && left_num < right_num)  
        {  
            // if there is right bracket, we need to check make sure there is more left bracket in s than right bracket.
            generate_recursion(left_num, right_num - 1, s+')', ret);  
        }  
    } 

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate_recursion(n, n, "", ret);
        return ret;
    }
};
