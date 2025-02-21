class Solution {
    public String convert(String s, int n) {
        List<List<Character>> z = new ArrayList<>();
        for(int i=0;i<n;i++)
            z.add(new ArrayList<>());
        int k = 0,l = s.length();
        while(k<l)
        {
            for(int i=0;i<n && k<l;i++)
                z.get(i).add(s.charAt(k++));
            for(int i=n-2;i>=1 && k<l;i--)
                z.get(i).add(s.charAt(k++));
        }
        String ans = "";
        for(int i=0;i<n;i++){
            for(char ch:z.get(i))
                ans+=ch;
        }
        return ans;
    }
}