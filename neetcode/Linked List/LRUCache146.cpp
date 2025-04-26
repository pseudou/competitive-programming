
// https://leetcode.com/problems/lru-cache/description/
// unordered map key-> Node pointer. create a doubly linkedlist with curr cap and max cap.
class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val, Node* _next, Node* _prev) {
            key = _key;
            val = _val;
            next = _next;
            prev = _prev;
        }
    };



    unordered_map<int, Node*> m;
    Node* tail;
    Node* head;
    int currCap;
    int maxCap;

    LRUCache(int capacity) {
        head = new Node(-1, -1, NULL, NULL);
        tail = new Node(-1, -1, head, NULL);
        head->next = tail;
        currCap = 0;
        maxCap = capacity;
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        } else {
            removeNode(m[key]);
            addNode(m[key]);
        }
        return m[key]->val;
    }
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            removeNode(m[key]);
            addNode(m[key]);
            m[key]->val = value;
            return;
        }

        Node *n = new Node(key, value, head, head->next);
        addNode(n);
        m[key] = n;
        if (currCap == maxCap) {
            Node* deleteN = tail->prev;
            deleteNode(deleteN);
        } else {
            currCap++;
        }
    }

    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next = node;
        node->next->prev = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void deleteNode(Node* deleteN) {
        removeNode(deleteN);
        m.erase(deleteN->key);
        delete deleteN;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */