class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> small;
        vector<int> big;
        for(int &i:nums)
        {
            if(i<pivot)
                small.push_back(i);
            else if (i > pivot){
                big.push_back(i);
            }
        }
        int tot = small.size()+big.size();
        if((nums.size() - tot)!=0){
            int n = nums.size();
            int ele = n - tot,k=0;
            for(int i=0;i<small.size();i++){
                nums[k] = small[i];
                k++;
            }
            while(ele--){
                nums[k] = pivot;
                k++;
            }
            for(int i=0;i<big.size();i++){
                nums[k] = big[i];
                k++;
            }
        }
        else{
            int n = nums.size();
            int ele = n - tot,k=0;
            for(int i=0;i<small.size();i++){
                nums[k] = small[i];
                k++;
            }
            nums[k] = pivot;
            k++;
            for(int i=0;i<big.size();i++){
                nums[k] = big[i];
                k++;
            }
        }
        return nums;
    }
};