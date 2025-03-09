class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0,n = colors.size();
        for(int i=0;i<k-1;i++)
            colors.push_back(colors[i]);
        int i = 0,j = 1;
        while(j<colors.size())
        {
            if(colors[j] == colors[j-1])
            {
                i = j;
                j++;
                continue;
            }
            if(j-i+1 == k){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};