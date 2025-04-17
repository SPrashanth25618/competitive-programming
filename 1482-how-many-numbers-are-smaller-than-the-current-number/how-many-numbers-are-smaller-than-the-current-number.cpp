class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        /*
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[j] < nums[i])
                    ans[i]++;
            }
        }
        return ans;
        */
        vector<int> cnt(101,0);
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        for(int i=1;i<100;i++){
            cnt[i] = cnt[i]+cnt[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                ans[i] = 0;
            }
            else
                ans[i] = cnt[nums[i]-1];
        }
        return ans;
    }
};