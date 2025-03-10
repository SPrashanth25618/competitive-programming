class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int n = word.size();
        vector<int> check(n);
        int last = n;
        for(int i=n-1;i>=0;i--){
            check[i] = last;
            if(!isVowel(word[i]))
                last = i;
        }
        unordered_map<char,int> mp;
        int cnt = 0;
        int i=0,j=0;
        while(j<n) {
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else{
                cnt++;
            }

            while(i<n && cnt > k){
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    cnt--;
                }
                i++;
            }
            while(i<n && mp.size() == 5 && cnt == k){
                int index = check[j];
                ans += index - j;
                char ch = word[i];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};