/**
*	PRIM Algo to find MST
*/

int spanningTree(int n, vector<vector<int>> adj[]) {
        int ans = 0;
        vector<bool> vis(n, false);
        priority_queue<pi, vector<pi>, greater<> > pq;
        // distance, node
        pq.push({0, 0});
        while(!pq.empty()) {
            pi temp = pq.top();
            pq.pop();
            int node = temp.second, cost = temp.first;
            if(vis[node])
                continue;
            vis[node] = true;
            ans = ans + cost;
            for(auto x: adj[node]) {
                int v = x[0], w = x[1];
                if(!vis[v]) {
                    pq.push({w, v});
                }
            }
        }
        return ans;
    }
