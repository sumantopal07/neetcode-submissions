class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        map<vector<int>, vector<string>> ans;
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
