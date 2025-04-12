class Solution {
public:
    void precompute(vector<int>& fact){
        for(int i=2;i<11;i++)
            fact[i] = i*fact[i-1];
    }
    long long countGoodIntegers(int n, int k) {
        vector<int> fact(11,1);
        precompute(fact);
        int d = (n+1)/2;
        int start = pow(10,d-1);
        int end = pow(10,d) - 1;
        unordered_set<string> st;
        for(int i=start;i<=end;i++){
            string istr = to_string(i);
            string full = "";
            if(n%2 == 0){
                string jstr = istr;
                reverse(jstr.begin(),jstr.end());
                full = istr+jstr;
            }else{
                string jstr = istr.substr(0,d-1);
                reverse(jstr.begin(),jstr.end());
                full = istr + jstr;
            }
            long long num = stoll(full);
            if(num%k != 0)
                continue;
            sort(full.begin(),full.end());
            st.insert(full);
        }
        long long ans = 0;
        for(const string &i:st){
            vector<int> cnt(10,0);
            for(const char &j:i){
                cnt[j-'0']++;
            }
            int len = i.length();
            int non_zeroes = len - cnt[0];
            long long premutation = (non_zeroes*fact[len-1]);
            for(int k=0;k<10;k++){
                premutation /= fact[cnt[k]];
            }
            ans += premutation;
        }
        return ans;
    }
};