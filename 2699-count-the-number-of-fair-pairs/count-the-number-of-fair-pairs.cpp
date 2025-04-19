class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        for(int i=0;i+1<n;i++){
            auto low = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto high = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            cnt += (high-low);
        }
        return cnt;
    }
};