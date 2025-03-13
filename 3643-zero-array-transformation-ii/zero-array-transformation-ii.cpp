class Solution {
public:
    int n, q;
    bool check_zeroes(vector<int>& nums) {
        for (int& i : nums) {
            if (i != 0)
                return false;
        }
        return true;
    }
    bool check(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);
        for (int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            diff[l] += val;
            if (r + 1 < n)
                diff[r + 1] -= val;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            diff[i] = sum;
            if (nums[i] - diff[i] > 0)
                return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        if (check_zeroes(nums))
            return 0;
        int lo = 0, hi = q - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(nums, queries, mid)) {
                ans = mid+1;
                hi = mid - 1;
            } 
            else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};