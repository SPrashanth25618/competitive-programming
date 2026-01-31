class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int ans = '{';
        for(char a : letters)
        {
            if(a > target)
                ans = Math.min(ans, a);
        }
        return (ans == '{') ? letters[0] : (char)ans;
    }
}