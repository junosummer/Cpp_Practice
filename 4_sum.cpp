// 4Sum LeetCode
// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Find all unique quadruplets in the array which gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.

// Simplify this problem to 3 Sum then 2 Sum.

class Solution {
public:
        // Find two numbers whose sum equals to target.
    void twoSum(vector<int>& nums, vector<vector<int>>& ret, int first_pos, int second_pos, int begin, int end, int target) 
    {
        int left = begin, right = end;  
        while (left < right) // Using sandwich method.
        {  

            if (nums[left] + nums[right] == target) 
            {  
                ret.push_back({nums[first_pos], nums[second_pos], nums[left], nums[right]});
                
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
    
    void threeSum(vector<int>& nums, vector<vector<int>>& ret, int first_pos, int begin, int end, int target) {
        for (int j = begin; j < end-1; j++)
        {
            if (j == begin || (j > begin && nums[j] != nums[j-1])) // make sure there is no duplicate.
            {
                twoSum(nums, ret, first_pos, j, j+1, end, target-nums[j]);
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort (nums.begin(), nums.end());
        int len = nums.size();
        if (len < 4)
        {
            return ret;
        }
        for (int i = 0; i < len-3; i++)
        {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                threeSum(nums, ret, i, i+1, len-1, target-nums[i]);
            }
        }
        
        return ret;
        
    }
};
