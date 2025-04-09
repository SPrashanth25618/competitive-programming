class Solution {
public:
    bool check(vector<int>& piles,int h,int mid){
        long long cnt = 0;
        for(int i=0;i<piles.size();i++){
            cnt += ceil((double)piles[i]/(double)mid);
        }
        if(cnt <= h)
            return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(),piles.end());
        int lo = 1,hi = maxi,ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            // cout<<mid<<endl;
            if(check(piles,h,mid)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};