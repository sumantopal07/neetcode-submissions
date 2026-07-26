class Solution {
public:
    vector<int> productExceptSelf(vector<int>& ar) {
        int n=ar.size();
        vector<int> product_till_now(n,1), product_till_yet(n,1);
        product_till_now[0]=ar[0];
        product_till_yet[n-1]=ar.back();
        for(int i=1;i<n;i++) {
            product_till_now[i]=product_till_now[i-1] * ar[i];
        }
        for(int i=n-2;i>=0;i--) {
            product_till_yet[i]=product_till_yet[i+1] * ar[i];
        }
        
        vector<int> ans(n,1);
        ans[0] = product_till_yet[1];
        ans[n-1]  = product_till_now[n-2];
        for(int i=1;i<n-1;i++) {
            ans[i] = product_till_now[i-1] * product_till_yet[i+1];
        }
        return ans;
        

    }
};
