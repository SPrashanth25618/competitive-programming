class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        int cnt = 0;
        while(n>0){
            n >>= 1;
            cnt++;
        }
        return (int)pow(2,cnt);
    }
};