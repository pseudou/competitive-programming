
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Use recursion to count from the back. if the count == n+1 then you will have to remove the next element
// make sure to keep a unique value if the nth element is removed. If it is not removed then you will have
// to remove the head;

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
    int checkNode(ListNode* head, int n) {
        if (head == NULL) return 0;
        int curr = 1 + checkNode(head->next, n);
        if (curr == n + 1) {
            head->next = head->next->next;
            return -2;
        }
        return curr == -1? -2: curr;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || head->next == NULL) return NULL;
        int curr = checkNode(head, n);
        if (curr != -2) {
            head = head->next;
        }
        return head;
    }
};