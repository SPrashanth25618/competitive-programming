class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int res = 0;
        int end = 0,n = meetings.size();
        for(int i=0;i<n;i++){
            if(meetings[i][0] > end){
                res += meetings[i][0] - end - 1;
            }
            end = max(meetings[i][1],end);
        }
        if(end < days){
            res += (days - end);
        }
        return res;
    }
};