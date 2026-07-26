class Solution {
    public int[] twoSum(int[] ar, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i< ar.length;i++) {
            if(mp.containsKey(target-ar[i])) {
                 return new int[]{mp.get(target-ar[i]), i};
            }
            mp.put(ar[i], i);
        }
        return null;
    }
}
/*

class Solution {
public:
    vector<int> twoSum(vector<int>& ar, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<ar.size(); i++) {
            if(mp.count(target-ar[i])){
                return {mp[target-ar[i]],i};
            }
            mp[ar[i]]=i;
        }
        return vector<int>();
    }
};

*/