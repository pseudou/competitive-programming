
// https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Ans; have a hash map from old Node pointer to the new Node pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        unordered_map<Node*, Node*> m;

        Node* copy= new Node(head->val);
        Node* trh = head->next;
        m[head] = copy;

        while (trh != NULL) {
            Node *newNode = new Node(trh->val);
            m[trh] = newNode;
            copy->next = newNode;
            copy = newNode;
            trh = trh->next;
        }
        copy = m[head];
        trh = head;
        while (trh != NULL) {
            m[trh]->random = m[trh->random];
            trh = trh->next;
        }

        return m[head];
    }
};