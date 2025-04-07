class Solution {
public:
    int dp[201][20001];
    bool partition_sum(vector<int>& nums,int i,int su){
        if(su == 0)
            return true;
        if(i >= nums.size())
            return false;
        if(dp[i][su] != -1)
            return dp[i][su];
        int include = false;
        if(nums[i] <= su){
            include = partition_sum(nums,i+1,su-nums[i]);
        }
        bool exclude = partition_sum(nums,i+1,su);
        return dp[i][su] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2 !=0)
            return false;
        int su = sum/2;
        memset(dp,-1,sizeof(dp));
        return partition_sum(nums,0,su);
    }
};