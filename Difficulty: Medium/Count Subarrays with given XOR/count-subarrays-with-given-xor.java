class Solution {
    public long subarrayXor(int arr[], int k) {
        int n = arr.length;
        long ans = 0;
        HashMap<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int val = 0;
        for(int i=0;i<n;i++){
            val ^= arr[i];
            int rem = val^k;
            if(mp.containsKey(rem)){
                ans += mp.get(rem);
            }
            mp.put(val,mp.getOrDefault(val,0)+1);
        }
        return ans;
    }
}