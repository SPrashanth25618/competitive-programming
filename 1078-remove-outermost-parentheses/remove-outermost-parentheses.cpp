class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";
        int cnt = 0;
        for(char ch:s){
            if(ch == '(')
            {
                if(!st.empty())
                    ans += ch;
                st.push(ch);
            }
            else{
                st.pop();
                if(!st.empty())
                    ans += ch;
            }
        }
        return ans;
    }
};