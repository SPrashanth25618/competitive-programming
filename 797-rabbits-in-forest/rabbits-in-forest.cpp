class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int &i:answers){
            mp[i]++;
        }
        int ans = 0;
        for (auto& [x, count] : mp) {
            int groupSize = x + 1;
            int groups = (count + groupSize - 1) / groupSize;
            ans += groups * groupSize;
        }
        return ans;
    }
};