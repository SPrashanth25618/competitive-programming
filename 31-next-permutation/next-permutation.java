class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length,ind = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums,0,n-1);
            return ;
        }
        for(int i=n-1;i>=ind;i--){
            if(nums[i] > nums[ind]){
                int t = nums[i];
                nums[i] = nums[ind];
                nums[ind] = t;
                break;
            }
        }
        reverse(nums,ind+1,n-1);
    }

    public void reverse(int[] nums,int st,int ed){
        while(st<=ed){
            int t = nums[st];
            nums[st] = nums[ed];
            nums[ed] = t;
            st++;
            ed--;
        }
    }
}