class Solution {
    public void sortInWave(int arr[]) {
        int n = arr.length;
        for(int i=0;i<n;i+=2){
            if(i+1 < n){
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = t;
            }
        }
    }
}
