class Solution {
public:
    long long get(string& str, string& s, int limit) {
        if (str.length() < s.length())
            return 0;
        long long cnt = 0;
        string trailing = str.substr(str.length() - s.length());
        int rem = str.length() - s.length();
        for (int i = 0; i < rem; i++) {
            int val = str[i] - '0';
            if (val <= limit) {
                cnt += val * pow(limit + 1, rem - i - 1);
            } else {
                cnt += pow(limit + 1, rem - i);
                return cnt;
            }
        }
        if (trailing >= s)
            cnt += 1;
        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string startstr = to_string(start-1);
        string finishstr = to_string(finish);
        return get(finishstr, s, limit) - get(startstr, s, limit);
    }
};