pass starting vertex in dfs function

	vector<vector<int>> adj; 
	int n; // number of vertices

	vector<bool> visited;

	void dfs(int v) {
	    visited[v] = true;
	    for (int u : adj[v]) {
		if (!visited[u])
		    dfs(u);
	    }
	}
