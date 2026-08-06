class Solution {
public:
    int rob(vector<int>& ar) {
        int n=ar.size();
        vector<int> dp(n,0);
        if(n==0)
            return 0;
        if(n==1)
            return ar[0];
        int max_prev_prev = ar[0];
        int max_prev=max(ar[1],ar[0]);
        int ans = max(max_prev_prev,max_prev );
        for(int i=2;i<n;i++) {
            int temp=max(max_prev, ar[i]+max_prev_prev);
            max_prev_prev = max_prev;
            max_prev = temp;
            ans = max(max_prev , max_prev_prev);
        }
            ans = max(max_prev , max_prev_prev);

        return ans;

    }
};
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& ar) {

        
//     }
// };
