class PrefixTree {
    struct Node {
        int children[26];
        bool isWord = false;
        Node() { fill(begin(children), end(children), -1); }
    };

    vector<Node> pool;

    int newNode() {
        pool.emplace_back();
        return pool.size() - 1;
    }

public:
    PrefixTree() {
        pool.reserve(1 << 16); // tune based on expected input size
        newNode(); // root = index 0
    }

    void insert(const string& word) {
        int cur = 0;
        for (char ch : word) {
            int idx = ch - 'a';
            if (pool[cur].children[idx] == -1) {
                pool[cur].children[idx] = newNode();
            }
            cur = pool[cur].children[idx];
        }
        pool[cur].isWord = true;
    }

    bool search(const string& word) {
        int node = findNode(word);
        return node != -1 && pool[node].isWord;
    }

    bool startsWith(const string& prefix) {
        return findNode(prefix) != -1;
    }

private:
    int findNode(const string& s) {
        int cur = 0;
        for (char ch : s) {
            int idx = ch - 'a';
            if (idx < 0 || idx >= 26 || pool[cur].children[idx] == -1) {
                return -1;
            }
            cur = pool[cur].children[idx];
        }
        return cur;
    }
};