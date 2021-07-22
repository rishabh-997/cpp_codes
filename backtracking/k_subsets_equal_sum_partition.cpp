// can an array be divided into k subset of equal sum


bool f(int arr[], vector<bool> &vis, 
                    int n, int k, int target, int curr, int index) {
        if(k==0)
            return true;
        if(curr==target) {
            return f(arr, vis, n, k-1, target, 0, 0);
        }
        for(int i = index;i<n;i++) {
            if(!vis[i] && curr+arr[i]<=target) {
                vis[i] = true;
                if(f(arr, vis, n, k, target, curr+arr[i], i + 1))
                    return true;
                vis[i] = false;
            }
        }
        return false;
    }
  
    bool isKPartitionPossible(int arr[], int n, int k) {
        sort(arr, arr+n);
        reverse(arr, arr+n);
        int sum = 0;
        for(int i = 0;i<n;i++)
            sum += arr[i];
        if(k==1)
            return true;
        if(sum%k)
            return false;
        vector<bool> vis(n, false);
        return f(arr, vis, n, k, sum/k, 0, 0);
    }

