class Solution {
public:
    bool check(vector<int>& ranks, int cars,long long val)
    {
        long long ans = 0;
        for(int &i:ranks){
            ans += (int)sqrt(val/i);
            if(ans >= cars)
                return true;
        }
        return (ans >= cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        int maxi = *max_element(begin(ranks),end(ranks));
        long long lo = 1,hi = maxi*1ll*cars*1ll*cars;
        long long ans = 0;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            if(check(ranks,cars,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};