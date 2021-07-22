bool check(vector<string> &queen, int n, int row, int col) {
        for(int i = 0;i<n;i++) {
            if(queen[i][col]=='Q')
                return false;
        }
        for(int i = 0;i<n;i++) {
            if(queen[row][i]=='Q')
                return false;
        }
        for(int i = 0; i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(row+col == i+j) {
                    if(queen[i][j]=='Q')
                        return false;   
                }
                if(row-col == i-j) {
                    if(queen[i][j]=='Q')
                        return false;
                }
             }
        }
        return true;
    }

    void backtrack(vector<vector<string>> &ans, vector<string> &temp, int n, int cunt) {
        if(cunt>=n) {
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i<n;i++) {
            if(check(temp, n, cunt, i)) {
                temp[cunt][i] = 'Q';
                backtrack(ans, temp, n, cunt + 1);
                temp[cunt][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        vector<vector<string>> ans;
        vector<string> temp(n, s);
        backtrack(ans, temp, n, 0);
        return ans;
    }
