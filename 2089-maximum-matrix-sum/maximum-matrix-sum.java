class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int cnt = 0;
        int n = matrix.length,m = matrix[0].length;
        long sum = 0;
        int mini = Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] < 0){
                    cnt++;
                }
                sum += Math.abs(matrix[i][j]);
                mini = Math.min(mini,Math.abs(matrix[i][j]));
            }
        }
        return (cnt%2 == 0)?sum : sum - 2*mini;
    }
}