class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &i:nums)
            mp[i]++;
        int val = 0;
        for(auto i:mp){
            val += i.second/2;
        }
        return (val == (nums.size()/2));
    }
};