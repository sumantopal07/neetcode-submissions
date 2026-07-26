int EXISTS_FURTHER=0;
int WORD_ENDS=1;
int WORD_ENDS_AND_EXISTS_FURTHER=2;

class PrefixTree {
public:
    map<string, int> root;   // <-- keyed by the prefix path, not (index,char)

    PrefixTree() {}

    void insert(string word) {
        for(int i=0;i<word.size();i++) {
            string key = word.substr(0, i+1);   // <-- prefix up to and including i
            if(!root.count(key)) {
                root[key] = (i==word.size()-1) ? WORD_ENDS : EXISTS_FURTHER;
            }
            else if(root[key]==EXISTS_FURTHER) {
                root[key] = (i==word.size()-1) ? WORD_ENDS : EXISTS_FURTHER;
            }
            else if(root[key]==WORD_ENDS) {
                root[key] = (i==word.size()-1) ? WORD_ENDS : WORD_ENDS_AND_EXISTS_FURTHER;
            }
        }
    }

    bool search(string word) {
        for(int i=0;i<word.size();i++) {
            string key = word.substr(0, i+1);
            if(!root.count(key)) return false;
            if((root[key]==WORD_ENDS || root[key]==WORD_ENDS_AND_EXISTS_FURTHER) && i==word.size()-1) {
                return true;
            }
        }
        return false;
    }

    bool startsWith(string word) {
        for(int i=0;i<word.size();i++) {
            string key = word.substr(0, i+1);
            if(!root.count(key)) return false;
            if(i==word.size()-1) return true;
        }
        return false;
    }
};