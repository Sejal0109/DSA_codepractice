// File: missing_number.cpp

/*
    Leetcode Link: https://leetcode.com/problems/missing-number/description/
*/

/*
    Problem Statement:
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

    Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }
};
