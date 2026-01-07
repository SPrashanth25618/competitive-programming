class Solution {
    int m = (int) 1e9 + 7;
    public int numSubseq(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int i = 0, j = n - 1, cnt = 0;
        int[] powof2 = new int[n];
        powof2[0] = 1;
        for(int k=1;k<n;k++){
            powof2[k] = (powof2[k-1]*2)%m;
        }
        while (i <= j) {
            int sum = nums[i] + nums[j];
            if (sum <= target) {
                cnt = (cnt + powof2[j-i]) % m;
                i++;     
            } else {
                j--;
            }
        }
        return cnt;
    }
}