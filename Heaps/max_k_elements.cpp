	void heapify(int arr[], int n, int i)  {
		int par = i;
		int left = 2*i + 1;
		int right = 2*i + 2;
		if(left<n && arr[left] > arr[par])
		    par = left;
		if(right<n && arr[right] > arr[par])
		    par = right;
		if(par!=i) {
		    swap(arr[par], arr[i]);
		    heapify(arr, n, par);
		}
	}
    
	vector<int> kLargest(int arr[], int n, int k) {
	    for(int i = (n/2)-1;i>=0;i--)
	        heapify(arr, n, i);
	    vector<int> ans;
	    for(int i = n-1;i>=(n-k);i--) {
	        swap(arr[0], arr[i]);
	        heapify(arr, i, 0);
	        ans.push_back(arr[i]);
	    }
	    return ans;
	}
