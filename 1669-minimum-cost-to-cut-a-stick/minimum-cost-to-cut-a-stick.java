class Solution {
    int ar[];
    int[][] dp;
    public int minCost(int n, int[] cuts) {
        Arrays.sort(cuts);
        int len = cuts.length;
        ar = new int[len+2];
        for(int i=1;i<=len;i++){
            ar[i] = cuts[i-1];
        }
        ar[len+1] = n;
        dp = new int[len+2][len+2];
        for(int i=0;i<len+2;i++){
            Arrays.fill(dp[i],-1);
        }
        int ans = fun(1,ar.length-2);
        return ans;
    }

    public int fun(int i,int j){
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int mini = Integer.MAX_VALUE;
        for(int k=i;k<=j;k++){
            int val = ar[j+1] - ar[i-1];
            mini = Math.min(mini,val + fun(i,k-1) + fun(k+1,j));
        }
        return dp[i][j] = mini;
    }
}