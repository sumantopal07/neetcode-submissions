bool cmp(vector<int>&a, vector<int>&b) {
    return a[1]>b[1];
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& ar, int k) {
        vector<vector<int>> v;
        unordered_map<int,int> mp;
        for(int i=0; i<ar.size(); i++) {
            mp[ar[i]]++;
        }
        for(auto &i: mp)
            v.push_back({i.first,i.second});
        sort(v.begin(), v.end(),cmp);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i][0]);
        return ans;
    }
};
