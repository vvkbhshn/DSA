//problem link: https://www.interviewbit.com/problems/capture-regions-on-board/

void dfs(int x, int y, vector<vector<char>> &A){
    if(x<0 || x>=A.size() || y<0 || y>=A[0].size() || A[x][y]!='O') return;
    A[x][y]='Y';    
    dfs(x+1,y,A);
    dfs(x-1,y,A);
    dfs(x,y-1,A);
    dfs(x,y+1,A);
}

void Solution::solve(vector<vector<char>> &A) {
    int n=A.size(), m=A[0].size();
    for(int j=0;j<m;j++){
        dfs(0,j,A);
        dfs(n-1,j,A);
    }
    for(int i=1;i<n-1;i++){
        dfs(i,0,A);
        dfs(i,m-1,A);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O') A[i][j]='X';
            else if(A[i][j]=='Y') A[i][j]='O';
        }
    }
}
