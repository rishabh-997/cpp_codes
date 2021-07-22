// check all numbers at all positions


   bool check(int grid[N][N], int row, int col, int num) {
        for(int i = 0;i<9;i++) {
            if(grid[i][col]==num)
                return false;
        }
        for(int i = 0;i<9;i++) {
            if(grid[row][i]==num)
                return false;
        }
        row = (row / 3) * 3;
        col = (col / 3) * 3;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (grid[i][j] == num)
                    return false;
            }
        }
        return true;
    }
    
    bool backtrack(int grid[N][N], int row = 0, int col = 0) {
        if(row==9)
            return true;
        if(col==9) 
            return backtrack(grid, row+1, 0);
        if(grid[row][col]!=0) {
            return backtrack(grid, row, col+1);
        }
        for(int i = 1;i<=9;i++) {
            if(check(grid, row, col, i)) {
                grid[row][col] = i;
                if(backtrack(grid, row, col+1))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    }
