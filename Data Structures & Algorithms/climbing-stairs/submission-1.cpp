class Solution {
    int dp[46]={};
public:
    int climbStairs(int n) {
        if(n==1)
            return dp[1]=1;
        if(n==2)
            return dp[2] = 2;
        if(dp[n]!=0)
            return dp[n];
        dp[n] = climbStairs(n-2) + climbStairs(n-1);
        return dp[n];
    }
};
