class Solution {
public:
    int rob(vector<int>& ar) {
        int n=ar.size();
        vector<int> dp(n,0);
        if(n==0)
            return 0;
        if(n==1)
            return ar[0];
        dp[0]=ar[0];
        dp[1]=max(ar[1],ar[0]);
        for(int i=2;i<n;i++)
            dp[i]=max(dp[i-1], ar[i]+dp[i-2]);
        return max(dp[n-1],dp[n-2]);

    }
};
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& ar) {

        
//     }
// };
