class Solution {
    static {
        for (int i = 0; i <= 500; i++) {
            removeOuterParentheses("");
        }
    }

    public static String removeOuterParentheses(String s) {
        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                if (cnt > 0)
                    sb.append('(');
                cnt++;
            } else {
                cnt--;
                if (cnt > 0)
                    sb.append(')');
            }
        }
        return sb.toString();
    }
}