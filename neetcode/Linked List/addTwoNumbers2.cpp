
// https://leetcode.com/problems/basic-calculator-ii/
// Normal Addition. try to do it constant space, you will have many edge cases to solve.

//

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode * l1p = l1, * l2p = l2;
        while (l1 != NULL && l2 != NULL) {
            sum += (l1->val + l2->val);
            l1->val = sum % 10;
            l2->val = sum%10;
            sum = sum/10;
            if (l1->next == NULL && l2->next == NULL) {
                if (sum != 0) {
                    ListNode *node = new ListNode(sum);
                    l1->next = node;
                }
                return l1p;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2 != NULL) {
            l1 = l2;
            l1p = NULL;
        }
        while(l1 != NULL) {
            sum += l1->val;
            l1->val = sum%10;
            sum = sum/10;
            if (l1->next != NULL)l1 = l1->next;
            else break;
        }
        if (sum != 0) {
            ListNode *node = new ListNode(sum);
            l1->next= node;
        }

        return l1p == NULL? l2p :l1p;

    }
};