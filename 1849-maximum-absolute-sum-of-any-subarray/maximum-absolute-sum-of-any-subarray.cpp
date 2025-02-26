class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0,max_sum = INT_MIN;
        for(int &i:nums)
        {
            sum += i;
            max_sum = max(max_sum,sum);
            if(sum < 0)
                sum = 0;
        }
        sum = 0;
        int min_sum = INT_MAX;
        for(int &i:nums)
        {
            sum += i;
            min_sum = min(min_sum,sum);
            if(sum > 0)
                sum = 0;
        }
        return max(abs(min_sum),max_sum);
    }
};