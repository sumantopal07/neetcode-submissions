class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        map<int,int> mp;
        for(int i=0; i<ar.size(); i++) {
            if(mp.count(target-ar[i])){
                return {mp[target-ar[i]],i};
            }
            mp[ar[i]]=i;
        }
        return vector<int>();
    }
};
