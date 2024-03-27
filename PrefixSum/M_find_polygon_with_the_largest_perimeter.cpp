// File: find_polygon_with_the_largest_perimeter.cpp

/*
    Leetcode Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/
*/

/*
    Problem Statement:
    Given an array nums of positive lengths of sides of a polygon, return the largest perimeter of a polygon that can be formed with any three of the lengths. If the perimeter is not possible, return -1.

    A polygon is valid if it can be formed by any three sides with the following two conditions:

    The sum of the lengths of the three sides is greater than zero.
    The length of any side is less than the sum of the lengths of the other two sides.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 1, 1, 2, 3, 5, 12, 50

        int n = nums.size();
        long long sum = 0;
        // find prefix sum
        // 1, 2, 4, 7, 12, 24, 74
        vector<long long> prefix(n, 0);
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[i] += sum;
        }

        long long res = -1;
        int k = 0; // k -> curr_length
        for(int i = 0; i < n-1; i++) {
            if(prefix[i] > nums[i+1]) { // adding nums[i+1] will give valid parameter
                res = prefix[i+1];
                // cout<<res<<endl;
                k = i+1;
                // cout<<k<<endl;
            } 
        }
        
        return k >= 2 ? res : -1;
    }
};
