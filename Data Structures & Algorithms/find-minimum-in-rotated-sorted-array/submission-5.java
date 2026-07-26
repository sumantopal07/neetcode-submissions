class Solution {
    public int findMin(int[] ar) {
        int low = 0 , high = ar.length-1 , ans = ar[0];
        while(low<=high) { 
            int mid = low + (high - low)/2;
            System.out.println(low + " " + mid + " " + high);
            if(ar[0]<=ar[mid]) {
                low = mid+1;
            }
            else {
                ans = Math.min(ar[mid],ans);
                high= mid-1;
            }
        }
        return ans;
        
    }
}
