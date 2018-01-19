// LeetCode Problem 13
// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    
    int singleInt(char ch)
    {
        switch (ch)
        {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
        }
    }
    
    int romanToInt(string s) {
        int ret = 0;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (singleInt(s[i]) < singleInt(s[i+1]))
            {
                ret -= singleInt(s[i]);
            }
            else
            {
                ret += singleInt(s[i]);
            }
        }
        ret += singleInt(s[s.length()-1]);
        return ret;
    }
    
};
