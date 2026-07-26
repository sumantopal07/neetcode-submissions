class Solution {
public:
    int minCostClimbingStairs(vector<int>& ar) {
        int n = ar.size();
        vector<int> dp(n,0);
        dp[0]=ar[0];
        dp[1]=ar[1];

        for(int i=2;i<n;i++){
            dp[i] = min(dp[i-1],dp[i-2])+ar[i];
        }
        return min(dp[n-1],dp[n-2]);
        
    }
};
