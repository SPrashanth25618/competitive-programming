class Solution {
public:
    int solve(int i,int j,vector<int>& arr,unordered_map<int,int>& mp)
    {
        int sum = arr[j] - arr[i];
        if(mp.find(sum) != mp.end() && mp[sum]<i)
        {
            int k = mp[sum];
            return solve(k,i,arr,mp)+1;
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++)
            mp[arr[i]] = i;
        int i = 0,j,n = arr.size();
        int cnt,max_len = INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int len = solve(i,j,arr,mp);
                max_len = max(max_len,len);
            }
        }
        return (max_len < 3)?0:max_len;
    }
};
