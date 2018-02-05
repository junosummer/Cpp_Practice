// Leetcode Problem 31 Next Permutation
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory. -> swap or sort!!!

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size = nums.size();
        if(nums_size != 0 && nums_size != 1)
        {
            int current = nums_size-1;
            while(current > 0 && nums[current]<=nums[current-1])
                current--;
            if(current == 0)
            {
                for (int i = 0; i < nums_size/2; i++)
                    swap(nums[i], nums[nums_size-1-i]);
            }
            else
            {
                int pos = current;
                if(pos==nums_size-1)
                    swap(nums[pos], nums[pos-1]);
                else
                {
                    while (nums[pos] > nums[current-1] && pos < nums_size)
                        pos++;
                    pos--;
                    swap(nums[pos], nums[current-1]);
                    sort(nums.begin()+curr,nums.end());
                }
            } 
        }
    }
};
