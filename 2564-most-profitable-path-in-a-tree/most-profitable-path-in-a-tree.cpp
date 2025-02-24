class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> mp;
    int max_amount;
    bool __bob(int cur,int time,vector<bool>& visited)
    {
        visited[cur] = true;
        mp[cur] = time;
        if(cur == 0)
            return true;
        for(int& dg : adj[cur])
        {
            if(!visited[dg] && __bob(dg,time + 1,visited))
                return true;
        }
        mp.erase(cur);
        return false;
    }

    void Alice(int cur,int time,int income,vector<bool>& visited,vector<int>& amount)
    {
        visited[cur] = true;
        if(mp.find(cur) == mp.end() || time < mp[cur])
        {
            income += amount[cur];
        }
        else if(time == mp[cur])
        {
            income += amount[cur]/2;
        }

        if(adj[cur].size() == 1 && cur != 0)
        {
            max_amount = max(max_amount,income);
        }

        for(int& dg:adj[cur])
        {
            if(!visited[dg])
                Alice(dg,time + 1,income,visited,amount);
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        for(vector<int>& edg:edges)
        {
            int u = edg[0];
            int v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        max_amount = INT_MIN;
        int time = 0;
        vector<bool> visited(n,false);
        __bob(bob,time,visited);

        int income = 0;
        visited.assign(n,false);
        Alice(0,0,income,visited,amount);
        return max_amount;
    }
};