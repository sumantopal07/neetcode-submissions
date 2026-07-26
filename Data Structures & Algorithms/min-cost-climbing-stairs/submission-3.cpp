class Solution {
public:
    int minCostClimbingStairs(vector<int>& ar) {
        int n = ar.size();
        int choice1=ar[0];
        int choice2=ar[1];

        for(int i=2;i<n;i++){
            if(choice1>choice2) {
                choice1=choice2;
                choice2 = choice2 + ar[i];
            }
            else  {
                int temp = choice2;
                choice2 = choice1 + ar[i];
                choice1 = temp;
            }
            // dp[i] = min(dp[i-1],dp[i-2])+ar[i];
        }
        return min(choice1,choice2);
        
    }
};
