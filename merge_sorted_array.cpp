// Leetcode Problem 88 Merge Sorted Array

// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

class Solution {
public:
    
    /* The first solution use the method of vector, and to insert smaller element into the sorted nums1
       However, this is not very proper as the problem specification says array (can't change the size)
       See below for a faster and cleaner solution to move the currently largest element to the end of nums1
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator iter = nums1.begin();
        int curr1 = 0;
        int curr2 = 0;
        int count = 0;
        int nums1_size = nums1.size();
        nums1.erase(iter+m, iter+nums1_size);
        while (count < m && curr2 < n)
        {
            if(nums1[curr1] > nums2[curr2])
            {
                nums1.insert(iter+curr1, nums2[curr2]);
                curr1++;
                curr2++;
            }
            else
            {
                curr1++;
                count++;
            }
        }
        if(curr2<n)
        {
            for (int i = curr2; i< n; i++)
                nums1.push_back(nums2[i]);
        }
    }
    
    
    
    
    // A better, faster and cleaner solution
    void fastermerge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while( n > 0 )
            nums1[ n + m - 1] = ( m == 0 || nums2[n-1] > nums1[m-1]) ? nums2[--n] : nums1[--m];
    }
};
