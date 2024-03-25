// File: 704_binary_search.cpp

/*
    Leetcode Link: https://leetcode.com/problems/binary-search/
*/

/*
    Problem Statement:
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    You must write an algorithm with O(log n) runtime complexity.
*/

#include <vector>

using namespace std;

class Solution {
public:
    // Iterative approach for binary search
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int l = 0, r = n-1;
        
        int mid = 0;
        
        while(l <= r) {
            
            mid = l + (r-l)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        
        return -1;
    }
    
    // Recursive approach for binary search
    // Time Complexity: O(log n)
    // Space Complexity: O(log n)
    int searchRecursive(vector<int>& nums, int target, int l, int r) {
        if (l > r)
            return -1;
        
        int mid = l + (r - l) / 2;
        
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            return searchRecursive(nums, target, mid + 1, r);
        else
            return searchRecursive(nums, target, l, mid - 1);
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return searchRecursive(nums, target, 0, n - 1);
    }
};
