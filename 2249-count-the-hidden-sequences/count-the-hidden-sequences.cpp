class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int cnt = 0;
        int mini = 0,maxi = 0;
        for(int &i:differences){
            cnt += i;
            mini = min(mini,cnt);
            maxi = max(maxi,cnt);
            if((upper-maxi) - (lower - mini) + 1 < 0)
                return 0;
        }
        return ((upper-maxi) - (lower - mini) + 1);
    }
};