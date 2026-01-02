class Solution {
    public int[][] merge(int[][] ar) {
        int n = ar.length;
        Arrays.sort(ar,(a,b) -> a[0]-b[0]);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            int st = ar[i][0],ed = ar[i][1];
            if(ans.isEmpty() || st > ans.get(ans.size()-1).get(1)){
                ans.add(Arrays.asList(st,ed));
            }else{
                ans.get(ans.size()-1).set(1,Math.max(ans.get(ans.size()-1).get(1),ed));
            }
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