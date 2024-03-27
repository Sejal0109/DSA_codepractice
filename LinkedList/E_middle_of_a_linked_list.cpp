// File: middle_of_the_linked_list.cpp

/*
    Leetcode Link: https://leetcode.com/problems/middle-of-the-linked-list/description/
*/

/*
    Problem Statement:
    Given a non-empty, singly linked list with head node head, return a middle node of linked list.

    If there are two middle nodes, return the second middle node.
*/

/**
 * Definition for singly-linked list.
 */
#include <cstddef>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *p = new ListNode;
        int lgth = 0;
        p = head;
        while(p != NULL) {
            lgth++;
            p = p->next;
        }
        lgth = lgth / 2 ;
        p = head;
        while(lgth) {
            p = p->next;
            lgth--;
        }
        return p;
    }
};
