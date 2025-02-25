class Solution {
public:
    int m = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long sum = 0,odd = 0;
        for(int &i:arr)
        {
            sum += i;
            odd += sum%2;
        }
        odd += (n-odd)*odd;
        return odd%m;
    }
};