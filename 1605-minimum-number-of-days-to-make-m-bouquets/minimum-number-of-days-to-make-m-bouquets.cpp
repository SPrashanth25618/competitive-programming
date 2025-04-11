class Solution {
public:
    bool check(vector<int>& bloomDay,int day,int k,int m){
        int cnt = 0,val = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }else{
                val += cnt/k;
                cnt = 0;
            }
        }
        val += cnt/k;
        return (val>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int lo = 1,hi = *max_element(bloomDay.begin(),bloomDay.end());
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(bloomDay,mid,k,m)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};