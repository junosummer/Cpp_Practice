// Leetcode Problem 17 Letter Combinations of a Phone Number
// Given a digit string, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below.
// 2: "abc", 3: "def", 4: "ghi", 5: "jkl", 6: "mno", 7: "pqrs", 8: "tuv", 9: "wxyz"}
// Using deque to achieve first in first out(BFS) and then convert to vector
// Alternatively, use vector directly and the algorithm should be DFS(last in first out)

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        deque<string> ret;
        string str = "";
        ret.push_back(str);
        string temp = "";
        string current = "";
        string map_num[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> deque_to_vector;
        
        if(digits.length() == 0)
            return deque_to_vector;
        
        for(int i = 0; i < digits.length(); i++)
        {
            str = ret.front();
            while(str.length() == i)
            {
                current = map_num[digits[i]-'2'];
                temp = str;
                for (int j = 0; j < current.length(); j++)
                {
                    temp += current[j];
                    ret.push_back(temp);
                    temp = str;
                }
                ret.pop_front();
                str = ret.front();
            }
        }    
        
        for (int k = 0; k < ret.size(); k++)
        {
            deque_to_vector.push_back(ret[k]);
        }
        return deque_to_vector;
    }
};
