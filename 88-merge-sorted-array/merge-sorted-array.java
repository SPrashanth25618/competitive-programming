class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int len = m+n;
        int gap = (len/2) + (len%2);
        while(gap > 0){
            int i=0,j=i+gap;
            while(j<len){
                if(i<m && j>=m){
                    swap(nums1,nums2,i,j-m);
                }else if(i>=m){
                    swap(nums2,nums2,i-m,j-m);
                }else{
                    swap(nums1,nums1,i,j);
                }
                i++;
                j++;
            }
            if(gap == 1)
                break;
            gap = (gap/2)+(gap%2);
        }
        for(int k=m;k<n+m;k++){
            nums1[k] = nums2[k-m];
        }
    }
    public void swap(int[] ar1,int[] ar2,int i,int j){
        if(ar1[i] > ar2[j]){
            int t = ar1[i];
            ar1[i] = ar2[j];
            ar2[j] = t;
        }
    }
}