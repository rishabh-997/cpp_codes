struct compare {
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        if (a.first == b.first) {
            return (a.second < b.second);
        } else {
            return a.first > b.first;
        }
    }
};

vector<string> topKFrequentWords(vector<string> &arr, int k) {
    map<string, int> mp;
    for (auto x:arr)
        mp[x]++;
    priority_queue<pair<int, string>, vector<pair<int, string> >, compare> pq;
    for (auto x: mp) {
        pair<int, string> temp = {x.second, x.first};
        pq.push(temp);
        if (pq.size() > k)
            pq.pop();
    }
    vector<string> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
