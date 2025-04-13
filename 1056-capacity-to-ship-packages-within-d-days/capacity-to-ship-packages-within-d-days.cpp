class Solution {
public:
    bool check(vector<int>& weights,int mid,int m){
        int cnt = 1;
        int load = 0;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > mid){
                cnt++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }
        return (cnt <= m);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = -1;
        int sum = accumulate(weights.begin(),weights.end(),0);
        int lo = *max_element(weights.begin(),weights.end()),hi = sum;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(weights,mid,days)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};