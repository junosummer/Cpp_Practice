/* Leetcode Problem 48 Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

*/

// reflect the image twice, first about the right up to left down diagonal line, second about the horizontal mid line.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int image_size = matrix.size();
        for(int i = 0; i < image_size; i++)
        {
            for(int j = 0; j< image_size-i; j++)
            {
                swap(matrix[i][j], matrix[image_size-1-j][image_size-1-i]);
            }
        }
        
        for (int i = 0; i < image_size/2; i++)
        {
            for (int j = 0; j < image_size; j++)
            {
                swap(matrix[i][j], matrix[image_size-1-i][j]);
            }
        }
    }
};
