/* M-COLORING PROBLEM
1. travle all nodes from 0 to n-1
2. check all possible colors on that node
3. if possible, go to next node to color
4. Else backtrack and check alternative color
*/


bool check(vector<vector<int> > &arr, vector<int> &color, int n, int node, int c) {
    for(int i = 0;i<n;i++) {
        if(arr[node][i] && color[i]==c) 
            return false;
    }
    return true;
}

bool backtrack(vector<vector<int> > &arr, vector<int> &color, int m, int n, int node) {
    if(node==n)
        return true;
        
    for(int i = 1;i<=m;i++) {
        if(check(arr, color, n, node, i)) {
            color[node] = i;
            if(backtrack(arr, color, m, n, node+1)) {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v) {
    vector<int> color(v, 0);
    vector<vector<int> > arr(v, vector<int> (v, 0));
    for(int i =0;i<v;i++) {
        for(int j = 0;j<v;j++) {
            if(graph[i][j])
                arr[i][j] = 1;
        }
    }
    
    if(backtrack(arr, color, m, v, 0)) 
        return true;
    return false;
}

