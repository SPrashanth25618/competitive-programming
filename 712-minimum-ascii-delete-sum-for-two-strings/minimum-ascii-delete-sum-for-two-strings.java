class Solution {
    int[][] dp;
    int n,m;
    public int minimumDeleteSum(String s1, String s2) {
        n = s1.length();
        m = s2.length();
        dp = new int[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j] = -1;
        return fun(0,0,s1,s2);
    }
    public int fun(int i,int j,String s1,String s2){
        if(i >= n && j >= m)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i >= n)
            return dp[i][j] = (int)s2.charAt(j) + fun(i,j+1,s1,s2);
        else if(j >= m) 
            return dp[i][j] = (int)s1.charAt(i) + fun(i+1,j,s1,s2);
        if(s1.charAt(i) == s2.charAt(j))
            return dp[i][j] = fun(i+1,j+1,s1,s2);
        int val1 = s1.charAt(i) + fun(i+1,j,s1,s2);
        int val2 = s2.charAt(j) + fun(i,j+1,s1,s2);
        return dp[i][j] = Math.min(val1,val2);
    }
}