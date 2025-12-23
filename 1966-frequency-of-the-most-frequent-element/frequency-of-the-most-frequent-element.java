class Solution {
    public int maxFrequency(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int i = 0,maxi = 0;
        long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];
            while((long)nums[j]*(j-i+1)-sum > k){
                sum -= nums[i];
                i++;
            }
            int len = j-i+1;
            if((long)len*nums[j]-sum <= k){
                maxi = Math.max(maxi,len);
            }
        }
        return maxi;
    }
}