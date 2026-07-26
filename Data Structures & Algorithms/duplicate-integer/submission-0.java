class Solution {
    public boolean hasDuplicate(int[] ar) {
        Set<Integer> st = new HashSet<>();
        for(int i: ar) {
            if(st.contains(i)){
                return true;
            }
            st.add(i);
        }
        return false;
    }
}