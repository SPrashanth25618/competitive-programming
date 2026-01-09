class Solution {
    public String removeOuterParentheses(String s) {
        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        for(char ch : s.toCharArray()){            
            if(ch == '('){
                if(cnt > 0)
                    sb.append('(');
                cnt++;                
            }else{
                cnt--;
                if(cnt > 0) 
                    sb.append(')');
            }
        }
        return sb.toString();
    }
}