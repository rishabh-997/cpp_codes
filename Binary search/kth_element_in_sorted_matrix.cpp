int binary(vector<int> &arr, int x) {
        int low = -1,high = arr.size(), mid;
        if(arr[0] > x)
            return 0;
        if(arr[high-1] <= x)
            return high;
        while(high>low+1) {
            mid = (high+low)/2;
            if(arr[mid] <= x)
                low = mid;
            else
                high = mid;
        }
        return low + 1;
    }

    int median(vector<vector<int>> &arr, int r, int c){
        int k = (r*c)/2;
        k++;
        int low = 0;
        int high = 1;
        for(int i = 0;i<r;i++)
            high += arr[i][c-1];
        int mid;
        
        while(high>low+1) {
            mid = (high+low) / 2;
            int cunt = 0;
            for(int i = 0;i<r;i++) {
                cunt = cunt + binary(arr[i], mid);
            }
            if(cunt<k)
                low = mid;
            else
                high = mid;
        }
        return high;
    }
