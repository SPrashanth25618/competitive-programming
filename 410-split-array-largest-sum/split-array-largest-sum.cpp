class Solution {
public:
    bool check(vector<int>& nums,int n,int mid,int k){
        int par_sum = 0,cnt = 1;
        for(int i=0;i<n;i++){
            if(par_sum + nums[i] <= mid){
                par_sum += nums[i];
            }else{
                cnt++;
                par_sum = nums[i];
            }
        }
        return (cnt <= k);
    }

    int splitArray(vector<int>& nums, int k) {
        int ans = -1,n = nums.size();
        int lo = *max_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(nums,n,mid,k)){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};