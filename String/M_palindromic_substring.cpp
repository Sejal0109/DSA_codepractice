// File: palindromic_substrings.cpp

/*
    Leetcode Link: https://leetcode.com/problems/palindromic-substrings/description/
*/

/*
    Problem Statement:
    Given a string, your task is to count how many palindromic substrings in this string.

    The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

    A string is called a palindrome when it reads the same backward as forward.
*/

#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int t[1001][1001];

    bool checkPalindrome(string& s, int i, int j) {
        if(i > j) return true;

        if(t[i][j] != -1) return t[i][j];

        if(s[i] == s[j]) {
            return t[i][j] = checkPalindrome(s, i+1, j-1);
        }

        return t[i][j] = false;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        memset(t, -1, sizeof(t));

        // t[i][j] = -1, not solved yet
        // t[i][j] = 0, false, not palindrome
        // t[i][j] = 1, true

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {

                if(checkPalindrome(s, i, j)) count++;
            }
        }

        return count;
    }

};
