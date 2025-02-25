class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0,n = arr.size();
        int sum = 0,odd =0,even = 1;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum%2!=0)
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
        return ans%m;
    }
};