class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;
        int lo = 0, hi = n - 1, mid = 0;
        while(mid <= hi) {
            if (nums[mid] == 0) {
                int t = nums[mid];
                nums[mid] = nums[lo];
                nums[lo] = t;
                lo++;
                mid++;
            } else if (nums[mid] == 2) {
                int t = nums[mid];
                nums[mid] = nums[hi];
                nums[hi] = t;
                hi--;
            }else{
                mid++;
            }
        }
    }
}