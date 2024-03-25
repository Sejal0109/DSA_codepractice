// File: 48_rotate_image.cpp

/*
    Leetcode Link: https://leetcode.com/problems/rotate-image/
*/

/*
    Problem Statement:
    You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
    You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include <vector>

using namespace std;

class Solution {
public:
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrixT(n, vector<int>(n));

        // TRANSPOSE
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrixT[j][i] = matrix[i][j];
            }
        }
        
        // MIRROR
        for (int i = 0; i < n; i++)
        {
            int k = n-1;
            for(int j = 0; j < n; j++)
            {
                matrix[i][k] = matrixT[i][j];
                k--;
            }
        }
    }
};
