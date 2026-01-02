class Solution {
    public int[][] merge(int[][] ar) {
        int n = ar.length;
        Arrays.sort(ar,(a,b) -> a[0]-b[0]);
        List<int[]> ans = new ArrayList<>();
        for(int[] i:ar){
            if(ans.isEmpty() || i[0] > ans.get(ans.size()-1)[1]){
                ans.add(new int[]{i[0],i[1]});
            }else{
                ans.get(ans.size()-1)[1] = Math.max(ans.get(ans.size()-1)[1],i[1]);
            }
        }        
        return ans.toArray(new int[ans.size()][2]);
    }
}