class Solution {
    public int[][] merge(int[][] ar) {
        int n = ar.length;
        Arrays.sort(ar,(a,b) -> a[0]-b[0]);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            int st = ar[i][0],ed = ar[i][1];
            if(!ans.isEmpty() && ans.get(ans.size()-1).get(1) >= ed)
                continue;
            for(int j=i+1;j<n;j++){
                if(ar[j][0] <= ed){
                    ed = Math.max(ed,ar[j][1]);
                }else{
                    break;
                }
            }
            ans.add(Arrays.asList(st,ed));
        }
        System.out.println(ans);
        int[][] res = new int[ans.size()][2];
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<2;j++){
                res[i][j] = ans.get(i).get(j);
            }
        }
        return res;
    }
}