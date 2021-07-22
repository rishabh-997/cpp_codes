#include <bits/stdc++.h>

using namespace std;
#define fastRead() ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<set<int> >

const int max_n = 1e17;
const int min_n = -1e17;
const int MOD = 1e9 + 7;

vvi adjList;
vi degree;
vb visited;
int n, m;

void dfs(int node) {
    visited[node] = true;
    for (auto child: adjList[node]) {
        if (!visited[child])
            dfs(child);
    }
}

void resize() {
    adjList.resize(n + 1);
    visited.resize(n + 1);
    visited.assign(visited.size(), false);
    degree.resize(n + 1);
    degree.assign(degree.size(), 0);
}

bool remains() {
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if(!visited[i] && !adjList[i].empty())
            return true;
    }
    return false;
}

int32_t main() {
    fastRead()
    int a, b;
    cin >> n >> m;
    resize();

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adjList[a].insert(b);
        adjList[b].insert(a);
        degree[a]++, degree[b]++;
    }

    if (remains()) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE";
            return EXIT_SUCCESS;
        }
    }

    stack<int> head, tail;
    head.push(1);
    while (!head.empty()) {
        while (degree[head.top()] != 0) {
            int v = head.top();
            int child = *adjList[v].begin();
            adjList[v].erase(adjList[v].begin());
            adjList[child].erase(v);
            degree[child]--, degree[v]--;
            head.push(child);
        }
        while (!head.empty() && !degree[head.top()]) {
            tail.push(head.top());
            head.pop();
        }
    }
    while (!tail.empty()) {
        cout << tail.top() << " ";
        tail.pop();
    }

    return EXIT_SUCCESS;
}
