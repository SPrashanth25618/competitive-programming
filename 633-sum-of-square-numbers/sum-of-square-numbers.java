class Solution {
    public boolean judgeSquareSum(int c) {
        long i=0,j=(long)Math.sqrt(c);
        while(i<=j){
            long sqsum = (long)(i*i + j*j);
            if(sqsum == c)
                return true;
            else if(sqsum > c)
                j--;
            else
                i++;
        }
        return false;
    }
}