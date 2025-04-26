// https://leetcode.com/problems/linked-list-cycle/

// Ans: use fast pointer and slow pointer


/**
* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next ==  NULL) return false;
        if (head->next->next ==  NULL) return false;
        auto s = head->next, f = head->next->next;

        while(f != NULL && f->next != NULL) {
            if (s == f) return true;
            s = s->next;
            f = f->next->next;
        }
        return false;

    }
};