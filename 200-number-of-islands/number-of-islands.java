class Solution {
    char[][] g;
    boolean[][] vis;
    int[] x = { -1, 0, 1, 0 };
    int[] y = { 0, 1, 0, -1 };

    public int numIslands(char[][] grid) {
        int n = grid.length,m = grid[0].length;
        vis = new boolean[n][m];
        g = grid;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != true && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,n,m);
                }
            }
        }
        return ans;
    }

    public void dfs(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || g[i][j] == '0'){
            return ;
        }
        vis[i][j] = true;
        for(int k=0;k<4;k++)
            dfs(i+x[k],j+y[k],n,m);
    }
}