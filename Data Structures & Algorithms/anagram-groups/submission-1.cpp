struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;

        for (int x : v) {
            hash = hash * 31 + x;
        }

        return hash;
    }
};
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<vector<int>, vector<string>,VectorHash> ans;
        for(string &i : s) {
            vector<int> anagram(26,0);
            for(char &ch :i)
                anagram[ch-'a']++;
            // if(ans.count(anagram)) 
                ans[anagram].push_back(i);
            // else 
                // ans[anagram]=vector<string>(i,1);
        }
        vector<vector<string>> answer;
        for(auto &i:ans)
            answer.push_back(i.second);
        return answer;        
    }
};
