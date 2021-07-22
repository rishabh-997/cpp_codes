

	void dfs(vector<int> adj[], vector<int> &ans, vector<bool> &vis, int node) {
	    vis[node] = true;
	    for(auto x: adj[node]) {
	        if(!vis[x]) {
	            dfs(adj, ans, vis, x);
	        }
	    }
	    ans.push_back(node);
	}


	vector<int> topoSort(int v, vector<int> adj[]) {
	    vector<bool> vis(v, false);
	    vector<int> ans;
	    for(int i = 0;i<v;i++) {
	        if(!vis[i]) {
	            dfs(adj, ans, vis, i);
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}


