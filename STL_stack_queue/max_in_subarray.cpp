/**
* Maximum of all subarrays of size k
*/	


vector<int> max_of_subarrays(int *arr, int n, int k) {
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> ans;
        for (int i = k; i < n; i++) {
            ans.push_back(arr[q.front()]);
            while (!q.empty() && q.front() <= (i - k))
                q.pop_front();
            while (!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);
        }
        ans.push_back(arr[q.front()]);
        return ans;
    }
