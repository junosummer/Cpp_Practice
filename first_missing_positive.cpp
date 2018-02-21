/* Leetcode Problem 41 First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

/* Sort first, find the position of 1 if none is found, return 1
   else, go through the vecotr behind 1 to find the first missing positive
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int nsize = nums.size();
        int curr = 1;
        int pos = find(nums.begin(),nums.end(),curr) - nums.begin();
        if(pos == nums.size())
        {
            return curr;
        }
        while (pos < nums.size())
        {
            if(nums[++pos]!=curr+1)
            {
                if(nums[pos]!=curr)
                {
                    return curr+1;
                }
                else
                {
                    continue;
                }
            }
            curr++;
        }
        return ++curr;
    }
};
