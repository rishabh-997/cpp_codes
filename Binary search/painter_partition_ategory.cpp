// Painter partition problem
// Book Allocation problem

    int solve(int arr[], int n, int pages) {
        int i = 0, ans = 0, curr = 0;
        while(i<n) {
            if(curr + arr[i] <=pages) {
                curr += arr[i];
                i++;
            } else {
                ans++;
                curr = 0;
            }
        }
        if(curr>0)
            ans++;
        return ans;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) {
        int low = INT_MIN, high = 1, mid;
        int ans = -1;
        for(int i = 0;i<n;i++) {
            low = max(low, arr[i]);
            high += arr[i];
        }
        while(low <= high) {
            mid = (low+high)/2;
            int temp = solve(arr, n, mid);
            if(temp > m)
                low = mid + 1;
            else {
                high = mid - 1;
            }
        }
        return low;
    }

