class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size() == k)
        {
            return *max_element(nums.begin(),nums.end());
        }
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            cout<<i<<endl;
            for(int j=i;j<=i+k-1;j++)
            {
                mp[nums[j]]++;
            }
        }
        int ans = -1;
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second == 1)
            {
                ans = max(ans,it.first);
            }
        }
        if(mp.size() == 1 && k > 1)
        {
            auto it = mp.begin();
            ans = max(ans,it->first);
        }
        return ans;
    }
};