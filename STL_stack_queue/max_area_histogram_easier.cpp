int histogram(vector<int> &arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            left[i] = -1;
        else
            left[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (s.empty())
            right[i] = n;
        else
            right[i] = s.top();
        s.push(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = arr[i] * (right[i] - left[i] - 1);
        ans = max(ans, temp);
    }
    return ans;
}
