bool dfs(vector<bool> &visited, vector<vector<int> > &adjList, vector<int> &team, int vertex, int current) {
    visited[vertex] = true;
    team[vertex] = current;
    for (auto child: adjList[vertex]) {
        if (team[vertex] == team[child])
            return false;
        if (!visited[child]) {
            if (!dfs(visited, adjList, team, child, (current + 1) % 2))
                return false;
        }
    }
    return true;
}

int main() {
    fastRead()
    ll t;
    //cin >> t;
    t = 1;
    while (t--) {
        int vertex, edges, a, b;
        cin >> vertex >> edges;
        vector<vector<int> > adjList(vertex + 1);
        for (int i = 0; i < edges; i++) {
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        vector<bool> visited(vertex + 1, false);
        vector<int> team(vertex + 1, -1);
        for (int i = 1; i <= vertex; i++) {
            if (!visited[i]) {
                if (!dfs(visited, adjList, team, i, 0)) {
                    cout << "IMPOSSIBLE";
                    return 0;
                }
            }
        }
        for (int i = 1; i <= vertex; i++)
            cout << (team[i] + 1) << " ";
    }
    return EXIT_SUCCESS;
}
