class Solution {
    public String reverseWords(String s) {
        s = s.strip().replaceAll("\\s+", " ");;
        String[] words = s.split(" ");
        reverse(words,0,words.length-1);
        StringBuilder sb = new StringBuilder();        
        for(int i=0;i<words.length;i++){            
            sb.append(words[i]);
            if(i != words.length-1)
                sb.append(" ");
        }
        return sb.toString();
    }
    public void reverse(String[] ar,int st,int ed){
        while(st < ed){
            String t = ar[st];
            ar[st] = ar[ed];
            ar[ed] = t;
            st++;
            ed--;
        }
    }
}