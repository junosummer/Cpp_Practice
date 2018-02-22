/* Leetcode Problem 42 Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

// Using the method of two pointers to go from the two ends to the middle.

class Solution {
public:
    int trap(vector<int>& height)
    {
        int left = 0, right = height.size() - 1;
        int water = 0;
        int left_max = 0, right_max = 0;
        while (left < right) 
        {
            if (height[left] < height[right])
            {
                height[left] >= left_max ? (left_max = height[left]) : water += (left_max - height[left]);
                left++;
            }
            else 
            {
                height[right] >= right_max ? (right_max = height[right]) : water += (right_max - height[right]);
                right--;
            }
        }
        return water;
    }
};
