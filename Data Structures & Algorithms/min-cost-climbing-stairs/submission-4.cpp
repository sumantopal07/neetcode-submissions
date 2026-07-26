class Solution {
public:
    int minCostClimbingStairs(vector<int>& ar) {
        int n = ar.size();
        int choice1=ar[0];
        int choice2=ar[1];

        for(int i=2;i<n;i++){
            int cur  = min(choice1,choice2) + ar[i];
            choice1=choice2;
            choice2 = cur;
        }
        return min(choice1,choice2);
        
    }
};
