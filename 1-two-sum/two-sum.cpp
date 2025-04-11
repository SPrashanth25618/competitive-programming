class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mp;
        int n = nums.size();
        int x,y;
        for(int i=0;i<n;i++)
        {
            x = target - nums[i],y = nums[i];
            if( mp.find(x) != mp.end() )
                return {mp[x],i};
            mp[y] = i;
        }
        return {};
    }
};