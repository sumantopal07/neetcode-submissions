class PrefixTree {
    struct Node {
        Node* children[26] = {nullptr};
        bool isWord = false;
        ~Node() {
            for (Node* c : children) delete c;
        }
    };

    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    ~PrefixTree() {
        delete root;
    }

    void insert(string word) {
        Node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->children[idx]) {
                cur->children[idx] = new Node();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        Node* node = findNode(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(string prefix) {
        return findNode(prefix) != nullptr;
    }

private:
    Node* findNode(const string& s) {
        Node* cur = root;
        for (char ch : s) {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26 || !cur->children[idx]) {
                return nullptr;
            }
            cur = cur->children[idx];
        }
        return cur;
    }
};