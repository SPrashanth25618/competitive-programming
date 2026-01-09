class Solution {
    int ar[];
    int[][] dp;

    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int len = cuts.length;
        ar = new int[len + 2];
        for (int i = 1; i <= len; i++) {
            ar[i] = cuts[i - 1];
        }
        ar[len + 1] = n;
        dp = new int[len + 2][len + 2];
        for (int i = 0; i < len + 2; i++) {
            Arrays.fill(dp[i], -1);
        }
        int m = len + 2;
        for (int i = m - 1; i >= 1; i--) {
            for (int j = 0; j < m - 1; j++) {
                if(i > j){
                    dp[i][j] = 0;
                    continue;
                }
                int mini = Integer.MAX_VALUE;
                for (int k = i; k <= j; k++) {
                    int val = ar[j + 1] - ar[i - 1];
                    mini = Math.min(mini, val + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = mini;
            }
        }        
        return dp[1][m-2];
    }
}