class Solution {
    public double separateSquares(int[][] squares) {
        double totarea = (double)0;
        int y = 0;
        for(int[] sq:squares){
            int l = sq[2];
            totarea += (double)l*l;
            y = Math.max(y,sq[1]+l);
        }
        double lo = (double)0,hi = (double)y;
        double ans = 0.00000;
        while(hi-lo > 1e-5){
            double mid = lo + (hi-lo)/2.0;
            ans = mid;
            if(check(mid,squares,totarea)){
                hi = mid;
            }else{
                lo = mid;
            }
        }
        return ans;
    }
    public boolean check(double mid,int[][] squares,double totarea){
        double bottomarea = 0.0;
        for(int[] sq:squares){
            double l = (double)sq[2];
            double ty = sq[1]+l;
            double by = sq[1];
            if(mid >= ty){
                bottomarea += (double)l*l;                
            }else if(mid > by){
                bottomarea += (double)l*(mid-by);
            }
        }
        return (bottomarea >= (totarea - bottomarea));
    }
}