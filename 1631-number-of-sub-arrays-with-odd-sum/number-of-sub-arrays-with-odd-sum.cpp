class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0,n = arr.size();
        vector<int> presum(n);
        presum[0] = arr[0];
        for(int i=1;i<n;i++)
            presum[i] = presum[i-1] + arr[i];
        int even = 1,odd = 0;
        for(int i=0;i<n;i++)
        {
            if(presum[i]%2!=0)
            {
                ans = (ans + even)%m;
                odd++;
            }
            else
            {
                even++;
                ans = (ans + odd)%m;
            }
        }
        return ans;
    }
};