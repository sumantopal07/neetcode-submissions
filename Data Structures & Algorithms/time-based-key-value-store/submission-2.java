class TimeMap {
    Map<String,List<Pair<String,Integer>>> mp;

    public TimeMap() {
        mp = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        if(mp.get(key) == null) {
            mp.put(key, new ArrayList<>());
        }
       
            mp.get(key).add(new Pair<>(value, timestamp));        
    }
    
    public String get(String key, int timestamp) {
        if(mp.get(key) == null) {
            return "";
        }
        List<Pair<String, Integer>> time =  mp.get(key);
        int low=0,high=time.size()-1, ans = -1;
        // System.out.println(low + " " + high);
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(time.get(mid).getValue() <= timestamp) {
                ans=mid;
                low=mid+1;
            }
            else {
                high = mid-1;
            }
        }
        // System.out.println(ans);
        if(ans==-1)
            return "";
        return time.get(ans).getKey();
    }
}
