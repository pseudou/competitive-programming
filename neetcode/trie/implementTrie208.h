

class Trie {
public:

    class TreeNode {
    public:
        bool isEnd;
        vector<TreeNode*> child;

        TreeNode() {
            isEnd = false;
            child.resize(26, NULL);
        }

        void setNode(char c) {
            child[c-'a'] = new TreeNode();
        }

        TreeNode* getNode(char c) {
            return child[c - 'a'];
        }

    };
    TreeNode *head;
    Trie() {
        head = new TreeNode();
    }

    void insert(string word) {
        TreeNode *h = head;
        for (int i=0; i <word.size(); i++) {
            if (h->getNode(word[i]) != NULL) {
                h = h->getNode(word[i]);
            } else {
                h->setNode(word[i]);
                h = h->getNode(word[i]);
            }
        }
        h->isEnd = true;
    }

    bool search(string word) {
        TreeNode *h = head;
        for (int i=0; i <word.size(); i++) {
            if (h->getNode(word[i]) == NULL) {
                return false;
            } else {
                h = h->getNode(word[i]);
            }
        }
        return h->isEnd;
    }

    bool startsWith(string prefix) {
        TreeNode *h = head;
        for (int i=0; i <prefix.size(); i++) {
            if (h->getNode(prefix[i]) == NULL) {
                return false;
            } else {
                h = h->getNode(prefix[i]);
            }
        }
        return true;
    }
};