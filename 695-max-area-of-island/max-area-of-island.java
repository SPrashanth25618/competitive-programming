class Solution {
    int[][] g;
    boolean[][] vis;
    int[] x = {-1,0,1,0};
    int[] y = {0,1,0,-1};
    public int maxAreaOfIsland(int[][] grid) {
        int n = grid.length,m = grid[0].length;
        vis = new boolean[n][m];
        g = grid;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != true && grid[i][j] == 1){
                    int val = dfs(i,j);
                    ans = Math.max(ans,val);
                }
            }
        }
        return ans;
    }

    public int dfs(int i,int j){
        if(i<0 || j<0 || i>=g.length || j>=g[0].length || g[i][j] == 0 || vis[i][j])
            return 0;
        vis[i][j] = true;
        int val = 1;
        for(int k=0;k<4;k++){
            val += dfs(i+x[k],j+y[k]);
        }
        return val;
    }
}