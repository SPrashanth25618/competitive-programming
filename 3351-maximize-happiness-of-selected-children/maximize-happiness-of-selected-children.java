class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        long sum = 0;
        Arrays.sort(happiness);
        int lo = 0,hi = n-1;        
        while(lo<=hi){
            int t = happiness[lo];
            happiness[lo] = happiness[hi];
            happiness[hi] = t;
            lo++;
            hi--;
        }
        sum += happiness[0];
        k--;        
        for(int i=1;i<=k;i++){
            if(happiness[i]-i > 0)         
                sum += happiness[i]-i;
        }
        return sum;
    }
}