class Solution {
public:
    string check(string val){
        string ans="";
        int i=0;
        while(i<val.length()){
            int j = i;
            while(j+1<val.length() && val[j+1] == val[j])
                j++;
            int cnt = j-i+1;
            ans += (to_string(cnt)+val[i]);
            i = j+1;
        }
        return ans;
    }
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string val = "1";
        for(int i=2;i<=n;i++)
        {
            val = check(val);
        }
        return val;
    }
};