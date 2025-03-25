class Solution {
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < result.back()[1]) { 
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor;
        vector<vector<int>> vert;
        for(auto &cor : rectangles) {
            int x1 = cor[0];
            int y1 = cor[1];
            int x2 = cor[2];
            int y2 = cor[3];
            hor.push_back({x1, x2});
            vert.push_back({y1, y2});
        }
        vector<vector<int>> res1 = merge(hor);
        if(res1.size() >= 3)
            return true;
        vector<vector<int>> res2 = merge(vert);
        return res2.size() >= 3;
    }
};