// LeetCode Problem 22 Generate Parenthese
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

class Solution {
public:
    void generate(int leftNum, int rightNum, string s, vector<string> &ret)  
    {  
        if(leftNum==0 && rightNum==0)  
        {  
            ret.push_back(s);  
        }  
        if(leftNum > 0)  
        {  
            // if there is left bracket, we can directly add it to the end of the string. 
            generate(leftNum-1, rightNum, s+'(', ret);  
        }  
        if(rightNum>0 && leftNum<rightNum)  
        {  
            // if there is right bracket, we need to check make sure there is more left bracket in s than right bracket.
            generate(leftNum, rightNum-1, s+')', ret);  
        }  
    } 

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        generate (n, n, "", ret);
        return ret;
    }
};
