class Solution {
    int n,m;
    int[][] dp;
    public int maxDotProduct(int[] nums1, int[] nums2) {
        n = nums1.length;
        m = nums2.length;
        dp = new int[501][501];
        for(int i=0;i<501;i++){
            Arrays.fill(dp[i],(int)-1e6);
        }
        return fun(nums1,nums2,0,0);
    }

    public int fun(int[] ar1,int[] ar2,int i,int j){
        if(i == n || j == m){
            return (int)-1e6;
        }
        if(dp[i][j] != (int) -1e6)
            return dp[i][j];
        int val = ar1[i]*ar2[j];
        int val2 = val + fun(ar1,ar2,i+1,j+1);
        int val3 = fun(ar1,ar2,i+1,j);
        int val4 = fun(ar1,ar2,i,j+1);        
        dp[i][j] = Math.max(val,Math.max(val2,Math.max(val3,val4)));
        return dp[i][j];
    }
}