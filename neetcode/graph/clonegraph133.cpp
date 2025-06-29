/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        if (m.find(node) != m.end()) {
            return m[node];
        }
        Node* newnode = new Node(node->val);
        m[node] = newnode;
        for (Node *n : node->neighbors) {
            newnode->neighbors.push_back(cloneGraph(n));
        }
        return newnode;
    }
};