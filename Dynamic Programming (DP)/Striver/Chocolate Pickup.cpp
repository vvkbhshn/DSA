//problem link: https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(c,vector<int>(c,0)));
    int index=1;
    for(int row=0;row<r;row++){
        for(int x=0;x<min(c,row+1);x++){
            for(int y=max(0,c-1-row);y<c;y++){
                int res=0;
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(min(x+i,y+j)<0 || max(x+i,y+j)>=c) continue;
                        res=max(res,dp[1-index][x+i][y+j]);
                    }
                }
                if(x==y) dp[index][x][y]=grid[row][x]+res;
                else dp[index][x][y]=grid[row][x]+grid[row][y]+res;
            }
        }
        index=1-index;
    }
    index=1-index;
    int res=0;
    for(int i=0;i<c;i++){
        for(int j=0;j<c;j++){
            res=max(res,dp[index][i][j]);
        }
    }
    return res;
}