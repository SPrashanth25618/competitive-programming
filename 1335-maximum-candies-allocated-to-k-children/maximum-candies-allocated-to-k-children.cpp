class Solution {
public:
    bool check(vector<int>& candies, long long k, int val) {
        long long ans = 0;
        for (int& i : candies) {
            if (val > 0)
                ans += (i / val);
            if (ans >= k)
                return true;
        }
        return (ans >= k);
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long total_candies = accumulate(candies.begin(), candies.end(), 0LL);
        if (total_candies < k)
            return 0;
        int maxi = *max_element(candies.begin(),candies.end());
        int lo = 1, hi = maxi;
        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(candies, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else
                hi = mid - 1;
        }
        return ans;
    }
};