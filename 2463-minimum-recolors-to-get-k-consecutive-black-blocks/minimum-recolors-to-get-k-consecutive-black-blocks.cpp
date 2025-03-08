class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX,cnt = 0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i] == 'W')
                cnt++;
        }
        ans = min(ans,cnt);
        for(int i=1;i<=blocks.size()-k;i++)
        {
            if(blocks[i-1] == 'W')
                cnt--;
            if(blocks[i+k-1] == 'W')
                cnt++;
            ans = min(ans,cnt);
        }
        return ans;
    }
};