class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] ar = new int[n+m];
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                ar[k] = nums1[i];
                k++; i++;
            }else{
                ar[k] = nums2[j];
                k++; j++;
            }
        }
        while(i<m){
            ar[k] = nums1[i];
            k++; i++;
        }
        while(j<n){
            ar[k] = nums2[j];
            k++; j++;
        }
        for(int l=0;l<n+m;l++){
            nums1[l] = ar[l];
        }
    }
}