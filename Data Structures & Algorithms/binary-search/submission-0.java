class Solution {
    public int search(int[] ar, int target) {
        int low=0, high = ar.length - 1;
        while(low<=high) {
            int mid =low+(high-low)/2;
            if(ar[mid]<target) {
                low = mid+1;
            }
            else if (ar[mid]>target){
                high = mid-1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
}
