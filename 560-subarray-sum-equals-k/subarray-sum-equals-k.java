class Solution {
    public int subarraySum(int[] nums, int k) {        
        HashMap<Integer,Integer> mp = new HashMap<>();
        int cnt = 0,sum = 0;
        mp.put(0,1);
        for(int i:nums){
            sum += i;
            int rem = sum - k;
            if(mp.containsKey(rem)){
                cnt += mp.get(rem);
            }
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return cnt;
    }
}