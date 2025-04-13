class Solution {
public:
    bool check(vector<int>& nums,int mid,int m){
        long sum = 0;
        for(int i:nums){
            sum += ceil((double)i/(double)mid);
        }
        return (sum <= m);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        int sum = *max_element(nums.begin(),nums.end());
        int lo = 1,hi = sum;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(nums,mid,threshold)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};