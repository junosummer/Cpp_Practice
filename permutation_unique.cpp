/* Leetcode Problem 47 Permutation 2

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

*/

/* Solution is basically the same as problem 46 permutation (a collection of distinct numbers),

  but with an extra check before push the new permutation to the return vector 
  
  to make sure it is different from the one before it.
  
*/

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int nums_size = nums.size();
        if(nums_size != 0 && nums_size != 1)
        {
            int current = nums_size-1;
            while(current > 0 && nums[current]<=nums[current-1])
            {
                current--;
            }
            if(current == 0)
            {
                for (int i = 0; i < nums_size/2; i++)
                    swap(nums[i], nums[nums_size-1-i]);
            }
            else
            {
                int pos = current;
                if(pos==nums_size-1)
                {
                    swap(nums[pos], nums[pos-1]);
                }
                else
                {
                    while (nums[pos] > nums[current-1] && pos < nums_size)
                        pos++;
                    pos--;
                    swap(nums[pos], nums[current-1]);
                    for (int j = 0;j < (nums_size-current)/2; j++)
                        swap(nums[j+current], nums[nums_size-1-j]);
                }
                
            }
            
        }
        
    return nums;
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr = nums;
        vector<vector<int>> ret = {nums};
        curr = nextPermutation(curr);
        while(nums != curr)
        {
            if(curr != ret[ret.size()-1])
                ret.push_back(curr);
            curr = nextPermutation(curr);
        }
        return ret;
    }
};
