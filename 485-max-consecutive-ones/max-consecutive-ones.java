class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0,max_cnt = 0;
        for(int i:nums){
            if(i == 1){
                cnt++;
            }else{
                max_cnt = Math.max(max_cnt,cnt);
                cnt = 0;
            }
        }
        max_cnt = Math.max(max_cnt,cnt);
        return max_cnt;
    }
}