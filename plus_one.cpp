// Leetcode Problem 66 Plus One
// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
// You may assume the integer do not contain any leading zero, except the number 0 itself.
// The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int digits_len = digits.size();
        digits[digits_len-1] ++;
        if (digits[digits_len-1] > 9)
        {
            digits[digits_len-1] -= 10;
            carry = 1;
        }
        for (int i = digits_len-2; i > -1; i--)
        {
            digits[i] = digits[i] + carry;
            carry = 0;
            if (digits[i] > 9)
            {
            digits[i] -= 10;
            carry = 1;
            }
        }
        vector<int> ret;
        if(carry == 1)
        {
            ret.push_back(carry);
        }
        for (int j = 0; j < digits_len; j++)
        {
            ret.push_back(digits[j]);
        }
        
        return ret;
    }
};
