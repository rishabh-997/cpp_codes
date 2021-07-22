/**
* 1. Pick a node and run dfs
* 2. Finding longest distance node
* 3. Apply dfs on that node
* 4. Maximum distance is answer
*/


void dfs(vector<vector<int> > &adjList, vector<bool> &visited, vector<int> &depth, int node) {
    visited[node] = true;
    for (auto child: adjList[node]) {
	if (!visited[child]) {
	    depth[child] = 1 + depth[node];
	    dfs(adjList, visited, depth, child);
	}
    }
}

int main() {
   
    int n, a, b;
    cin >> n;
    vector<vector<int> > adjList(n + 1);
    vector<bool> visited(n + 1, false);
    vector<int> depth(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    // Apply DFS
    dfs(adjList, visited, depth, 1);
    b = 0, a = 1;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > b) {
            b = depth[i];
            a = i;
        }
    }
    visited.assign(visited.size(), false);
    depth.assign(depth.size(), 0);
    // Apply dfs from that node
    dfs(adjList, visited, depth, a);
    b = 0;
    for (int i = 1; i <= n; i++) {
        if (depth[i] > b)
            b = depth[i];
    }
    cout << b;
    return EXIT_SUCCESS;
}
