// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// Using Dynamic Programming.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        if (nums.size() == 0)  return 0;
        int global_max = nums[0];  
        int local_max = nums[0];  
        for(int i=1; i<nums.size(); i++)  
        {  
            local_max = nums[i]>local_max+nums[i] ? nums[i] : local_max+nums[i];  
            global_max = local>global_max ? local : global_max;  
        }  
        return global_max;  
    }
};
