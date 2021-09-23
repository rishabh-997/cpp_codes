#define pp pair<int, int> 

int dx[8] = {-1,1,0,0};
int dy[8] = {0,0,1,-1};

int solve(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pp> q;
    
    if(n==1 && grid[0][0]==0) 
        return 1; 
    
    q.push({0,0});
    
    int count=0;
    while(q.size()){
        
        int c = q.size();
        
        while(c--){
            
            auto curr = q.front();
            q.pop();
            
            for(int i=0;i<4;++i){
                
                int row = dx[i] + curr.first;
                int col = dy[i] + curr.second;
                
                if(row<0 || col<0 || row>=n || col>=m) 
                    continue;
                
                if(grid[row][col]=='#') 
                    continue;
                
                grid[row][col] = '#;
                
                if(row==n-1 && col==m-1) 
                    return count+1;
                q.push({row,col});
            }
        }
        count++;
    }
    return -1;
}

string reachend(vector<string> grid, int k) {
    int ans = solve(grid);
    if(ans==-1)
    	return "No";
    if(ans<=k)
        return "Yes";
    else
        return "No";
}
