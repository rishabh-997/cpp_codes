vector<vector<int>> adj;
int n; // number of vertices

vector<int> color;
/**
*	0 = unvisited
*	1 = reached
*	2 = finished
*/

vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v] = 1;
    for (int u : adj[v])
        if (color[u] == 0)
            dfs(u);
    color[v] = 2;
    time_out[v] = dfs_timer++;
}
