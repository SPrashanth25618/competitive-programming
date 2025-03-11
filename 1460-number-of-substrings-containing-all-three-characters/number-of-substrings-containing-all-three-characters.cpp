class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int j=0;
        int ans = 0;
        vector<int> mp(3,-1);
        while(j<n){
            char ch = s[j];
            mp[ch - 'a'] = j;
            if(mp[0]!=-1 && mp[1]!=-1 && mp[2]!=-1){
                ans += (1+min(mp[0],min(mp[1],mp[2])));
            }
            j++;
        }
        return ans;
    }
};