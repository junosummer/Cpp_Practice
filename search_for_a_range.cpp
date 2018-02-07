// Leetcode Problem 34 Search for a Range
// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int nums_size = nums.size();
        int left = 0;
        int right = nums_size - 1;
        int mid = 0;
        
        while(left<=right)
        {
            mid = (left+right)/2;
            if (nums[mid] ==target)
            {
                int range_l = mid;
                int range_r = mid;
                while(--range_l >-1)
                {
                    if (nums[range_l]!=target)
                        break;
                }
                
                while(++range_r < nums_size)
                {
                    if (nums[range_r]!=target)
                        break;
                }
                return vector<int> {++range_l, --range_r};
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return vector<int> {-1,-1};
    }
};
