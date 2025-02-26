class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> mp;
    int tot_income;

    bool DFS_bob(int cur,int time,vector<bool>& visited)
    {
        visited[cur] = true;
        mp[cur] = time;
        if(cur == 0)
            return true;
        for(int f:adj[cur])
        {
            if(!visited[f] && DFS_bob(f,time+1,visited))
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
        else if(time == mp[cur]){
            income += amount[cur]/2;
        }

        if(adj[cur].size() == 1 && cur != 0)
            tot_income = max(tot_income,income);
        
        for(int i:adj[cur])
        {
            if(!visited[i])
            {
                Alice(i,time+1,income,visited,amount);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = edges.size();
        tot_income = INT_MIN;
        for(vector<int>& edg : edges)
        {
            int u = edg[0];
            int v = edg[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        int time = 0;
        DFS_bob(bob,time,visited);

        visited.assign(n,false);
        int income = 0;
        Alice(0,0,income,visited,amount);
        return tot_income;
    }
};