/**
*	This code creates sparse table for a function
	1. Second part shows evaluation for O(1);
*/


int maxx = 17;

int main() {

    int n, q;
    int sparse[n][maxx];
    
    // 1. Creating sparse table
    for (int i = 0; i < n; i++) {
        sparse[i][0] = arr[i];
    }

    for (int j = 1; j <= maxx; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
  
    // 2. Evaluating queries on sparse table (indempotent cases)
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, ans = INT32_MAX, laag;
        cin >> a >> b;
        laag = (int) log2(b - a + 1);
        ans = min(sparse[a][laag], sparse[b - (1 << laag) + 1][laag]);
        cout << ans << "\n";
    }
    return EXIT_SUCCESS;
}
