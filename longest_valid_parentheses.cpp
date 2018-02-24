/* Leetcode Problem 32 Longest Valid Parentheses
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

// Using Stack


class Solution {
public:
    
    int longestValidParentheses(string s) {
        int max_len = 0;
        int curr = 0;
        stack<int> par;
        int str_len = s.length();
        int ind = str_len-1;
        for (int i = 0; i < str_len; i++)
        {
            if(s[i]=='(')
            {
                par.push(i);
                if(i < ind)
                    ind = i;
            }
            else if(s[i] == ')' && !par.empty())
            {
                par.pop();
                if(par.empty())
                    curr = i - ind + 1;
                else
                    curr = i-par.top();
                if(curr > max_len)
                    max_len = curr;
            } 
            else
                ind = str_len-1;
        }
        return max_len;
    }
};
