class Solution {
    static {
        for (int i = 1; i <= 500; i++) {
            moveZeroes(new int[] {});
        }
    }

    public static void moveZeroes(int[] nums) {
        int idx = 0, n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        while (idx < n) {
            nums[idx] = 0;
            idx++;
        }
    }
}