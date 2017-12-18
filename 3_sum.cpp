// 3Sum LeetCode
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.

class Solution {
public:
    // Find two numbers whose sum equals to target.
    void twoSum(vector<int>& nums, vector<vector<int>>& ret, int begin, int end, int target) 
    {
        int left = begin, right = end;  
        while (left < right) // Using sandwich method.
        {  
            if (nums[left] + nums[right] == target) 
            {  
                ret.push_back({-target, nums[left], nums[right]});
                
                // Make sure there is no duplicate.
                while (left < right && nums[left] == nums[left+1])
                {
                    left++;  
                }
                while (left < right && nums[right] == nums[right-1])
                {
                    right--;  
                }
                left++;  
                right--;  
            } 
            else if (nums[left] + nums[right] < target) 
            {  
                left++;  
            } 
            else 
            {  
                right--;  
            }  
        }  
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort (nums.begin(), nums.end());
        int len = nums.size();
        if (len < 3 || nums[0] > 0 || nums[len-1] < 0) // When there is definitely no solution.
        {
            return ret;
        }
        int three_sum = 0;
        for (int i = 0; i < len-2; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) // make sure there is no duplicate.
            {
                twoSum(nums, ret, i+1, len-1, -nums[i]);
            }
        }
        
        return ret;
    }
}；
