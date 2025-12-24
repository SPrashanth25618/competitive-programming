class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int m = strs[0].length();
        int cnt = 0;
        boolean[] flg = new boolean[n-1];
        for(int i=0;i<m;i++){
            boolean check = false;
            for(int j=0;j<n-1;j++){
                if(!flg[j] && strs[j].charAt(i) > strs[j+1].charAt(i)){
                    check = true;
                    break;
                }
            }
            if(check){
                cnt++;
                continue;
            }
            for(int j=0;j<n-1;j++){
                if(!flg[j] && strs[j].charAt(i) < strs[j+1].charAt(i)){
                    flg[j] = true;
                }
            }            
        }
        return cnt;
    }
}