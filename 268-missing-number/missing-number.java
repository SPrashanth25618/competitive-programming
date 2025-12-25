class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n*(n+1)/2;
        int su = 0;
        for(int i:nums)
            su += i;
        return sum - su;
    }
}