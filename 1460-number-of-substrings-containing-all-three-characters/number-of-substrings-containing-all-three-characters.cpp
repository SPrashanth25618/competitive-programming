class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int i=0,j=0;
        int ans = 0;
        unordered_map<char,int> mp;
        while(j<n){
            char ch = s[j];
            mp[ch]++;
            while(i<n && mp.size() == 3){
                ans += n-j;
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};