class Solution {
    int m = (int) 1e9+7;
    int[][] dp;
    String[] states = {
            "RYR", "RYG", "RGR", "RGY",
            "YRY", "YRG", "YGR", "YGY",
            "GRG", "GRY", "GYR", "GYG"
    };    
    public int numOfWays(int n) {
        dp = new int[n][12];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        int res = 0;
        for(int i=0;i<12;i++){
            res = (res + getcount(n-1,i))%m;
        }
        return res;
    }

    public int getcount(int n,int prev){
        if(n == 0)
            return 1;
        if(dp[n][prev] != -1)
            return dp[n][prev];
        int res = 0;
        String last = states[prev];
        for(int i=0;i<12;i++){
            if(i == prev)
                continue;
            String curr = states[i];
            boolean flg = false;
            for(int j =0;j<3;j++){
                if(curr.charAt(j) == last.charAt(j)){
                    flg = true;
                    break;
                }
            }
            if(!flg){
                res = (res + getcount(n-1,i))%m;
            }
        }
        return dp[n][prev] = res;
    }
}