class Solution {
public:
    int longestConsecutive(vector<int>& ar) {
        unordered_map<int,int> p;
        int n = ar.size();
        if(n==0 )
            return 0;
        int ans=1,prev=ar[0],curr=1;
        sort(ar.begin(),ar.end());
        for(int i=1;i<n;i++) {
            curr=(ar[i]-1 == ar[i-1]) ? curr + 1 : (ar[i-1]==ar[i]) ? curr : 1;
            prev=ar[i];
            ans=max(ans,curr);
        }
        return ans;
    }
};
