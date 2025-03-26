class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size(),m=grid[0].size();
        vector<int> ar;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ar.push_back(grid[i][j]);
            }
        }
        int si = ar.size();
        nth_element(ar.begin(),ar.begin()+si/2,ar.end());
        int ans = 0;
        int value = ar[si/2];
        for(int &i:ar){
            if(i%x != value%x)
                return -1;
            ans += abs(value-i)/x;
        }
        return ans;
    }
};