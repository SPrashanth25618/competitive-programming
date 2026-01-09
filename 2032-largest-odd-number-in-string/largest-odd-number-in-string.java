class Solution {
    static {
        for (int i = 0; i < 200; i++) {
            largestOddNumber("");
        }
    }

    public static String largestOddNumber(String num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if ((num.charAt(i) - '0') % 2 != 0) {
                return num.substring(0, i + 1);
            }
        }
        return "";
    }
}