class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length,m = grid[0].length;
        int cnt = 0;
        for(int i=0;i<=n-3;i++){
            for(int j=0;j<=m-3;j++){
                if(isMagicSquare(grid,i,j))
                    cnt++;
            }
        }
        return cnt;
    }
    public boolean isMagicSquare(int[][] grid,int i,int j){        
        boolean[] vis = new boolean[10];
        for(int k=i;k<i+3;k++){
            for(int l=j;l<j+3;l++){
                int val = grid[k][l];
                if(val < 1 || val > 9 || vis[val])
                    return false;
                vis[val] = true;
            }
        }        
        int sum = grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for(int k=i;k<i+3;k++){
            int row_sum = 0;
            for(int l=j;l<j+3;l++){
                row_sum += grid[k][l];
            }
            if(row_sum != sum){
                return false;
            }
        }
        for(int l=j;l<j+3;l++){
            int col_sum = 0;
            for(int k=i;k<i+3;k++){
                col_sum += grid[k][l];
            }
            if(col_sum != sum)
                return false;
        }
        int diag1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
        int diag2 = grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
        return diag1 == sum && diag2 == sum;
    }
}