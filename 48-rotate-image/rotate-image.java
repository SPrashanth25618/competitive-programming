class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i],0,n-1);
        }        
    }
    public void reverse(int[] ar,int st,int ed){
        while(st<=ed){
            int t = ar[st];
            ar[st] = ar[ed];
            ar[ed] = t;
            st++;
            ed--;
        }
    }
}