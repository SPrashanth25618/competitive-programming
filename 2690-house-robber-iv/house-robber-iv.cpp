class Solution {
public:
    bool check(vector<int>& nums, int k,int mid)
    {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= mid){
                cnt++;
                i++;
            }
            if(cnt == k)
                return true;
        }
        return (cnt >= k);
    }
    int minCapability(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(),nums.end());
        int hi = *max_element(nums.begin(),nums.end());
        int ans = hi;
        while(lo <= hi)
        {
            int mid = lo+(hi-lo)/2;
            if(check(nums,k,mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};