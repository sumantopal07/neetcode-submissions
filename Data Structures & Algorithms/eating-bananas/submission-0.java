class Solution {
    public int minEatingSpeed(int[] ar, int h) {
        int low = 1 , high = Arrays.stream(ar).max().getAsInt(), ans = Arrays.stream(ar).max().getAsInt();
        while(low<=high) {
            int mid = low + (high - low)/2;
            int possible = 0;
            for(int i=0;i<ar.length; i++)
                possible += (ar[i]+mid-1)/mid;
            if(possible<=h) {
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
}
