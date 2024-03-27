// File: least_number_of_unique_integers_after_k_removals.cpp

/*
    Leetcode Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
*/

/*
    Problem Statement:
    Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

    Note: the same integer can be removed multiple times from the array.

    Return the least number of unique integers after removing exactly k elements.
*/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> P;

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp; 
        int n = arr.size();
        for(int i = 0; i < n; i++) mp[arr[i]]++; // store freq
        priority_queue<P, vector<P>, greater<P>> pq;
        for(auto item: mp) {
            pq.push({item.second, item.first});
        }

        while(k--) {
            auto curr = pq.top();
            int freq = curr.first;
            freq--;
            pq.pop();
            if(freq > 0) {
                pq.push({freq, curr.second});
            }
        }
        
        return pq.size();
    }
};
