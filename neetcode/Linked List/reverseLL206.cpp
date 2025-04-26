

// https://leetcode.com/problems/reverse-linked-list/
// normal while loop where head->next != NULL, keep a track of previous node.

/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        while (head != NULL ) {
            auto n = head->next;
            head->next = prev;
            prev = head;
            head = n;
        }
        return prev;

    }
};