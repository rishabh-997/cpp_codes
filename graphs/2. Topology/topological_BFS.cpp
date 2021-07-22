// Topological sorting in ascendind form of all possible permutations;
// Use queue to reduce time complexity if any answer is acceptable;

	for (int i = 0; i < edges; i++) {
            cin >> a >> b;
            adjList[a].push_back(b);
            inDegree[b]++;
        }

        set<int> pQueue;
        vector<int> ans;
        for (int i = 1; i <= vertex; i++) {
            if (inDegree[i] == 0)
                pQueue.insert(i);
        }

        while (!pQueue.empty()) {
            auto x = pQueue.begin();
            ans.push_back(*x);
            for (auto child: adjList[*x]) {
                inDegree[child]--;
                if (inDegree[child] == 0)
                    pQueue.insert(child);
            }
            pQueue.erase(x);
        }
        if (ans.size() != vertex) {
            cout << "Sandro fails.";
            return EXIT_SUCCESS;
            // cycle found
        }
        for (auto x:ans)
            cout << x << " ";
