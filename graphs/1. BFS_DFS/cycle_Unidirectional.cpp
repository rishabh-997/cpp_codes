// Printing a cycle present in system


void dfs(int node, vector<vector<int> > &adjList, vector<int> &visited, vector<int> &parent) {
    visited[node] = 1;
    for (auto child: adjList[node]) {
        if (visited[child] == 0) {
            parent[child] = node;
            dfs(child, adjList, visited, parent);
        } else if (visited[child] == 1) {
            int temp = node;
            vector<int> ans;
            ans.push_back(child);
            while (temp != child) {
                ans.push_back(temp);
                temp = parent[temp];
            }
            ans.push_back(child);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto x:ans)
                cout << x << " ";
            exit(0);
        }
    }
    visited[node] = 2;
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
        vector<int> visited(vertex + 1, 0);
        vector<int> parent(vertex + 1);

        for (int i = 0; i < edges; i++) {
            cin >> a >> b;
            adjList[a].push_back(b);
        }

        for (int i = 1; i <= vertex; i++) {
            if (!visited[i])
                dfs(i, adjList, visited, parent);
        }
        cout << "IMPOSSIBLE";
    }
    return EXIT_SUCCESS;
}
