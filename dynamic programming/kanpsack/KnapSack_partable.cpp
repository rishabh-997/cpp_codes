/*
	N = 3, W = 50
	values[] = {60,100,120}
	weight[] = {10,20,30}
	
	Output:
	240.00
*/

    static bool compare(Item a,Item b) {
        double x = ((double)a.value)/(a.weight);
        double y = ((double)b.value)/(b.weight);
        return x>y;
    }
    
    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr + n, compare);
        double ans = 0;
        for(int i = 0;i<n;i++) {
            int val = arr[i].value;
            int wt = arr[i].weight;
            if(w==0)
                return ans;
            if(wt<=w) {
                ans = ans + (val);
                w = w - wt;
            } else {
                ans = ans + (val * ((double) w / wt));
                w = 0;
            }
        }
        return ans;
    }
