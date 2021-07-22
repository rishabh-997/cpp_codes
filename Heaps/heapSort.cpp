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


void heapSort(int arr[], int n) {
    int index = (n/2) - 1;
    for(int i = index;i>=0;i--) {
        heapify(arr, n, i);
    }
        
    for(int i = n-1;i>=0;i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
