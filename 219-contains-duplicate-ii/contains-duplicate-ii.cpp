class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            auto it = mp.find(nums[i]);
            if(it != mp.end() && abs(i-it->second)<=k){
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};