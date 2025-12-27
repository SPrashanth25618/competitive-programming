class Solution {
    public int majorityElement(int[] nums) {
        int ele = nums[0],cnt = 1;
        for(int i=1;i<nums.length;i++){
            if(cnt == 0){
                ele = nums[i];
            }
            if(nums[i] == ele){
                cnt++;
            }else{
                cnt--;
            }
        }
        return ele;
    }
}