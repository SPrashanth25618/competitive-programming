class Solution {
public:
    bool check(vector<int>& nums)
    {
        unordered_set<int> st;
        for(int &i:nums){
            st.insert(i);
        }
        int flg = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0)
            {
                flg = 1;
                break;
            }
        }
        return ((st.size() == nums.size()) && !flg);
    }
    vector<int> applyOperations(vector<int>& nums) {
        if(check(nums)){
            return nums;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        int j = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                j = i;
                break;
            }
        }
        for(int i=j+1;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;   
    }
};