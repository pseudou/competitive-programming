// https://leetcode.com/problems/reorder-list/description/
// use slow and fast pointer to find the mid. then point the mid to null and everything after
// mid, reverse it. Now you have two listedlist, merge them alternatively.

// example : 1 2 3 4 5
// l1: 1 2
// l2: 5 4 3
// 1 5 2 4 3

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

    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return ;
        int l = 0;
        auto c = head;
        while (c != NULL) {
            l++;
            c = c->next;
        }
        int h = ceil((float)(l-1)/2);

        c = head;
        while (h != 1) {
            h--;
            c= c->next;
        }
        auto n = c->next;
        c->next = NULL;

        n = reverseList(n);
        c= head;

        while(c!= NULL && n != NULL) {
            auto nextc = c->next ;
            auto nextn = n->next ;
            c->next = n;
            if(nextc != NULL) n->next = nextc;
            c= nextc;
            n = nextn;
        }

    }
};