class Solution {
    public int countNegatives(int[][] grid) {
        int n = grid.length,m = grid[0].length;
        int row = n-1,col = 0;
        int cnt = 0;
        while(row>=0 && col<m){
            if(grid[row][col] >= 0){
                col++;
            }else{
                cnt += (m-col);
                row--;
            }
        }
        return cnt;
    }
}